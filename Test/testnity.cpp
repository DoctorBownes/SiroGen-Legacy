#include "testnity.h"

Testnity::Testnity()
{
}

void Testnity::update(float deltaTime)
{
	if (GetInput()->KeyReleased(KeyCode::Y))
	{
		std::cout << "You pressed B" << std::endl;
	}
}