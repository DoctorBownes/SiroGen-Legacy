#include "floor.h"

const int width = 32;
const int height = 32;
const int TileSize = 16;

int testlevel[height][width]{
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
{ 1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,},
{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
{ 1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,0,0,0,1,},
{ 1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,},
{ 1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,},
{ 1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,0,0,1,},
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
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

std::map<std::pair<int,int>, Entity*> ItemMap;

Tile* Tiles(int x, int y)
{
	return TileMap[std::make_pair(x, y)];
}

Entity* Items(int x, int y)
{
	return ItemMap[std::make_pair(x, y)];
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
		}
	}

	static char keycanvas[] {
		0x7,0x7,0x7,0x0,0x0,0x0,0x0,0x0,
		0x7,0x0,0x7,0x7,0x7,0x7,0x7,0x7,
		0x7,0x7,0x7,0x0,0x0,0x7,0x0,0x7,
	};

	Entity* magickey = new Entity();
	magickey->AddComponent<Sprite>()->SetSprite(keycanvas, 8, 3);
	magickey->AddComponent<Collider>()->SetUpSquare(0, 0, 8, 3);
	ItemMap[std::make_pair(5, 2)] = magickey;
	setPos(magickey,5, 2);

	this->Addchild(player);
	this->Addchild(magickey);
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
	for (int y = -4; y < 4; y+=7)
	{
		for (int x = -3; x < 3; x++)
		{
			if (Tiles(getPos(player)[0] + x, getPos(player)[1] + y) && Tiles(getPos(player)[0] + x, getPos(player)[1] + y)->Parent)
			{
				Removechild(Tiles(getPos(player)[0] + x, getPos(player)[1] + y));
			}
		}
	}
	for (int y = -3; y < 3; y++)
	{
		for (int x = -4; x < 4; x+= 7)
		{
			if (Tiles(getPos(player)[0] + x, getPos(player)[1] + y) && Tiles(getPos(player)[0] + x, getPos(player)[1] + y)->Parent)
			{
				Removechild(Tiles(getPos(player)[0] + x, getPos(player)[1] + y));
			}
		}
	}
	for (int y = -3; y < 3; y++)
	{
		for (int x = -3; x < 3; x++)
		{
			if (Tiles(getPos(player)[0] + x, getPos(player)[1] + y) && !Tiles(getPos(player)[0] + x, getPos(player)[1] + y)->Parent)
			{
				Addchildfront(Tiles(getPos(player)[0] + x, getPos(player)[1] + y));
			}
		}
	}
	for (int y = -1; y < 1; y++)
	{
		for (int x = -1; x < 1; x++)
		{
			if (player->GetComponent<Collider>()->isColliding(Tiles(getPos(player)[0] + x, getPos(player)[1] + y)) && !Tiles(getPos(player)[0] + x, getPos(player)[1] + y)->walkable)
			{
				player->transform.position.x = player->oldpos.x;
				player->transform.position.y = player->oldpos.y;
			}
			if (Items(getPos(player)[0] + x, getPos(player)[1] + y) && player->GetComponent<Collider>()->isColliding(Items(getPos(player)[0] + x, getPos(player)[1] + y)))
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