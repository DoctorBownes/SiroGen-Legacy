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
	}
}

void Animation::RemoveAnimation()
{
	AnimationQueue.erase(AnimationQueue.begin());
}

void Animation::PauseAnimation(int atframe)
{
    frame = atframe;
    paused = true;
}

void Animation::ResumeAnimation(int atframe)
{
    if (paused)
    {
        starttime = glfwGetTime();
        frame = atframe;
        paused = false;
    }
}

void Animation::DoIt(unsigned int _shader)
{
    if (AnimationQueue.begin()->first->GetArray().size() >= 1)
    {
        std::vector<std::pair<Sprite*, float> > tempvector = AnimationQueue.begin()->first->GetArray();
        Component* tempsprite = tempvector.at(frame).first;
        isFinished = false;
        tempsprite->DoIt(_shader);
        if (glfwGetTime() - starttime >= tempvector.at(frame).second && !paused)
        {
            frame++;
            if (frame == tempvector.size())
            {
                isFinished = true;
                frame = 0;
                if (!AnimationQueue.begin()->second)
                {
                    RemoveAnimation();
                }
            }
            starttime = glfwGetTime();
        }
    }
}