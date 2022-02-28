#include "wackem.h"

Wackem::Wackem() : Scene()
{
	GetMainCamera()->SetZoom(10);
	joey = new Player();
	std::vector<Gangster*> mob = std::vector<Gangster*>(2);
	for (int i = 0; i < mob.size(); i++)
	{
		mob[i] = new Gangster();
		Addchild(mob[i]);
	}
	mob[1]->transform->position->x = 16;
	Addchild(joey);
}

void Wackem::update(float deltaTime)
{
}