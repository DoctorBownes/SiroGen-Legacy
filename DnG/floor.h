#ifndef FLOOR_H_
#define FLOOR_H_
#include <SiroGen/scene.h>
#include "player.h"

class Floor :
	public Scene
{
public:
	Floor();
	virtual void update(float deltaTime);
	std::vector<Entity*> map;
	Player* joey = nullptr;
};

#endif
