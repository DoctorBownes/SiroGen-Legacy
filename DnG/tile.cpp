#include "tile.h"

Tile::Tile()
{
	//shouldUpdate = false;
	AddComponent<Sprite>();
	AddComponent<Collider>()->SetUpSquare(0,0,16,16);
}
