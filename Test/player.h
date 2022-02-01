#pragma once
#include <SiroGen/entity.h>
#include "testnity.h"

class Player : public Entity
{
public:
	Player();
	virtual void update(float deltaTime);
};

