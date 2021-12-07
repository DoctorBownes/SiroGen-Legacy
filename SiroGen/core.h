#pragma once
#include <glm/glm.hpp>

#include <SiroGen/scene.h>
#include <SiroGen/renderer.h>

class Core
{
public:
	double deltaTime;
	Core();
	void Start(Scene* scene);
private:
	Renderer sceneRenderer;
	void CalculateDeltaTime();
};
