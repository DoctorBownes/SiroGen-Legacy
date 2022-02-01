#include <SiroGen/core.h>

Core::Core()
{
	deltaTime = 0;
}

void Core::Start(Scene* scene)
{
	scene->GetInput()->Init(sceneRenderer.window);
	std::vector<Entity*> child = scene->GetEntities();
	std::vector<Entity*>::iterator it;
	for (it = child.begin(); it != child.end(); it++)
	{
		scene->InputInit(*it, sceneRenderer.window);
	}
	do
	{
		CalculateDeltaTime();

		scene->GetMainCamera()->UpdateCamera();

		scene->update((float)deltaTime);
		std::vector<Entity*> child = scene->GetEntities();
		std::vector<Entity*>::iterator it;
		for (it = child.begin(); it != child.end(); it++)
		{
			scene->updateEntities(*it, (float)deltaTime);
		}

		sceneRenderer.RenderScene(scene);
	} 	while (glfwWindowShouldClose(sceneRenderer.window) == 0);
}

void Core::CalculateDeltaTime()
{
	static double starttime = glfwGetTime();
	double endtime = glfwGetTime();
	deltaTime = endtime - starttime;
	starttime = endtime;
}