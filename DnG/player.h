#ifndef PLAYER_H_
#define PLAYER_H_
#include <SiroGen/entity.h>

class Player : public Entity
{
public:
	Player();
	virtual void update(float deltaTime);
	Vector3 oldpos;
	Vector3 olderpos;
	Vector3 velocity;
	float accel = 1.0f;
	bool grounded = false;
	bool jumping = false;
private:
	SpriteAnimation* walkAnim = nullptr;
};

#endif
