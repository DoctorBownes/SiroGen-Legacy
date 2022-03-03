#pragma once
#include <SiroGen/entity.h>

class Player : public Entity
{
public:
	Player();
	virtual void update(float deltaTime);
private:
	SpriteAnimation* walkAnim;
	SpriteAnimation* smokeAnim;
	float speed = 0.0f;
};

