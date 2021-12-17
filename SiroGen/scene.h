#pragma once

#include <vector>
#include <SiroGen/entity.h>
#include <SiroGen/camera.h>

class Scene
{
public:
	Scene();
	~Scene();

	virtual void update(float deltaTime) = 0;
	void Addchild(Entity* entity);
	std::vector<Entity*> Getchildren() { return _children; };
	Camera* GetMainCamera() { return MainCamera; };

private:
	Camera* MainCamera = new Camera(true);
	std::vector<Entity*> _children;
};

