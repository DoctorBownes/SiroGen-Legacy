#include <SiroGen/entity.h>
#include <algorithm>

Entity::Entity()
{
}

void Entity::update(float deltaTime)
{
}

void Entity::Addchild(Entity* entity)
{
	entity->Parent = this;
	//AddChildren(entity);
	_children.push_back(entity);
}

void Entity::Removechild(Entity* entity)
{
	entity->Parent = nullptr;
	//RemoveChildren(entity);
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
	std::map<size_t, Component*>::iterator it;
	for (it = componentlist.begin(); it != componentlist.end(); it++)
	{
		std::cout << "Deleting Component" << std::endl;
		delete it->second;
	}
	componentlist.clear();
}

//void Entity::AddChildren(Entity* entity)
//{
//	for (int i = 0; i < entity->_children.size(); i++)
//	{
//		Addchild(entity->_children[i]);
//	}
//}

//void Entity::RemoveChildren(Entity* entity)
//{
//	for (int i = 0; i < entity->_children.size(); i++)
//	{
//		Removechild(entity->_children[i]);
//	}
//}

void Entity::DeleteChildren(Entity* entity)
{
	for (int i = 0; i < entity->_children.size(); i++)
	{
		DeleteChild(entity->_children[i]);
	}
}