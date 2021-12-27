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
	SoloAnimation = spriteanimation;
	isLooping = loop;
	isPlaying = true;
}

void Animation::StopAnimation()
{
	isPlaying = false;
}