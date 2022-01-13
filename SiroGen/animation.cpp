#include "animation.h"

Animation::Animation()
{
	starttime = glfwGetTime();
}

Animation::~Animation()
{

}

void Animation::PlayAnimation(SpriteAnimation* spriteanimation, bool loop)
{
	if (std::find(AnimationQueue.begin(), AnimationQueue.end(), std::make_pair(spriteanimation, loop)) == AnimationQueue.end())
	{
		AnimationQueue.push_back(std::make_pair(spriteanimation, loop));
		std::cout << "Animation Pushed" << std::endl;
		std::cout << AnimationQueue.size() << std::endl;
	}
}

void Animation::RemoveAnimation()
{
	AnimationQueue.erase(AnimationQueue.begin());
}

void Animation::DoIt(unsigned int _shader)
{
    if (AnimationQueue.size() >= 1)
    {
        std::vector<std::pair<Sprite*, float> > tempvector = AnimationQueue.begin()->first->GetArray();
        Component* tempsprite = tempvector.at(pos).first;
        isFinished = false;
        tempsprite->DoIt(_shader);
        if (glfwGetTime() - starttime >= tempvector.at(pos).second)
        {
            pos++;
            if (pos == tempvector.size())
            {
                isFinished = true;
                pos = 0;
                if (!AnimationQueue.begin()->second)
                {
                    RemoveAnimation();
                }
            }
            starttime = glfwGetTime();
        }
    }
}