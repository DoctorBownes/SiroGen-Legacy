#pragma once
#include <SiroGen/scene.h>
#include "player.h"
#include "gangster.h"

class Wackem :
	public Scene
{
public:
	Wackem();
	virtual void update(float deltaTime);
	std::vector<Gangster*> mob;
	Player* joey;
};

