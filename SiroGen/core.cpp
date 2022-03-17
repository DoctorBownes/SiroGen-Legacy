#include <SiroGen/core.h>

Core::Core()
{
	deltaTime = 0;
}

void Core::Start(Scene* scene)
{
    //First it checks if there are any entities to direct them to the correct window for the keyboard support
    scene->InputInit(scene, sceneRenderer._window);
    //It renders prematurely once, to properly set the entity's position
    //Scenes are derived from the Entity class. This way all of it's children will also be 
    //properly set. 
    sceneRenderer.RenderScene(scene);
    do
    {
        //Calculates the deltaTime to prevent inconsistent speeds
        CalculateDeltaTime();

        //Camera is not derived from Entity so it has to be updated secludedly
        scene->GetMainCamera()->UpdateCamera();

        //Goes through all found entities update functions and runs whatever is put there
        scene->updateEntities(scene, (float)deltaTime);

        //Finally it renders all of the found entities' Components. Either it being graphical or else
        sceneRenderer.RenderScene(scene);
        //Do this while the windows 'X' mark has not been clicked on or 
        //when the user as run into the StopRunning command
    } while (glfwWindowShouldClose(sceneRenderer._window) == 0 && scene->isRunning);
}

void Core::CalculateDeltaTime()
{
	static double starttime = glfwGetTime();
	double endtime = glfwGetTime();
	deltaTime = endtime - starttime;
	starttime = endtime;
}