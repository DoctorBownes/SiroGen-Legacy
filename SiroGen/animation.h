#pragma once
#include <SiroGen/spriteanimation.h>
class Animation : public Component
{
public:
	Animation();
	~Animation();
	SpriteAnimation SoloAnimation;

	std::vector<SpriteAnimation*> AnimationQueue;

	float starttime = 0.0f;

	void PlayAnimation(SpriteAnimation* spriteanimation, bool loop = true);
	void StopAnimation();
	bool isAnimationPlaying() { return isPlaying; };
	bool isAnimationFinished() { return isFinished; };
	bool isFinished = 0;
private:
	bool isPlaying = 0;
};