#pragma once
#include <SiroGen/spriteanimation.h>
class Animation : public Component
{
public:
	Animation();
	~Animation();
	SpriteAnimation SoloAnimation;

	float starttime = 0.0f;

	bool isPlaying = 0;
	bool isLooping = 1;
	
	void PlayAnimation(SpriteAnimation spriteanimation, bool loop = true);

};

