#ifndef WALL_H_
#define WALL_H_
#include "tile.h"

class Wall :
    public Tile
{
public:
    Wall();
    void Activate(Player* player) override;
};

#endif
