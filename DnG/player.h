#ifndef PLAYER_H_
#define PLAYER_H_
#include <SiroGen/entity.h>

class Player : public Entity
{
public:
	Player();
	virtual void update(float deltaTime);
	Vector2 oldpos;
	Vector2 olderpos;
	Vector2 velocity;
	float accel = 1.0f;
	bool grounded = false;
private:
	SpriteAnimation* walkAnim = nullptr;
};

#endif
