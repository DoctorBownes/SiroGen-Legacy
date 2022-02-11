#ifndef ENTITY_H_
#define ENTITY_H_
#include <iostream>

#include <SiroGen/transform.h>
//#include <SiroGen/component.h>
#include <SiroGen/sprite.h>
#include <SiroGen/animation.h>
#include <SiroGen/text.h>
#include <SiroGen/collider.h>
#include <SiroGen/input.h>

class Entity
{
public:
	Entity();
	~Entity();

	void Addchild(Entity* entity);
	void Removechild(Entity* entity);
	void DeleteChild(Entity* entity);
	void DeleteChildren(Entity* entity);
	std::vector<Entity*> Getchildren() { return _children; };

	template <typename T>
	T* AddComponent();

	template <typename T>
	T* GetComponent();

	template <typename T>
	void RemoveComponent();

	virtual void update(float deltaTime);
	std::map<size_t, Component*> GetComponentList() { return componentlist; };

	Transform* transform;
	Transform* worldtransform;
	Input* GetInput() { return input; };

private:
	Entity* Parent = nullptr;
	Input* input = new Input();
	std::vector<Entity*> _children;
	std::map<size_t, Component*> componentlist;
};

template <typename T>
T* Entity::AddComponent()
{
	if (componentlist.find(typeid(T).hash_code()) == componentlist.end())
	{
		T* test = new T(this);
		componentlist.emplace(typeid(T).hash_code(), test);
		return static_cast<T*>(componentlist[typeid(T).hash_code()]);
	}
	std::cout << "Error: cannot add two of the same component" << std::endl;
	return nullptr;
}

template <typename T>
T* Entity::GetComponent()
{
	if (componentlist.find(typeid(T).hash_code()) != componentlist.end())
	{
		return static_cast<T*>(componentlist[typeid(T).hash_code()]);
	}
	std::cout << "Error: component not found" << std::endl;
	return nullptr;
}

template <typename T>
void Entity::RemoveComponent()
{
	if (componentlist.count(typeid(T).hash_code()))
	{
		delete componentlist.find(typeid(T).hash_code())->second;
		componentlist.erase(componentlist.find(typeid(T).hash_code()));
	}
	else
	{
		std::cout << "Warning: component set to remove was not found" << std::endl;
	}
}
#endif