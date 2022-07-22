#include "time.h"
Time* Time::_instance = 0;

void Time::CalculateDeltaTime()
{
    static double starttime = glfwGetTime();
    double endtime = glfwGetTime();
    deltaTime = endtime - starttime;
    starttime = endtime;
}

Time::Time()
{
}
