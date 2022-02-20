#include "animation.h"

Animation::Animation()
{
    _Owner = nullptr;
    starttime = glfwGetTime();
}

Animation::Animation(Entity* owner)
{
    _Owner = owner;
    starttime = glfwGetTime();
}

Animation::~Animation()
{
    //std::vector<std::pair<SpriteAnimation*, bool>>::iterator it;
    //for (it = AnimationQueue.begin(); it != AnimationQueue.end(); it++)
    //{
    //    std::cout << "Deleting Animation Component" << std::endl;
    //    delete it->first;
    //}
    AnimationQueue.clear();
}

void Animation::PlayAnimation(SpriteAnimation* spriteanimation, bool loop)
{
    PlayAnimation(spriteanimation, loop, 0, spriteanimation->GetArray().size() - 1);
}

void Animation::PlayAnimation(SpriteAnimation* spriteanimation, bool loop, int startframe, int endframe)
{
    if ((startframe != spriteanimation->startframe || endframe != spriteanimation->endframe) && !loop)
    {
        if (AnimationQueue.size() > 0)
        {
            AnimationQueue.erase(AnimationQueue.begin());
            starttime = glfwGetTime();
        }
    }
    if (std::find(AnimationQueue.begin(), AnimationQueue.end(), std::make_pair(spriteanimation, loop)) == AnimationQueue.end())
    {
        spriteanimation->startframe = startframe;
        spriteanimation->frame = spriteanimation->startframe;
        spriteanimation->endframe = endframe;
        AnimationQueue.insert(AnimationQueue.begin(), std::make_pair(spriteanimation, loop));
    }
}

void Animation::RemoveAnimation()
{
    if (!AnimationQueue.empty())
    {
        //delete AnimationQueue.begin()->first;
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
    if (!AnimationQueue.empty() && !AnimationQueue.begin()->first->GetArray().empty())
    {
        std::vector<std::pair<Sprite*, float> > tempvector = AnimationQueue.begin()->first->GetArray();
        Component* tempsprite = tempvector.at(AnimationQueue.begin()->first->frame).first;
        isFinished = false;
        tempsprite->DoIt(_shader);
        if (AnimationQueue.begin()->first->startframe != AnimationQueue.begin()->first->endframe)
        {
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
}