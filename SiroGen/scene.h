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
	void updateEntities(Entity* entity, float deltaTime);
	void InputInit(Entity* entity, GLFWwindow* window);

	void AddtoScene(Entity* entity);
	void RemovefromScene(Entity* entity);
	void DeleteEntity(Entity* entity);
	void AddSceneText(std::string, float x, float y, float size, uint8_t Color = 0xf, const char* TGAfont = "");
	void RemoveSceneText(int pos = 0);
	void SceneTextClear();
	std::vector<Entity*> GetEntities() { return _children; };
	std::vector<Text> GetTexts() { return scenetexts; };
	Camera* GetMainCamera() { return MainCamera; };
	Input* GetInput() { return _input; };
private:
	Input* _input = new Input();
	Camera* MainCamera = new Camera(false);
	std::vector<Text> scenetexts;
	std::vector<Entity*> _children;
};

