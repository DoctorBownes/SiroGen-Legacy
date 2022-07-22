#ifndef PLAYER_H_
#define PLAYER_H_
#include <SiroGen/entity.h>

class Player : public Entity
{
public:
	Player();
	virtual void update(float deltaTime);
	Vector3* oldpos = new Vector3();
	float speed = 0.0f;
private:
	SpriteAnimation* walkAnim = nullptr;
};

#endif
