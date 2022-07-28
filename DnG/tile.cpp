#include "tile.h"

Tile::Tile()
{
	AddComponent<Sprite>();
	AddComponent<Collider>()->SetUpSquare(0,0,16,16);
}

void Tile::Activate(Player* entity)
{
}
