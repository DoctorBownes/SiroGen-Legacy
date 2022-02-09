#include <SiroGen/entity.h>

Entity::Entity()
{
	transform = new Transform;
	worldtransform = new Transform;
}

void Entity::update(float deltaTime)
{

}

void Entity::Addchild(Entity* entity)
{
	_children.push_back(entity);
	entity->Parent = this;
}

void Entity::Removechild(Entity* entity)
{
	if (std::find(_children.begin(), _children.end(), entity) != _children.end())
	{
		_children.erase(std::find(_children.begin(), _children.end(), entity));
	}
}

void Entity::DeleteChild(Entity* entity)
{
	if (entity->Parent != nullptr)
	{
		if (std::find(entity->Parent->_children.begin(), entity->Parent->_children.end(), entity) != entity->Parent->_children.end())
		{
			entity->Parent->_children.erase(std::find(entity->Parent->_children.begin(), entity->Parent->_children.end(), entity));
			DeleteChildren(entity);
			delete entity;
		}
	}
	else
	{
		std::cout << "Warning: child entity was not found" << std::endl;
	}
}

Entity::~Entity()
{
	std::cout << "Deleting" << std::endl;
	delete transform;
	delete worldtransform;
	delete input;
	std::map< size_t, Component*>::iterator it;
	for (it = componentlist.begin(); it != componentlist.end(); it++)
	{
		delete it->second;
	}
	componentlist.clear();
}

void Entity::DeleteChildren(Entity* entity)
{
	DeleteChild(entity);
	for (int i = 0; i < entity->_children.size(); i++)
	{
		DeleteChildren(entity->_children[i]);
	}
}