#include "wackem.h"

Wackem::Wackem() : Scene()
{
	GetMainCamera()->SetZoom(10);
	joey = new Player();
	mob = std::vector<Gangster*>(5);
	for (int i = 0; i < mob.size(); i++)
	{
		mob[i] = new Gangster();
		Addchild(mob[i]);
	}
	mob[0]->transform->position->x = -48;
	mob[0]->SetColor(0x3);
	mob[1]->transform->position->x = -32;
	mob[1]->SetColor(0x9);
	mob[2]->transform->position->x = -16;
	mob[2]->SetColor(0x5);
	mob[3]->transform->position->x = 0;
	mob[3]->SetColor(0xd);
	mob[4]->transform->position->x = 16;
	mob[4]->SetColor(0xb);
	joey->transform->position->x = 32;
	//joey->transform->position->y = 32;
	//AddSceneText("Joey Spectrum", 420, 800, 10);
	Addchild(joey);
}

void Wackem::update(float deltaTime)
{
	mob[0]->transform->position->MoveTowards(*joey->transform->position, 5.0f * deltaTime);
}