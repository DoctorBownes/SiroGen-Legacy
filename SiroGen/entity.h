#pragma once
#include <map>
#include <iostream>

#include <SiroGen/transform.h>
#include <SiroGen/component.h>
#include <SiroGen/sprite.h>
#include <SiroGen/model.h>
#include <SiroGen/pixelsprite.h>

class Entity
{
public:
	Entity();
	~Entity();

	template <typename T>
	T* AddComponent();

	template <typename T>
	T* GetComponent();

	void update();
	Transform* transform;
private:
	std::map<size_t, Component> componentlist;
};

template <typename T>
T* Entity::AddComponent()
{
	if (!componentlist.count(typeid(T).hash_code()))
	{
		T test{};
		componentlist.emplace(typeid(T).hash_code(), test);
		return static_cast<T*>(&componentlist[typeid(T).hash_code()]);
	}
	std::cout << "Error: cannot add two of the same component" << std::endl;
	return nullptr;
}

template <typename T>
T* Entity::GetComponent()
{
	if (componentlist.count(typeid(T).hash_code()))
	{
		return static_cast<T*>(&componentlist[typeid(T).hash_code()]);
	}
	return nullptr;
}

