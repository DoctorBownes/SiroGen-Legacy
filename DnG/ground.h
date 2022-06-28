#ifndef GROUND_H_
#define GROUND_H_
#include "tile.h"

class Ground :
    public Tile
{
public:
    Ground();
    virtual void update(float deltaTime);
};

#endif
