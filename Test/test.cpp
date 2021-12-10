#include "test.h"

Test::Test() : Scene()
{
	Entity* guy = new Entity;
	guy->AddComponent<Sprite>()->DrawSprite("assets/bear.tga");
	guy->transform->position = new Vector3(0.0f, 0.0f, 0.0f);
	guy->transform->scale->x = 0.5f;

	Entity* guy2 = new Entity;
	guy2->AddComponent<Sprite>()->DrawSprite("assets/face.tga");
	guy2->transform->position = new Vector3(0.0f, 200.0f, 0.0f);

	this->Addchild(guy);
	this->Addchild(guy2);
}

void Test::update(float deltaTime)
{
	
}
