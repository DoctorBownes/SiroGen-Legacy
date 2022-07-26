#include <SiroGen/core.h>

Core::Core()
{
    starttime = glfwGetTime();
}

void Core::CalculateDeltaTime()
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

        scene->updateEntities(scene, (float)deltaTime);


       // static int framecounter = 0;
       // static int averageframerate = 0;
      //  static int counter = 0;
       // if (glfwGetTime() - starttime > 1.0f) {
       //       std::cout << framecounter << std::endl;
       //     counter++;
       //     averageframerate += framecounter;
       //     std::cout << averageframerate / counter << std::endl;
       //     framecounter = 0;
       //     starttime = glfwGetTime();
       // }
       // framecounter++;
        //Do this while the windows 'X' mark has not been clicked on or 
        //when the user as run into the StopRunning command
    } while (glfwWindowShouldClose(sceneRenderer._window) == 0 && scene->isRunning);
}
