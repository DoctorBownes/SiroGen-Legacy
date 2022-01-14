#pragma once
#include <SiroGen/scene.h>
#include <SiroGen/entity.h>

class Test :
    public Scene
{
public:
    Test();
    virtual void update(float deltaTime);
};

