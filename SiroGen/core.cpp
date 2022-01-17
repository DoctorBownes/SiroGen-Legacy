#include <SiroGen/core.h>

Core::Core()
{
	deltaTime = 0;
}

void Core::Start(Scene* scene)
{
	scene->GetInput()->Init(sceneRenderer.window);
	do
	{
		CalculateDeltaTime();

		scene->GetMainCamera()->UpdateCamera();

		scene->update((float)deltaTime);

		sceneRenderer.RenderScene(scene);
	} 	while (glfwWindowShouldClose(sceneRenderer.window) == 0);
}

void Core::CalculateDeltaTime()
{
	double starttime = glfwGetTime();
	double endtime = glfwGetTime();
	deltaTime = endtime - starttime;
	endtime = starttime;
}