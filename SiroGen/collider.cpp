#include "collider.h"
#include <iostream>

Collider::Collider()
{
	SetUpCollider(true, 0, 0, 10, 10);
}

void Collider::SetUpCollider(bool square, float x, float y, float width, float height)
{
	_issquare = square;
	_x = x;
	_y = y;
	_width = width;
	_height = height;
}

bool Collider::isColliding(Collider* collider)
{
	if (collider->_issquare)
	{
		if (this->_x < collider->_x + collider->_width	&&
			this->_y < collider->_y + collider->_height	&&
			collider->_x < this->_x + this->_width		&&
			collider->_y < this->_y + this->_height		
			)
			{
				std::cout << "Colliding!" << std::endl;
				return true;
			}
			return false;
	}
}

void Collider::DoIt(unsigned int _shader)
{

}