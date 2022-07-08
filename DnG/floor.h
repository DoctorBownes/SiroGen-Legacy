#ifndef FLOOR_H_
#define FLOOR_H_
#include <SiroGen/scene.h>
#include "tile.h"
#include "ground.h"
#include "wall.h"
#include "player.h"

class Floor :
	public Scene
{
public:
	Floor();
	virtual void update(float deltaTime);
	Player* player = nullptr;
};

#endif
