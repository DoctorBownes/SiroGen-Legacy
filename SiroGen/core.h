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
	Renderer sceneRenderer = Renderer();
};

#endif
