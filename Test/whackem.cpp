#include "whackem.h"

Whackem::Whackem() : Scene()
{
	this->GetMainCamera()->SetZoom(20);
	this->joey = new Player();
	this->Addchild(joey);
	this->don = new Gangster();
	this->Addchild(don);
	this->dontoo = new Gangster();
	don->Addchild(dontoo);
	this->donthree = new Gangster();
	dontoo->Addchild(donthree);
	dontoo->transform->position->x = 10;
	donthree->transform->position->x = 20;
	don->transform->position->x = -40;
	bkgdcolor = 2;

	//for (int i = 0; i < 6; i++)
	//{
	//	this->don = new Gangster();
	//	mob.push_back(don);
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
	//AddSceneText("SiroGen", 700, 800, 10);
}

void Whackem::update(float deltaTime)
{
	//deltaTime = 0.0f;
	//for (int i = 0; i < mob.size(); i++)
	//{
	if (don != nullptr)
	{
		if (don->GetComponent<Collider>()->isColliding(joey) || donthree->GetComponent<Collider>()->isColliding(joey) || dontoo->GetComponent<Collider>()->isColliding(joey))
		{
			std::cout << "Colliding!" << std::endl;
			this->Removechild(don);
			don = nullptr;
		}
	}
		//mob[i]->GetComponent<Animation>()->PlayAnimation(mob[i]->drawAnim);
	//}
		//if (GetInput()->KeyPressed(KeyCode::R))
		//{
		//	this->Addchild(don);
		//}
	if (GetInput()->KeyPressed(KeyCode::Escape))
	{
		isRunning = false;
	}
}