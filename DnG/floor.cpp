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
{ 1,1,1,1,1,1,1,1},
{ 1,0,1,0,0,0,0,1},
{ 1,0,1,0,0,0,0,1},
{ 1,0,1,0,0,0,0,1},
{ 1,0,0,0,0,0,0,1},
{ 1,0,0,0,0,0,0,1},
{ 1,0,0,0,1,0,0,1},
{ 1,1,1,1,1,1,1,1},
};

void setPos(Entity* entity, int x, int y)
{
	entity->transform.position.x = x * TileSize;
	entity->transform.position.y = -y * TileSize;
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
	this->GetMainCamera()->SetZoom(10);
	this->player = new Player();
	setPos(player, 3, 2);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			TileMap[std::make_pair(x, y)] = makers[testlevel[y][x]]();
			setPos(Tiles(x, y), x, y);
			Addchild(Tiles(x, y));
		}
	}

	this->Addchild(player);
}

int* getPos(Entity* entity)
{
	int arrayint[2]{};
	arrayint[0] = std::ceil(entity->transform.position.x / TileSize);
	arrayint[1] = std::ceil(-entity->transform.position.y / TileSize);
	return arrayint;
}

void Floor::update(float deltaTime)
{
	for (int y = -1; y < 1; y++)
	{
		for (int x = -1; x < 1; x++)
		{
			if (player->GetComponent<Collider>()->isColliding(Tiles(getPos(player)[0] + x, getPos(player)[1] + y)) && !Tiles(getPos(player)[0] + x, getPos(player)[1] + y)->walkable)
			{
				player->transform.position.x = player->oldpos.x;
				player->transform.position.y = player->oldpos.y;
			}
		}
	}
	//std::cout << "X: " << player->transform.position.x << " Y: " << player->transform.position.y << std::endl;
	//std::cout << "World X: " << player->worldtransform.position.x << " World Y: " << player->worldtransform.position.y << std::endl;
	
	if (GetInput()->KeyPressed(KeyCode::Escape))
	{
		isRunning = false;
	}
	GetMainCamera()->position.x = player->transform.position.x;
	GetMainCamera()->position.y = player->transform.position.y;
}