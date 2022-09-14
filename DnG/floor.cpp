#include "floor.h"

Floor::Floor() : Scene()
{
	//char SetLevel[32][32] {
	//{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
	//{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	//};

	this->GetMainCamera()->SetZoom(12);
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
		BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,
		GRY,WHT,WHT,WHT,WHT,WHT,WHT,BLK,GRY,WHT,WHT,WHT,WHT,WHT,WHT,BLK,
		GRY,WHT,WHT,WHT,WHT,WHT,WHT,BLK,GRY,WHT,WHT,WHT,WHT,WHT,WHT,BLK,
		GRY,GRY,GRY,GRY,GRY,GRY,GRY,BLK,GRY,GRY,GRY,GRY,GRY,GRY,GRY,BLK,
		BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,
		WHT,WHT,WHT,BLK,GRY,WHT,WHT,WHT,WHT,WHT,WHT,BLK,GRY,WHT,WHT,WHT,
		WHT,WHT,WHT,BLK,GRY,WHT,WHT,WHT,WHT,WHT,WHT,BLK,GRY,WHT,WHT,WHT,
		GRY,GRY,GRY,BLK,GRY,GRY,GRY,GRY,GRY,GRY,GRY,BLK,GRY,GRY,GRY,GRY,
		BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,
		GRY,WHT,WHT,WHT,WHT,WHT,WHT,BLK,GRY,WHT,WHT,WHT,WHT,WHT,WHT,BLK,
		GRY,WHT,WHT,WHT,WHT,WHT,WHT,BLK,GRY,WHT,WHT,WHT,WHT,WHT,WHT,BLK,
		GRY,GRY,GRY,GRY,GRY,GRY,GRY,BLK,GRY,GRY,GRY,GRY,GRY,GRY,GRY,BLK,
		BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,
		WHT,WHT,WHT,BLK,GRY,WHT,WHT,WHT,WHT,WHT,WHT,BLK,GRY,WHT,WHT,WHT,
		WHT,WHT,WHT,BLK,GRY,WHT,WHT,WHT,WHT,WHT,WHT,BLK,GRY,WHT,WHT,WHT,
		GRY,GRY,GRY,BLK,GRY,GRY,GRY,GRY,GRY,GRY,GRY,BLK,GRY,GRY,GRY,GRY,
	};
	
	static char gt[]
	{
		BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,
		BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,
		BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,
		BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,
		BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,WHT,WHT,BLK,BLK,BLK,BLK,BLK,BLK,
		BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,WHT,WHT,BLK,BLK,BLK,BLK,BLK,BLK,
		WHT,WHT,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,
		WHT,WHT,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,
		BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,
		BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,
		BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,
		BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,
		BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,WHT,WHT,BLK,BLK,BLK,
		BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,WHT,WHT,BLK,BLK,BLK,
		BLK,BLK,BLK,WHT,WHT,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,
		BLK,BLK,BLK,WHT,WHT,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,BLK,
	};

	static char* TileMap[]
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
	Mario->AddComponent<Sprite>()->SetTileSprite(TileMap, 32, 32, 16);
	Addchild(Mario);
	bkgdcolor = ICE;
	//player->transform.position.x = 2 * TileSize;
	//player->transform.position.y = 3 * -TileSize;

	
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