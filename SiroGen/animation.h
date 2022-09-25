#ifndef ANIMATION_H_
#define ANIMATION_H_
#include <map>
#include <SiroGen/spriteanimation.h>
#include <algorithm>
class Animation : public Component
{
public:
	Animation(Entity* owner = nullptr);
	~Animation();

	void PlayAnimation(SpriteAnimation* spriteanimation, bool loop = true);
	void PlayAnimation(SpriteAnimation* spriteanimation, bool loop, int startframe, int endframe);
	void RemoveAnimation();
	void PauseAnimation(int atframe = 0);
	void ResumeAnimation(int atframe = 0);
	bool isAnimationFinished(SpriteAnimation* spriteanimation = nullptr);
	int frame = 0;
private:
	SpriteAnimation* CentralAnimation = nullptr;
	bool isLoop = false;
	virtual void DoIt(unsigned int _shader);
	bool isFinished = false;
	bool paused = 0;
	double starttime = 0.0;
	//bool isPlaying = 0;
};

#endif
