#include <SiroGen/entity.h>
#include <algorithm>

Entity::Entity()
{
	transform = new Transform();
	AddComponent<Update>();
}

void Entity::update(float deltaTime)
{
}

void Entity::Addchild(Entity* entity)
{
	if (entity->worldtransform == nullptr)
	{
		AddChildren(entity);
	}
	_children.push_back(entity);
	entity->Parent = this;
}

void Entity::Removechild(Entity* entity)
{
	entity->Parent = nullptr;
	RemoveChildren(entity);
	if (std::find(_children.begin(), _children.end(), entity) != _children.end())
	{
		_children.erase(std::find(_children.begin(), _children.end(), entity));
	}
}

void Entity::DeleteChild(Entity* entity)
{
	//if (entity->Parent != nullptr)
	//{
		Removechild(entity);
		DeleteChildren(entity);
		delete entity;
	//}
	//else
	//{
	//	std::cout << "Warning: child entity was not found" << std::endl;
	//}
}

Entity::~Entity()
{
	std::cout << "Deleting Entity" << std::endl;
	delete transform;
	delete worldtransform;
	std::map<size_t, Component*>::iterator it;
	for (it = componentlist.begin(); it != componentlist.end(); it++)
	{
		std::cout << "Deleting Component" << std::endl;
		delete it->second;
	}
	componentlist.clear();
}

void Entity::AddChildren(Entity* entity)
{
	entity->worldtransform = new Transform();
	for (int i = 0; i < entity->_children.size(); i++)
	{
		AddChildren(entity->_children[i]);
	}
}

void Entity::RemoveChildren(Entity* entity)
{
	for (int i = 0; i < entity->_children.size(); i++)
	{
		RemoveChildren(entity->_children[i]);
	}
	delete entity->worldtransform;
	entity->worldtransform = nullptr;
}

void Entity::DeleteChildren(Entity* entity)
{
	for (int i = 0; i < entity->_children.size(); i++)
	{
		DeleteChild(entity->_children[i]);
	}
}