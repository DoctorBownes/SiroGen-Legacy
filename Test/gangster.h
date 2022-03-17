#ifndef GANGSTER_H_
#define GANGSTER_H_
#include <SiroGen/entity.h>

class Gangster : public Entity
{
public:
	Gangster();
	~Gangster();
	void SetColor(uint8_t color);
	virtual void update(float deltaTime);
	SpriteAnimation* blinkAnim;
	SpriteAnimation* drawAnim;
	Entity* target = nullptr;
private:
	std::vector<Entity*> bullets;
	SpriteAnimation* bulletAnim;
	bool bulletspawned = false;
};

#endif
