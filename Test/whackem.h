#ifndef WHACKEM_H_
#define WHACKEM_H_
#include <SiroGen/scene.h>
#include "player.h"
#include "gangster.h"

class Whackem :
	public Scene
{
public:
	Whackem();
	virtual void update(float deltaTime);
	std::vector<Entity*> map;
	Gangster* don = nullptr;
	Player* joey = nullptr;
	Gangster* dontoo = nullptr;
	Gangster* donthree = nullptr;
};

#endif
