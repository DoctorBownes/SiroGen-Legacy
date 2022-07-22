#ifndef CORE_H_
#define CORE_H_
#include <glm/glm.hpp>

#include <SiroGen/scene.h>
#include <SiroGen/renderer.h>

class Core
{
public:
	Core();
	void Start(Scene* scene);
private:
	Time* _time = _time->GetInstance();
	Renderer sceneRenderer = Renderer();
};

#endif
