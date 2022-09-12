#include "floor.h"

Floor::Floor() : Scene()
{
	//Tile* SetLevel[LevelHeight][LevelWidth] {
	//{ new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),},
	//{ new Wall(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Wall(),},
	//{ new Wall(),new Ground(),new Ground(),new Ground(),new Ground(),new Wall(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Wall(),},
	//{ new Wall(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Wall(),},
	//{ new Wall(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Wall(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Wall(),},
	//{ new Wall(),new Ground(),new Ground(),new Ground(),new Wall(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Wall(),},
	//{ new Wall(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Ground(),new Wall(),},
	//{ new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),new Wall(),},
	//};
	std::cout << sizeof(Sprite) << std::endl;
	this->GetMainCamera()->SetZoom(2);
	this->player = new Player();

	//static char MarioSprite[]{
	//	0x0,0x0,0x0,0x4,0x4,0x4,0x4,0x4,0x0,0x0,0x0,0x0,
	//	0x0,0x0,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x0,
	//	0x0,0x0,0x1,0x1,0x1,0xc,0xc,0x1,0xc,0x0,0x0,0x0,
	//	0x0,0x1,0xc,0x1,0xc,0xc,0xc,0x1,0xc,0xc,0xc,0x0,
	//	0x0,0x1,0xc,0x1,0x1,0xc,0xc,0xc,0x1,0xc,0xc,0xc,
	//	0x0,0x1,0x1,0xc,0xc,0xc,0xc,0x1,0x1,0x1,0x1,0x0,
	//	0x0,0x0,0x0,0xc,0xc,0xc,0xc,0xc,0xc,0xc,0x0,0x0,
	//	0x0,0x0,0x0,0x2,0x4,0x2,0x2,0x2,0x0,0x0,0x0,0x0,
	//	0x0,0x2,0x2,0x2,0x4,0x2,0x2,0x4,0x2,0x2,0x2,0x0,
	//	0x2,0x2,0x2,0x2,0x4,0x4,0x4,0x4,0x2,0x2,0x2,0x2,
	//	0xc,0xc,0x2,0x4,0xd,0x4,0x4,0xd,0x4,0x2,0xc,0xc,
	//	0xc,0xc,0xc,0x4,0x4,0x4,0x4,0x4,0x4,0xc,0xc,0xc,
	//	0xc,0xc,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0xc,0xc,
	//	0x0,0x0,0x4,0x4,0x4,0x0,0x0,0x4,0x4,0x4,0x0,0x0,
	//	0x0,0x1,0x1,0x1,0x0,0x0,0x0,0x0,0x1,0x1,0x1,0x0,
	//	0x1,0x1,0x1,0x1,0x0,0x0,0x0,0x0,0x1,0x1,0x1,0x1,
	//};

	static char wt[]
	{
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,
		0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,
		0xe,0xe,0xe,0xe,0xe,0xe,0xe,0x1,0xe,0xe,0xe,0xe,0xe,0xe,0xe,0x1,
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,
		0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,
		0xe,0xe,0xe,0x1,0xe,0xe,0xe,0xe,0xe,0xe,0xe,0x1,0xe,0xe,0xe,0xe,
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,
		0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,
		0xe,0xe,0xe,0xe,0xe,0xe,0xe,0x1,0xe,0xe,0xe,0xe,0xe,0xe,0xe,0x1,
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,
		0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,0xf,0xf,0xf,0x1,0xe,0xf,0xf,0xf,
		0xe,0xe,0xe,0x1,0xe,0xe,0xe,0xe,0xe,0xe,0xe,0x1,0xe,0xe,0xe,0xe,
	};

	static char gt[]
	{
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0xf,0xf,0x1,0x1,0x1,0x1,0x1,0x1,
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0xf,0xf,0x1,0x1,0x1,0x1,0x1,0x1,
		0xf,0xf,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0xf,0xf,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0xf,0xf,0x1,0x1,0x1,
		0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0xf,0xf,0x1,0x1,0x1,
		0x1,0x1,0x1,0xf,0xf,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
		0x1,0x1,0x1,0xf,0xf,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,
	};

	static char* TileMap[]//96x64
	{
		wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,wt,
		wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,wt,
	};

	Entity* Mario = new Entity();
	Mario->AddComponent<Sprite>()->SetTileSprite(TileMap, 32,32, 16);
	Addchild(Mario);
	bkgdcolor = 0xe;
	//player->transform.position.x = 2 * TileSize;
	//player->transform.position.y = 3 * -TileSize;

	//for (int y = 0; y < LevelHeight; y++)
	//{
	//	for (int x = 0; x < LevelWidth; x++)
	//	{
	//		TileLevel[y][x] = SetLevel[y][x];
	//		Addchild(TileLevel[y][x]);
	//		TileLevel[y][x]->transform.position.x = x * TileSize;
	//		TileLevel[y][x]->transform.position.y = y * -TileSize;
	//		SetLevel[y][x] = nullptr;
	//		//hm->Insert(Tiles(x, y));
	//	}
	//}

	this->Addchild(player);
	//this->Addchild(hm->getCell(0, 0)[0]);
}

void Floor::update(float deltaTime)
{
	//for (int y = -3; y < 4; y++)
	//{
	//	for (int x = -3; x < 4; x++)
	//	{
	//		if (RenderMap[std::max(0, std::min(BOUNDS -1, getCell(player)[0] + x))][std::max(0, std::min(BOUNDS - 1, getCell(player)[1] + y * -1))][0]->Parent)
	//		{
	//			for (int i = 0; i < RenderMap[std::max(0, std::min(BOUNDS - 1, getCell(player)[0] + x))][std::max(0, std::min(BOUNDS - 1, getCell(player)[1] + y * -1))].size(); i++)
	//			{
	//				Removechild(RenderMap[std::max(0, std::min(BOUNDS - 1, getCell(player)[0] + x))][std::max(0, std::min(BOUNDS - 1, getCell(player)[1] + y * -1))][i]);
	//			}
	//		}
	//	}
	//}
	//for (int y = -2; y < 3; y++)
	//{
	//	for (int x = -2; x < 3; x++)
	//	{
	//		if (!RenderMap[std::max(0, std::min(BOUNDS - 1, getCell(player)[0] + x))][std::max(0, std::min(BOUNDS - 1, getCell(player)[1] + y * -1))][0]->Parent)
	//		{
	//			for (int i = 0; i < RenderMap[std::max(0, std::min(BOUNDS - 1, getCell(player)[0] + x))][std::max(0, std::min(BOUNDS - 1, getCell(player)[1] + y * -1))].size(); i++)
	//			{
	//				Addchildfront(RenderMap[std::max(0, std::min(BOUNDS - 1, getCell(player)[0] + x))][std::max(0, std::min(BOUNDS - 1, getCell(player)[1] + y * -1))][i]);
	//			}
	//		}
	//	}
	//}
	//for (int y = -1; y < 1; y++)
	//{
	//	for (int x = -1; x < 1; x++)
	//	{
	//		Tiles(getPos(player)[0] + x, getPos(player)[1] + y)->Activate(player);
	//	}
	//}
	if (GetInput()->KeyPressed(KeyCode::Escape))
	{
		isRunning = false;
	}
	GetMainCamera()->position.x = player->transform.position.x;
	GetMainCamera()->position.y = player->transform.position.y;
}