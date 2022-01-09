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
	if (!isPlaying)
	{
		isPlaying = true;
	}
}

void Animation::StopAnimation()
{
	AnimationQueue.erase(AnimationQueue.begin());
	isPlaying = false;
}