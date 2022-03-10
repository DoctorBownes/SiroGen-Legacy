#include "whackem.h"

Whackem::Whackem() : Scene()
{
	GetMainCamera()->SetZoom(10);
	mob = std::vector<Gangster*>(4);
	joey = new Player();
	joey->transform->position->x = 32;
	Addchild(joey);
	for (int i = 0; i < mob.size(); i++)
	{
		mob[i] = new Gangster();
		mob[i]->AddComponent<Collider>()->SetUpSquare(0,0,8,16);
		mob[i]->target = joey;
		Addchild(mob[i]);
	}
	mob[0]->transform->position->x = -48;
	mob[0]->SetColor(0x9);
	mob[1]->transform->position->x = -32;
	mob[1]->SetColor(0x5);
	mob[2]->transform->position->x = -16;
	mob[2]->SetColor(0x3);
	mob[3]->transform->position->x = 0;
	mob[3]->SetColor(0xd);
	//mob[4]->transform->position->x = 16;
	//mob[4]->SetColor(0xb);
	joey->transform->position->y = 32;
	//AddSceneText("Joey Spectrum", 420, 800, 10);
}

void Whackem::update(float deltaTime)
{
	for (int i = 0; i < mob.size(); i++)
	{
		if (mob[i]->GetComponent<Collider>()->isColliding(joey))
		{
			this->DeleteChild(mob[i]);
			mob.erase(mob.begin() + i);
		}
		//mob[i]->GetComponent<Animation>()->PlayAnimation(mob[i]->drawAnim);
	}
}