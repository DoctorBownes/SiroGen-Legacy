#include "component.h"
#include <SiroGen/entity.h>

Component::Component()
{
	_Owner = nullptr;
}

Component::Component(Entity* owner)
{
	_Owner = owner;
}