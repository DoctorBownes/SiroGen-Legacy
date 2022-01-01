#include "animation.h"

Animation::Animation()
{
	starttime = glfwGetTime();
}

Animation::~Animation()
{

}

void Animation::PlayAnimation(SpriteAnimation spriteanimation, bool loop)
{
	if (!isAnimationFinished() && !isPlaying)
	{
		SoloAnimation = spriteanimation;
		isLooping = loop;
		SoloAnimation.it = SoloAnimation.AniArray.begin();
		isPlaying = true;
	}
}

void Animation::StopAnimation()
{
	isPlaying = false;
}