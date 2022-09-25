#include "component.h"
#include <SiroGen/entity.h>

Component::Component(Entity* owner)
{
	_Owner = owner;
}

Component::~Component()
{
}