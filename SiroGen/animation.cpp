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
        Component* tempsprite = AnimationQueue.begin()->first->AniArray.at(pos).first;
        isFinished = false;
        tempsprite->DoIt(_shader);
        if (glfwGetTime() - starttime >= AnimationQueue.begin()->first->AniArray.at(pos).second)
        {
            pos++;
            if (pos == AnimationQueue.begin()->first->AniArray.size())
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