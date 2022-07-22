#ifndef PLAYER_H_
#define PLAYER_H_
#include <SiroGen/entity.h>

class Player : public Entity
{
public:
	Player();
	~Player();
	void SetColor(uint8_t color);
	virtual void update(float deltaTime);
	SpriteAnimation* walkAnim;
	SpriteAnimation* drawAnim;
	Entity* target = nullptr;
	Entity* bullet = nullptr;
	int score = 3;
	short direction = 1;
	void Shoot();
private:
	SpriteAnimation* bulletAnim;
	bool bulletspawned = false;
	bool haspressed = false;
};

#endif
