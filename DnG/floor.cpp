#include "floor.h"

const int width = 8;
const int height = 8;
const int TileSize = 16;

Wall* w;
Ground* g;

//Tile* testlevel[height][width]{
//{ w,w,w,w,w,w,w,w },
//{ w,g,w,g,g,g,g,w },
//{ w,g,w,g,g,g,g,w },
//{ w,g,w,g,g,g,g,w },
//{ w,g,g,g,g,g,g,w },
//{ w,g,g,g,g,g,g,w },
//{ w,g,g,g,w,g,g,w },
//{ w,w,w,w,w,w,w,w },
//};

int testlevel[height][width]{
{ 0,0,1,1,1,1,1,1 },
{ 0,0,1,0,0,0,0,1 },
{ 1,0,1,0,0,0,0,1 },
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

std::map<std::pair<int,int>, Tile*> TileMap;

Tile* Tiles(int x, int y)
{
	return TileMap[std::make_pair(x, y)];
}

Floor::Floor() : Scene()
{
	this->GetMainCamera()->SetZoom(20);
	this->player = new Player();
	setPos(player, 3, 2);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			TileMap[std::make_pair(x, y)] = makers[testlevel[y][x]]();
			setPos(TileMap[std::make_pair(x, y)], x, y);
			Addchild(TileMap[std::make_pair(x, y)]);
		}
	}
	this->Addchild(player);
}

int* getPos(Entity* entity)
{
	int arrayint[2]{};
	arrayint[0] = std::round(entity->transform->position->x / TileSize);
	arrayint[1] = std::round(-entity->transform->position->y / TileSize);
	return arrayint;
}

void Floor::update(float deltaTime)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (player->GetComponent<Collider>()->isColliding(Tiles(x, y)) && !Tiles(x,y)->walkable)
			{
				player->transform->position->x = player->oldpos->x;
				player->transform->position->y = player->oldpos->y;
			}
		}
	}
	std::cout << "X: " << getPos(player)[0] << " Y: " << getPos(player)[1] << std::endl;
	if (GetInput()->KeyPressed(KeyCode::Escape))
	{
		isRunning = false;
	}
	GetMainCamera()->position.x = player->transform->position->x;
	GetMainCamera()->position.y = player->transform->position->y;
}