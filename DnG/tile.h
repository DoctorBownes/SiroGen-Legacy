#ifndef TILE_H_
#define TILE_H_
#include <SiroGen/entity.h>
#include "player.h"

class Tile :
    public Entity
{
public:
    Tile();
    virtual void Activate(Player* entity);
};

#endif
