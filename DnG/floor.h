#ifndef FLOOR_H_
#define FLOOR_H_

#include <SiroGen/scene.h>
#include <SiroGen/hashmap.h>
#include "ground.h"
#include "wall.h"
#include "player.h"

class Floor :
	public Scene
{
public:
	Floor();
	virtual void update(float deltaTime);
	//Tile* TileLevel[LevelHeight][LevelWidth] = nullptr;
	//HashMap* EnemyMap = nullptr;
	Player* player = nullptr;
};

#endif
