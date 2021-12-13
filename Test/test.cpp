#include "test.h"

Test::Test() : Scene()
{
	char canvas[54]
	{
		1,1,1,1,1,1,1,1,1,
		1,1,2,1,1,1,2,1,1,
		1,1,1,1,1,1,1,1,1,
		1,2,1,1,1,1,1,2,1,
		1,1,2,2,2,2,2,1,1,
		1,1,1,1,1,1,1,1,1,
	};
	Entity* guy = new Entity;
	guy->AddComponent<PixelSprite>()->AddSprite(canvas, 9,10);
	guy->transform->position = new Vector3(0.0f, 0.0f, 0.0f);

	//Entity* guy2 = new Entity;
	//guy2->AddComponent<Sprite>()->AddSprite("assets/pencils.tga");
	//guy2->transform->position = new Vector3(0.0f, 200.0f, 0.0f);
	//AddSprite(canvas, 9, 10);

	this->Addchild(guy);
	//this->Addchild(guy2);
}

void Test::update(float deltaTime)
{
	
}
