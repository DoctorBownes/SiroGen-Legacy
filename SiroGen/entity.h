//To make sure we only open this file once
#ifndef ENTITY_H_
#define ENTITY_H_

//We include all of the available Components, the transform for its position/rotation/scale 
//and the input class to give it keyboard support
#include <SiroGen/transform.h>
#include <SiroGen/sprite.h>
#include <SiroGen/animation.h>
#include <SiroGen/text.h>
#include <SiroGen/collider.h>
#include <SiroGen/input.h>
#include <iostream>

class Entity
{
public:
	Entity();
	virtual ~Entity();

	//All entities have child support. That includes the scene itself. 
	//Only real difference is the scene holds a camera and does not have a parent
	void Addchild(Entity* entity);

	void Addchildfront(Entity* entity);

	//Removes child from scene or other entity
	void Removechild(Entity* entity);

	//Removes child from scene or other entity and deletes it completely including its Components
	void DeleteChild(Entity* entity);
	void DeleteChildren(Entity* entity);
	std::vector<Entity*> Getchildren() { return _children; };

	//Like in Unity you can add a component via Templates
	//This way you can easily add the component without having to create one on an extra line
	template <typename T>
	T* AddComponent();

	template <typename T>
	T* GetComponent();

	template <typename T>
	void RemoveComponent();

	//bool shouldUpdate = true;

	//The update function goes through a while loop (along with the renderer, deltaTime and the Camera)
	//this is the main function used to implement gameplay elements
	virtual void update(float deltaTime);

	std::map<size_t, Component*> GetComponentList() { return componentlist; };

	//The transform and worldtransform hold the position, rotation and scale of the entity.
	//The worldposition is the entity's absolute position. Regardless of it being a child of another entity
	//this is mainly used for Collision checking.
	Transform transform;
	Transform worldtransform;

	//Used to call the input class for keyboard related commands
	//e.g. KeyDown(KeyCode key) MousePressed(MouseButton button)
	Input* GetInput() { return _instance; };
	Entity* Parent = nullptr;

protected:
	std::vector<Entity*> _children;

	//The componentlist is made out of the component's Hashcode for the key and the component itself as value
	std::map<size_t, Component*> componentlist;

private:
	//void RemoveChildren(Entity* entity);
	//void AddChildren(Entity* entity);
	//The Input class is a singleton class so it has to be called via instance
	Input* _instance = _instance->GetInstance();
};

template <typename T>
T* Entity::AddComponent()
{
	//First checks if it can NOT find the component
	if (componentlist.find(typeid(T).hash_code()) == componentlist.end())
	{
		//Creates the given Component
		T* test = new T(this);
		//Places it in the map
		//Because the map's value is a Component you cannot add a random class
		componentlist.emplace(typeid(T).hash_code(), test);
		//Because all Components are based of of the Component class we use the dynamic_cast
		//this is also a safety measure to ensure a Component type is added
		return dynamic_cast<T*>(componentlist[typeid(T).hash_code()]);
	}
	std::cout << "Error: cannot add two of the same component" << std::endl;
	return nullptr;
}

template <typename T>
T* Entity::GetComponent()
{
	//To boost performance, the code asks rightaway for the given Component without searching.
	//If this does not make sense to the program it will return a nullptr
	if (componentlist[typeid(T).hash_code()])
	{
		return dynamic_cast<T*>(componentlist[typeid(T).hash_code()]);
	}
	std::cout << "Error: component not found" << std::endl;
	return nullptr;
}

template <typename T>
void Entity::RemoveComponent()
{
	//Same as the GetComponent function. Only real difference is it deletes the Component
	//and does not return a nullptr if the Component is not "found"
	if (componentlist[typeid(T).hash_code()])
	{
		delete componentlist[typeid(T).hash_code()];
		componentlist.erase(componentlist.find(typeid(T).hash_code()));
	}
	else
	{
		std::cout << "Warning: component set to remove was not found" << std::endl;
	}
}

#endif
