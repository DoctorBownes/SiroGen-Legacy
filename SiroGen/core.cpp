#include <SiroGen/core.h>

float deltaTime = 0.0f;

Core::Core()
{
}

void CalculateDeltaTime()
{
    static double starttime = glfwGetTime();
    double endtime = glfwGetTime();
    deltaTime = endtime - starttime;
    starttime = endtime;
}

void Core::Start(Scene* scene)
{
    //First it checks if there are any entities to direct them to the correct window for the keyboard support
    scene->InputInit(scene, sceneRenderer._window);
    do
    {
        CalculateDeltaTime();
        //Camera is not derived from Entity so it has to be updated secludedly
        scene->GetMainCamera()->UpdateCamera();
        //Finally it renders all of the found entities' Components. Either it being graphical or else
        sceneRenderer.RenderScene(scene);
        //Do this while the windows 'X' mark has not been clicked on or 
        //when the user as run into the StopRunning command
    } while (glfwWindowShouldClose(sceneRenderer._window) == 0 && scene->isRunning);
}
