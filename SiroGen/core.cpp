#include <SiroGen/core.h>

Core::Core()
{
}

void Core::Start(Scene* scene)
{
    //First it checks if there are any entities to direct them to the correct window for the keyboard support
    scene->InputInit(scene, sceneRenderer._window);

    do
    {
        _time->CalculateDeltaTime();
        //Camera is not derived from Entity so it has to be updated secludedly
        scene->GetMainCamera()->UpdateCamera();

        //Finally it renders all of the found entities' Components. Either it being graphical or else
        sceneRenderer.RenderScene(scene);

        for (int i = 0; i < _time->UpdateableEntites.size(); i++)
        {
            _time->UpdateableEntites[i]->update(_time->deltaTime);
        }
        //Do this while the windows 'X' mark has not been clicked on or 
        //when the user as run into the StopRunning command
    } while (glfwWindowShouldClose(sceneRenderer._window) == 0 && scene->isRunning);
}
