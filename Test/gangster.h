#pragma once
#include <SiroGen/entity.h>

class Gangster : public Entity
{
public:
	Gangster();
	virtual void update(float deltaTime);
private:
	SpriteAnimation* blinkAnim;
};