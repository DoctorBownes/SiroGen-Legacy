#ifndef CORE_H_
#define CORE_H_

#include <SiroGen/scene.h>
#include <SiroGen/renderer.h>

class Core
{
public:
	Core();
	void Start(Scene* scene);
private:
	void CalculateDeltaTime();
	float deltaTime = 0.0f;
	double starttime = 0.0;
	Renderer sceneRenderer = Renderer();
};

#endif
