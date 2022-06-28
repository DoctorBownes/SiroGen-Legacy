#ifndef PLAYER_H_
#define PLAYER_H_
#include <SiroGen/entity.h>

class Player : public Entity
{
public:
	Player();
	virtual void update(float deltaTime);
private:
	SpriteAnimation* walkAnim = nullptr;
	SpriteAnimation* smokeAnim = nullptr;
	SpriteAnimation* deathAnim = nullptr;
	float speed = 0.0f;
};

#endif
