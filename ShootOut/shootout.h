#ifndef SHOOTOUT_H_
#define SHOOTOUT_H_
#include <SiroGen/scene.h>
#include "player.h"

class ShootOut :
    public Scene
{
public:
    ShootOut();
    virtual void update(float deltaTime);

private:
    Player* player1 = new Player();
    Player* player2 = new Player();
    Player* player3 = new Player();
    Player* player4 = new Player();
    int speed = 0;
};

#endif
