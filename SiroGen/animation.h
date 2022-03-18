#ifndef ANIMATION_H_
#define ANIMATION_H_
#include <map>
#include <SiroGen/spriteanimation.h>
#include <algorithm>
class Animation : public Component
{
public:
	Animation();
	Animation(Entity* owner);
	~Animation();

	void PlayAnimation(SpriteAnimation* spriteanimation, bool loop = true);
	void PlayAnimation(SpriteAnimation* spriteanimation, bool loop, int startframe, int endframe);
	void RemoveAnimation();
	void PauseAnimation(int atframe = 0);
	void ResumeAnimation(int atframe = 0);
	bool isAnimationFinished() { return isFinished; };
	SpriteAnimation* GetSpriteAnimation(int pos) { return AnimationQueue[pos].first; };
	int frame = 0;
private:
	virtual void DoIt(unsigned int _shader);
	bool isFinished = 0;
	bool paused = 0;
	double starttime = 0.0;
	std::vector<std::pair<SpriteAnimation*, bool> > AnimationQueue;
	//bool isPlaying = 0;
};

#endif
