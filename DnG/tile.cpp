#include "tile.h"

Tile::Tile()
{
	RemoveComponent<Update>();
	AddComponent<Sprite>();
	AddComponent<Collider>()->SetUpSquare(0,0,16,16);
}
