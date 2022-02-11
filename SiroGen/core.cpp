#include <SiroGen/core.h>

Core::Core()
{
	deltaTime = 0;
}

void Core::Start(Scene* scene)
{
	scene->InputInit(scene, sceneRenderer.window);	
	do
	{
		CalculateDeltaTime();

		scene->GetMainCamera()->UpdateCamera();

		scene->updateEntities(scene, (float)deltaTime);

		sceneRenderer.RenderScene(scene);
	} 	while (glfwWindowShouldClose(sceneRenderer.window) == 0 && scene->isRunning);
}

void Core::CalculateDeltaTime()
{
	static double starttime = glfwGetTime();
	double endtime = glfwGetTime();
	deltaTime = endtime - starttime;
	starttime = endtime;
}