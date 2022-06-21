#ifndef SCENE_H_
#define SCENE_H_
#include <SiroGen/entity.h>
#include <SiroGen/camera.h>

class Scene : public Entity
{
public:
	Scene();
	~Scene();

	void InputInit(Entity* entity, GLFWwindow* window);
	void AddSceneText(std::string text, float x, float y, float size, uint8_t Color = 0xf, const char* TGAfont = "");
	void RemoveSceneText(int pos = 0);
	void EditSceneText(std::string text, int pos = 0);
	void ClearSceneText();

	bool isRunning = true;

	uint8_t bkgdcolor = 0;

	std::vector<Text*> GetTexts() { return scenetexts; };
	Camera* GetMainCamera() { return MainCamera; };
private:
	Camera* MainCamera = new Camera(false);
	std::vector<Text*> scenetexts = std::vector<Text*>();
};

#endif
