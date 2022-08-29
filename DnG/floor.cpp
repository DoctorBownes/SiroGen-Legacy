#include "floor.h"
#include <SiroGen/hashmap.h>

#define Tiles(x,y) TileMap[std::make_pair(x, y)]

#define BOUNDS 12

const int width = 32;
const int height = 32;
const int TileSize = 16;

#define CELLSIZE width * TileSize

int testlevel[height][width]{
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
{ 1,0,1,0,1,0,1,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,},
{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
{ 1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,},
{ 1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,},
{ 1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,},
{ 1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,},
{ 1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
{ 1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
{ 1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,},
{ 1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,},
{ 1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,},
{ 1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,},
{ 1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,},
{ 1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,},
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,},
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,},
{ 1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,1,},
{ 1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,},
{ 1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,},
{ 1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,},
{ 1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,},
{ 1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,},
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
{ 1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,},
{ 1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,},
{ 1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,},
{ 1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,},
{ 1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,},
{ 1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,},
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
};

std::vector<Entity*> RenderMap[BOUNDS][BOUNDS];

void setPos(Entity* entity, int x, int y)
{
	entity->transform.position.x = x * TileSize;
	entity->transform.position.y = -y * TileSize;
}

void setJos(Entity* entity, int x, int y)
{
	entity->transform.position.x = x;
	entity->transform.position.y = y;
}

typedef Tile* TileMaker();

template <class T> Tile* make() {
	return new T;
}

//HashMap* hm = new HashMap(0,0,512,-512, 9);

TileMaker* makers[] = { make<Ground>, make<Wall>};

std::map<std::pair<int,int>, Tile*> TileMap;

int* getPos(Entity* entity)
{
	int arrayint[2]{};
	arrayint[0] = std::ceil(entity->transform.position.x / TileSize);
	arrayint[1] = std::ceil(-entity->transform.position.y / TileSize);
	return arrayint;
}

int* getCell(Entity* entity)
{
	int arrayint[2]{};
	arrayint[0] = entity->transform.position.x / (CELLSIZE / BOUNDS);
	arrayint[1] = entity->transform.position.y / (-CELLSIZE / BOUNDS);
	return arrayint;
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
			RenderMap[getCell(Tiles(x, y))[0]][getCell(Tiles(x, y))[1]].push_back(Tiles(x,y));
			//hm->Insert(Tiles(x, y));
		}
	}

	std::cout << RenderMap[0][0].size() << std::endl;

	static char keycanvas[] {
		0x7,0x7,0x7,0x0,0x0,0x0,0x0,0x0,
		0x7,0x0,0x7,0x7,0x7,0x7,0x7,0x7,
		0x7,0x7,0x7,0x0,0x0,0x7,0x0,0x7,
	};

	Entity* magickey = new Entity();
	magickey->AddComponent<Sprite>()->SetSprite(keycanvas, 8, 3);
	magickey->AddComponent<Collider>()->SetUpSquare(0, 0, 8, 3);
	//setJos(magickey,510, 0);
	//hm->Insert(magickey);

	this->Addchild(player);
	//this->Addchild(hm->getCell(0, 0)[0]);
}

void Floor::update(float deltaTime)
{
	for (int y = -3; y < 4; y++)
	{
		for (int x = -3; x < 4; x++)
		{
			if (RenderMap[std::max(0, std::min(BOUNDS -1, getCell(player)[0] + x))][std::max(0, std::min(BOUNDS - 1, getCell(player)[1] + y * -1))][0]->Parent)
			{
				for (int i = 0; i < RenderMap[std::max(0, std::min(BOUNDS - 1, getCell(player)[0] + x))][std::max(0, std::min(BOUNDS - 1, getCell(player)[1] + y * -1))].size(); i++)
				{
					Removechild(RenderMap[std::max(0, std::min(BOUNDS - 1, getCell(player)[0] + x))][std::max(0, std::min(BOUNDS - 1, getCell(player)[1] + y * -1))][i]);
				}
			}
		}
	}
	for (int y = -2; y < 3; y++)
	{
		for (int x = -2; x < 3; x++)
		{
			if (!RenderMap[std::max(0, std::min(BOUNDS - 1, getCell(player)[0] + x))][std::max(0, std::min(BOUNDS - 1, getCell(player)[1] + y * -1))][0]->Parent)
			{
				for (int i = 0; i < RenderMap[std::max(0, std::min(BOUNDS - 1, getCell(player)[0] + x))][std::max(0, std::min(BOUNDS - 1, getCell(player)[1] + y * -1))].size(); i++)
				{
					Addchildfront(RenderMap[std::max(0, std::min(BOUNDS - 1, getCell(player)[0] + x))][std::max(0, std::min(BOUNDS - 1, getCell(player)[1] + y * -1))][i]);
				}
			}
		}
	}
	for (int y = -1; y < 1; y++)
	{
		for (int x = -1; x < 1; x++)
		{
			Tiles(getPos(player)[0] + x, getPos(player)[1] + y)->Activate(player);
		}
	}
	if (GetInput()->KeyPressed(KeyCode::Escape))
	{
		isRunning = false;
	}
	GetMainCamera()->position.x = player->transform.position.x;
	GetMainCamera()->position.y = player->transform.position.y;
}