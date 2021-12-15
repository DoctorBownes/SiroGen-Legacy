#include "test.h"

Test::Test() : Scene()
{
	char canvas[]
	{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,1,0,0,1,0,0,
		0,0,0,0,0,0,0,0,
		0,1,0,0,0,0,1,0,
		0,0,1,1,1,1,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	};

	Entity* guy = new Entity;
	guy->AddComponent<PixelSprite>()->AddSprite(canvas,8,8);
	guy->transform->position = new Vector3(0.0f, 0.0f, 0.0f);
	guy->transform->scale->x = 30;
	guy->transform->scale->y = 30;

	Entity* guy2 = new Entity;
	guy2->AddComponent<Sprite>()->AddSprite("assets/pencils.tga");
	guy2->transform->position = new Vector3(0.0f, 200.0f, 0.0f);

	this->Addchild(guy);
	this->Addchild(guy2);
}

void Test::update(float deltaTime)
{
	
}
