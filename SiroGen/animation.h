#pragma once
#include <map>
#include <SiroGen/spriteanimation.h>
class Animation : public Component
{
public:
	Animation();
	~Animation();

	void PlayAnimation(SpriteAnimation* spriteanimation, bool loop = true);
	void RemoveAnimation();
	bool isAnimationFinished() { return isFinished; };
private:
	virtual void DoIt(unsigned int _shader);
	bool isFinished = 0;
	int pos = 0;
	float starttime = 0.0f;
	std::vector<std::pair<SpriteAnimation*, bool> > AnimationQueue;
	//bool isPlaying = 0;
};