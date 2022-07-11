#include "floor.h"

const int width = 8;
const int height = 8;
const int TileSize = 16;

Wall* w;
Ground* g;

Tile* testlevel[height][width]{
{ w,w,w,w,w,w,w,w },
{ w,g,w,g,g,g,g,w },
{ w,g,w,g,g,g,g,w },
{ w,g,w,g,g,g,g,w },
{ w,g,g,g,g,g,g,w },
{ w,g,g,g,g,g,g,w },
{ w,g,g,g,w,g,g,w },
{ w,w,w,w,w,w,w,w },
};

void setPos(Entity* entity, int x, int y)
{
	entity->transform->position->x = x * TileSize;
	entity->transform->position->y = -y * TileSize;
}

typedef Tile* TileMaker();

template <class T> Tile* make() {
	return new T;
}

TileMaker* makers[] = { make<Ground>, make<Wall>};

Floor::Floor() : Scene()
{
	this->GetMainCamera()->SetZoom(20);
	this->player = new Player();
	setPos(player, 3, 2);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			testlevel[y][x] = new Wall();
			setPos(testlevel[y][x], x, y);
			Addchild(testlevel[y][x]);
		}
	}
	this->Addchild(player);
}

void Floor::update(float deltaTime)
{
	if (GetInput()->KeyPressed(KeyCode::Escape))
	{
		isRunning = false;
	}
	GetMainCamera()->position.x = player->transform->position->x;
	GetMainCamera()->position.y = player->transform->position->y;
}