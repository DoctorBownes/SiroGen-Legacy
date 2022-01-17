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
	void AddtoScene(Entity* entity);
	void RemovefromScene(Entity* entity);
	void DeleteEntity(Entity* entity);
	std::vector<Entity*> GetEntities() { return _children; };
	Camera* GetMainCamera() { return MainCamera; };

private:
	Camera* MainCamera = new Camera(false);
	std::vector<Entity*> _children;
};

