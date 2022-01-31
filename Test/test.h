#pragma once
#include <SiroGen/scene.h>

class Test :
    public Scene
{
public:
    Test();
    void ShowSlide();
    virtual void update(float deltaTime);
};

