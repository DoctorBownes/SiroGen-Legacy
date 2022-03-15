#pragma once
#include <glm/glm.hpp>

#include <SiroGen/scene.h>
#include <SiroGen/renderer.h>

class Core
{
public:
	double deltaTime = 0.0;
	Core();
	void Start(Scene* scene);
private:
	Renderer sceneRenderer = Renderer();
	void CalculateDeltaTime();
};
