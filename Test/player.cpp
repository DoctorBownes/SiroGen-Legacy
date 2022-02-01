#include "player.h"

Player::Player()
{
	Testnity* stupidname = new Testnity();
	Addchild(stupidname);
}

void Player::update(float deltaTime)
{
	if (GetInput()->KeyReleased(KeyCode::Y))
	{
		std::cout << "You pressed Y" << std::endl;
	}
}