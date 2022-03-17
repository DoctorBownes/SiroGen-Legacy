#ifndef TEST_H_
#define TEST_H_
#include <SiroGen/scene.h>
#include "player.h"

class Test :
    public Scene
{
public:
    Test();
    virtual void update(float deltaTime);
   // Player* joey;
};

#endif
