#include "update.h"

extern float deltaTime;

Update::Update(Entity* owner)
{
	_Owner = owner;
}

void Update::DoIt(unsigned int _shader)
{
	_Owner->update(deltaTime);
}
