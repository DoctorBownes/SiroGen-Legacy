#include "floor.h"

const int width = 8;
const int height = 8;
const int TileSize = 16;

int testlevel[height][width]{
{ 1,1,1,1,1,1,1,1 },
{ 1,0,1,0,0,0,0,1 },
{ 1,1,1,0,0,0,0,1 },
{ 1,0,1,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,1 },
{ 1,0,0,0,1,0,0,1 },
{ 1,1,1,1,1,1,1,1 },
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
			Tile* t = makers[testlevel[y][x]]();
			setPos(t, x, y);
			Addchild(t);
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