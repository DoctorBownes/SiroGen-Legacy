#pragma once
#include <SiroGen/spriteanimation.h>
class Animation : public Component
{
public:
	Animation();
	~Animation();

	std::vector<std::pair<SpriteAnimation*, bool>> AnimationQueue;

	float starttime = 0.0f;

	void PlayAnimation(SpriteAnimation* spriteanimation, bool loop = true);
	void StopAnimation();
	bool isAnimationPlaying() { return isPlaying; };
	bool isAnimationFinished() { return isFinished; };
	bool isFinished = 0;
	int pos = 0;
private:
	bool isPlaying = 0;
};