#pragma once

#include <vector>
#include <SiroGen/entity.h>
#include <SiroGen/camera.h>
#include <SiroGen/input.h>

class Scene
{
public:
	Scene();
	~Scene();

	virtual void update(float deltaTime) = 0;
	void AddtoScene(Entity* entity);
	void RemovefromScene(Entity* entity);
	void DeleteEntity(Entity* entity);
	void AddTexttoScene(const char* text, int x, int y, int size, const char* TGAfont = "assets/LucidaConsole.tga");
	std::vector<Entity*> GetEntities() { return _children; };
	std::vector<Text*> GetTexts() { return scenetexts; };
	Camera* GetMainCamera() { return MainCamera; };
	Input* GetInput() { return _input; };
private:
	Input* _input = new Input();
	Camera* MainCamera = new Camera(false);
	std::vector<Text*> scenetexts;
	std::vector<Entity*> _children;
};

