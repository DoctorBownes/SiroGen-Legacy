#include "shootout.h"
#include <sstream>

ShootOut::ShootOut() : Scene()
{
	this->GetMainCamera()->SetZoom(10);

	player1->SetColor(5);
	player1->transform->position->x = 30;
	player1->transform->rotation->y = 180;
	this->Addchild(player1);

	player2->SetColor(9);
	player2->transform->position->x = -30;
	player1->direction = -1;
	this->Addchild(player2);

	bkgdcolor = 3;

	speed = 20;
	AddSceneText("Player1: 0", 1400, 950, 6, 5);
	AddSceneText("Player2: 0", 100, 950, 6, 9);
	AddSceneText("ShootOut", 650, 950, 10);
}

void ShootOut::update(float deltaTime)
{
	if (GetInput()->KeyDown(KeyCode::Left))
	{
		player1->walkAnim->hasPriority = true;
		player1->GetComponent<Animation>()->PlayAnimation(player1->walkAnim, true, 1, 2);
		player1->transform->position->x -= speed * deltaTime;
	}
	else if (GetInput()->KeyDown(KeyCode::Right))
	{
		player1->walkAnim->hasPriority = true;
		player1->GetComponent<Animation>()->PlayAnimation(player1->walkAnim, true, 1, 2);
		player1->transform->position->x += speed * deltaTime;
	}
	else if (GetInput()->KeyDown(KeyCode::Up))
	{
		player1->walkAnim->hasPriority = true;
		player1->GetComponent<Animation>()->PlayAnimation(player1->walkAnim, true, 1, 2);
		player1->transform->position->y += speed * deltaTime;
	}
	else if (GetInput()->KeyDown(KeyCode::Down))
	{
		player1->walkAnim->hasPriority = true;
		player1->GetComponent<Animation>()->PlayAnimation(player1->walkAnim, true, 1, 2);
		player1->transform->position->y -= speed * deltaTime;
	}
	else
	{
		player1->GetComponent<Animation>()->PlayAnimation(player1->walkAnim, true, 0, 0);
	}
	if (GetInput()->KeyPressed(KeyCode::Enter))
	{
		player1->Shoot();
	}


	if (GetInput()->KeyDown(KeyCode::A))
	{
		player2->walkAnim->hasPriority = true;
		player2->GetComponent<Animation>()->PlayAnimation(player2->walkAnim, true, 1, 2);
		player2->transform->position->x -= speed * deltaTime;
	}
	else if (GetInput()->KeyDown(KeyCode::D))
	{
		player2->walkAnim->hasPriority = true;
		player2->GetComponent<Animation>()->PlayAnimation(player2->walkAnim, true, 1, 2);
		player2->transform->position->x += speed * deltaTime;
	}
	else if (GetInput()->KeyDown(KeyCode::W))
	{
		player2->walkAnim->hasPriority = true;
		player2->GetComponent<Animation>()->PlayAnimation(player2->walkAnim, true, 1, 2);
		player2->transform->position->y += speed * deltaTime;
	}
	else if (GetInput()->KeyDown(KeyCode::S))
	{
		player2->walkAnim->hasPriority = true;
		player2->GetComponent<Animation>()->PlayAnimation(player2->walkAnim, true, 1, 2);
		player2->transform->position->y -= speed * deltaTime;
	}
	else
	{
		player2->GetComponent<Animation>()->PlayAnimation(player2->walkAnim, true, 0, 0);
	}
	if (GetInput()->KeyPressed(KeyCode::Space))
	{
		player2->Shoot();
	}

	if (player2->bullet->GetComponent<Collider>()->isColliding(player1))
	{
		player1->score--;
		Removechild(player2->bullet);
	}
	else if (player1->bullet->GetComponent<Collider>()->isColliding(player2))
	{
		player2->score--;
		Removechild(player1->bullet);
	}

	std::stringstream scoreplayer1;
	scoreplayer1 << "Lives: " << player1->score;
	EditSceneText(scoreplayer1.str(), 0);

	std::stringstream scoreplayer2;
	scoreplayer2 << "Lives: " << player2->score;
	EditSceneText(scoreplayer2.str(), 1);
}