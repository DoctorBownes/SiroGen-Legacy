#pragma once
#include <SiroGen/entity.h>

class Gangster : public Entity
{
public:
	Gangster();
	void SetColor(uint8_t color);
	virtual void update(float deltaTime);
private:
	SpriteAnimation* blinkAnim;
	SpriteAnimation* drawAnim;
};