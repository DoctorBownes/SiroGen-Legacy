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

	this->GetMainCamera()->SetZoom(6);
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

	static char sl[]
	{ 23,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
10,23,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
10,13,10,0,0,0,0,0,0,0,0,0,0,0,0,0,
10,23,10,23,0,0,0,0,0,0,0,0,0,0,0,0,
23,10,23,10,13,0,0,0,0,0,0,0,0,0,0,0,
10,10,13,10,23,0,0,0,0,0,0,0,0,0,0,0,
13,23,10,23,10,10,0,0,0,0,0,0,0,0,0,0,
10,13,13,10,13,23,13,0,0,0,0,0,0,0,0,0,
14,10,13,23,23,10,23,0,0,0,0,0,0,0,0,0,
14,14,13,13,13,10,10,23,0,0,0,0,0,0,0,0,
14,13,13,13,13,13,23,10,23,10,0,0,0,0,0,0,
13,13,13,13,13,13,13,23,10,10,23,13,0,0,0,0,
13,13,13,13,13,10,10,13,10,13,10,23,23,0,0,0,
13,13,13,13,10,14,14,23,23,10,23,10,10,23,0,0,
13,13,13,13,14,14,14,14,10,10,13,13,23,13,23,0,
13,13,13,13,13,13,13,13,13,13,13,13,13,10,23,10,

	};
	
	static char gt[]
	{
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,
		BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,BKG,
	};

	static char gs[]
	{ 
23,0,10,0,0,0,23,0,0,0,10,0,10,0,0,0,
10,23,13,23,0,13,23,10,0,10,10,23,10,23,13,0,
13,23,10,23,10,10,23,10,10,13,23,10,10,23,10,23,
23,10,10,23,10,23,10,10,23,10,23,10,13,23,10,23,
13,10,23,13,23,10,10,13,10,23,10,10,23,10,13,23,
10,23,10,10,23,10,23,10,10,23,10,23,13,10,23,10,
23,10,13,23,10,10,13,10,23,13,10,23,10,10,10,23,
10,13,23,10,10,13,13,13,10,10,23,13,13,13,23,10,
13,13,10,10,10,13,13,13,13,23,10,13,13,13,13,10,
13,13,13,10,10,13,13,13,13,10,10,13,13,13,13,10,
13,13,13,10,13,13,13,13,13,13,10,13,13,13,13,13,
13,13,13,13,13,13,13,13,13,13,13,13,4,13,13,13,
13,13,4,13,13,13,13,13,13,13,13,4,13,13,13,13,
13,13,13,13,13,10,13,13,4,13,13,13,4,13,13,13,
13,4,13,13,4,10,10,13,4,13,13,13,4,10,13,13,
13,13,4,13,13,4,13,13,13,4,13,13,10,4,10,13,


	};

	static char dt[]
	{ 
		OLV,OLV,MRN,OLV,OLV,OLV,MRN,OLV,OLV,OLV,MRN,FOR,GRY,GRY,GRY,OLV,
		OLV,OLV,OLV,OLV,OLV,OLV,OLV,MRN,MRN,MRN,OLV,FOR,GRY,GRY,GRY,OLV,
		OLV,OLV,OLV,OLV,OLV,OLV,OLV,OLV,OLV,MRN,MRN,MRN,OLV,GRY,OLV,OLV,
		OLV,OLV,OLV,OLV,FOR,FOR,OLV,OLV,OLV,OLV,OLV,MRN,MRN,MRN,OLV,OLV,
		OLV,OLV,OLV,FOR,GRY,FOR,FOR,OLV,OLV,OLV,OLV,OLV,OLV,OLV,MRN,OLV,
		MRN,OLV,FOR,GRY,GRY,GRY,GRY,FOR,OLV,OLV,OLV,OLV,OLV,OLV,OLV,MRN,
		FOR,OLV,OLV,OLV,OLV,OLV,OLV,OLV,FOR,OLV,OLV,OLV,OLV,OLV,OLV,FOR,
		GRY,FOR,OLV,OLV,OLV,OLV,OLV,OLV,OLV,OLV,OLV,OLV,OLV,OLV,FOR,GRY,
		GRY,GRY,OLV,OLV,OLV,OLV,MRN,MRN,OLV,OLV,OLV,OLV,OLV,OLV,OLV,GRY,
		GRY,OLV,OLV,OLV,OLV,OLV,OLV,MRN,MRN,MRN,OLV,MRN,OLV,OLV,OLV,OLV,
		OLV,OLV,OLV,OLV,OLV,OLV,OLV,OLV,OLV,MRN,OLV,OLV,MRN,OLV,OLV,OLV,
		OLV,MRN,OLV,OLV,OLV,FOR,FOR,OLV,OLV,OLV,OLV,OLV,MRN,MRN,OLV,OLV,
		OLV,MRN,MRN,OLV,FOR,GRY,GRY,FOR,FOR,OLV,OLV,OLV,OLV,MRN,OLV,OLV,
		OLV,OLV,MRN,OLV,GRY,GRY,GRY,GRY,FOR,FOR,OLV,OLV,OLV,MRN,MRN,OLV,
		OLV,OLV,MRN,OLV,OLV,OLV,MRN,OLV,OLV,OLV,OLV,OLV,OLV,FOR,OLV,MRN,
		OLV,OLV,OLV,MRN,OLV,OLV,OLV,MRN,OLV,OLV,OLV,FOR,FOR,GRY,FOR,OLV,
	};

	static char* TileMap[]
	{
		gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,
		gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,
		gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,
		gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,
		gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,
		gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,
		gt,gt,gt,gt,gt,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,sl,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,
		gt,gt,gt,gt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,sl,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,
		gt,gt,gt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,sl,gt,gt,gt,gt,gt,gt,gt,gt,gt,gt,
		gt,gt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,sl,gt,gt,gt,gt,gt,gt,gt,gt,gt,
		dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,
		dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,dt,
	};


	static char* GroundTiles[]{
		gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,gs,
	};

	Entity* MapEntity = new Entity();
	MapEntity->AddComponent<Sprite>()->SetTileSprite(TileMap, 32, 12, 16);

	ground = new Entity();
	ground->transform.position.y = -56;
	ground->AddComponent<Sprite>()->SetTileSprite(GroundTiles, 32, 1, 16);
	ground->AddComponent<Collider>()->SetUpSquare(0, 0, 32 * 16, 1 * 16);


	hground = new Entity();
	hground->transform.position.y = -40;
	hground->transform.position.x = 512;
	hground->AddComponent<Sprite>()->SetTileSprite(GroundTiles, 32, 1, 16);
	hground->AddComponent<Collider>()->SetUpSquare(0, 0, 32 * 16, 1 * 16);
	Addchild(MapEntity);
	Addchild(ground);
	Addchild(hground);


	bkgdcolor = NVY;
	//player->transform.position.x = 2 * TileSize;
	//player->transform.position.y = 3 * -TileSize;

	//AddSceneText("test", 800, 500, 10);
	gravity = -220.0f;
	player->velocity.y = 0.0f;
	this->Addchild(player);
	player->transform.position.y = -35;
	GetMainCamera()->position.y = player->transform.position.y + 29;
	//std::cout << sizeof(Sprite) << std::endl;;
}

void Floor::update(float deltaTime)
{
	if (player->GetComponent<Collider>()->isColliding(ground)) {
		player->velocity.y = 0.0f;
		player->transform.position.y = ground->transform.position.y + 20.0f;
		player->grounded = true;
	}
	else {
		player->grounded = false;
	}
	if (GetInput()->KeyPressed(KeyCode::Space) && player->grounded) {
		player->transform.position.y = ground->transform.position.y + 21.0f;
		player->velocity.y = 15000.0f * deltaTime;
	}
	if (player->GetComponent<Collider>()->isColliding(hground)) {
		player->velocity.y = 0.0f;
		if (player->transform.position.y - 13 < hground->transform.position.y + 7) {
			player->transform.position.x = player->oldpos.x;
		}
		else {
			std::cout << "above tile \n";
			player->transform.position.y = hground->transform.position.y + 20;
		}
		player->grounded = true;
	}
	player->transform.position.y += player->velocity.y * deltaTime;
	player->velocity.y += gravity * deltaTime;
	if (GetInput()->KeyPressed(KeyCode::Escape))
	{
		isRunning = false;
	}
	GetMainCamera()->position.x = player->transform.position.x;
}