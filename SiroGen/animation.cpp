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
}

void Animation::PlayAnimation(SpriteAnimation* spriteanimation, bool loop)
{
    PlayAnimation(spriteanimation, loop, 0, spriteanimation->GetArray().size() - 1);
}

void Animation::PlayAnimation(SpriteAnimation* spriteanimation, bool loop, int startframe, int endframe)
{
    if (spriteanimation->hasPriority && CentralAnimation)
    {
        CentralAnimation->hasPriority = false;
        if (CentralAnimation != spriteanimation)
        {
            RemoveAnimation();
           // std::cout << "REMOVED" << std::endl;
        }
    }
    if (!CentralAnimation/* && CentralAnimation != spriteanimation*/)
    {
        spriteanimation->startframe = startframe;
        spriteanimation->endframe = endframe;
        frame = spriteanimation->startframe;
        CentralAnimation = spriteanimation;
        CentralAnimation->isFinished = false;
        isLoop = loop;
      //  std::cout << "INSERTED" << std::endl;
    }
    else if (startframe != spriteanimation->startframe || endframe != spriteanimation->endframe)
    {
        spriteanimation->startframe = startframe;
        spriteanimation->endframe = endframe;
        frame = spriteanimation->startframe;
        starttime = glfwGetTime();
    }
}

void Animation::RemoveAnimation()
{
    CentralAnimation = nullptr;
    isLoop = false;
}

bool Animation::isAnimationFinished(SpriteAnimation* spriteanimation)
{
    if (spriteanimation == nullptr)
    {
        return CentralAnimation->isFinished;
    }
        return spriteanimation->isFinished;
}

void Animation::PauseAnimation(int atframe)
{
    frame = atframe;
    paused = true;
}

void Animation::ResumeAnimation(int atframe)
{
        starttime = glfwGetTime();
        frame = atframe;
        paused = false;
}

void Animation::DoIt(unsigned int _shader)
{
    //std::cout << "AnimationQueue.Size() = " << AnimationQueue.size() << std::endl;
    if (CentralAnimation && !CentralAnimation->GetArray().empty())
    {
        std::vector<std::pair<Sprite*, float> > tempvector = CentralAnimation->GetArray();
        Component* tempsprite = tempvector.at(frame).first;
        CentralAnimation->isFinished = false;
        tempsprite->DoIt(_shader);
        if (CentralAnimation->startframe != CentralAnimation->endframe)
        {
            if (glfwGetTime() - starttime >= tempvector.at(frame).second && !paused)
            {
                frame++;
                if (frame == CentralAnimation->endframe + 1)
                {
                    CentralAnimation->isFinished = true;
                    frame = CentralAnimation->startframe;
                    if (!isLoop)
                    {
                        RemoveAnimation();
                    }
                }
                starttime = glfwGetTime();
            }
        }
    }
}