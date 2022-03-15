#include "whackem.h"

Whackem::Whackem() : Scene()
{
	this->GetMainCamera()->SetZoom(10);
	this->don = new Gangster();
	this->Addchild(don);
	this->joey = new Player();
	this->Addchild(joey);
	//for (int i = 0; i < 6; i++)
	//{
	//	mob[i] = new Gangster();
	//	mob[i]->AddComponent<Collider>()->SetUpSquare(0,0,8,16);
	//	mob[i]->target = joey;
	//	mob[i]->SetColor((i + 1) * 2);
	//	Addchild(mob[i]);
	//}
	//mob[0]->transform->position->x = -48;
	//mob[1]->transform->position->x = -32;
	//mob[2]->transform->position->x = -16;
	//mob[3]->transform->position->x = 16;
	//mob[4]->transform->position->x = 32;
	//mob[5]->transform->position->x = 48;
	//AddSceneText("hr@team6-games.com", 700, 800, 10);
}

void Whackem::update(float deltaTime)
{
	//for (int i = 0; i < mob.size(); i++)
	//{
	//	if (mob[i]->GetComponent<Collider>()->isColliding(joey))
	//	{
	//		this->DeleteChild(mob[i]);
	//		mob.erase(mob.begin() + i);
	//	}
	//	//mob[i]->GetComponent<Animation>()->PlayAnimation(mob[i]->drawAnim);
	//}
}