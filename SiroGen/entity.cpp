#include <SiroGen/entity.h>

Entity::Entity()
{
	transform = new Transform;
}

void Entity::update()
{

}

void Entity::Addchild(Entity* entity)
{
	_children.push_back(entity);
}

void Entity::Removechild(Entity* entity)
{
	if (std::find(_children.begin(), _children.end(), entity) != _children.end())
	{
		_children.erase(std::find(_children.begin(), _children.end(), entity));
	}
}

Entity::~Entity()
{
	delete transform;
}