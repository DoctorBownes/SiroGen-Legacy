#pragma once
#include <SiroGen/scene.h>
#include "player.h"
#include "gangster.h"

class Whackem :
	public Scene
{
public:
	Whackem();
	virtual void update(float deltaTime);
	std::vector<Gangster*> mob;
	Gangster* don = nullptr;
	Player* joey = nullptr;
};

