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
    if (0 != spriteanimation->startframe || spriteanimation->GetArray().size() - 1 != spriteanimation->endframe && !loop)
    {
        if (AnimationQueue.size() > 0)
        {
            AnimationQueue.erase(AnimationQueue.end());
        }
    }
	if (std::find(AnimationQueue.begin(), AnimationQueue.end(), std::make_pair(spriteanimation, loop)) == AnimationQueue.end())
	{
        spriteanimation->startframe = 0;
        spriteanimation->frame = spriteanimation->startframe;
        spriteanimation->endframe = spriteanimation->GetArray().size() -1;
		AnimationQueue.insert(AnimationQueue.begin(),std::make_pair(spriteanimation, loop));
	}
}

void Animation::PlayAnimation(SpriteAnimation* spriteanimation, bool loop, int startframe, int endframe)
{
    if (startframe != spriteanimation->startframe || endframe != spriteanimation->endframe && !loop)
    {
        if (AnimationQueue.size() > 0)
        {
            AnimationQueue.erase(AnimationQueue.begin());
            std::cout << "Erased" << std::endl;
        }
    }
    if (std::find(AnimationQueue.begin(), AnimationQueue.end(), std::make_pair(spriteanimation, loop)) == AnimationQueue.end())
    {
        spriteanimation->startframe = startframe;
        spriteanimation->frame = spriteanimation->startframe;
        spriteanimation->endframe = endframe;
        AnimationQueue.insert(AnimationQueue.begin(), std::make_pair(spriteanimation, loop));
        std::cout << "Inserted" << std::endl;
    }
}

void Animation::RemoveAnimation()
{
    if (AnimationQueue.size() > 0)
    {
        AnimationQueue.erase(AnimationQueue.begin());
    }
}

void Animation::PauseAnimation(int atframe)
{
    AnimationQueue.begin()->first->frame = atframe;
    paused = true;
}

void Animation::ResumeAnimation(int atframe)
{
    if (paused)
    {
        starttime = glfwGetTime();
        AnimationQueue.begin()->first->frame = atframe;
        paused = false;
    }
}

void Animation::DoIt(unsigned int _shader)
{
    if (AnimationQueue.size() > 0 && AnimationQueue.begin()->first->GetArray().size() > 0)
    {
        std::vector<std::pair<Sprite*, float> > tempvector = AnimationQueue.begin()->first->GetArray();
        Component* tempsprite = tempvector.at(AnimationQueue.begin()->first->frame).first;
        isFinished = false;
        tempsprite->DoIt(_shader);
        if (glfwGetTime() - starttime >= tempvector.at(AnimationQueue.begin()->first->frame).second && !paused)
        {
            AnimationQueue.begin()->first->frame++;
            if (AnimationQueue.begin()->first->frame == AnimationQueue.begin()->first->endframe + 1)
            {
                isFinished = true;
                AnimationQueue.begin()->first->frame = AnimationQueue.begin()->first->startframe;
                if (!AnimationQueue.begin()->second)
                {
                    RemoveAnimation();
                }
            }
            starttime = glfwGetTime();
        }
    }
}