#include "collider.h"
#include <iostream>

Collider::Collider(Entity* owner)
{
	_Owner = owner;
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
		if (this->_Owner->transform->position->x < collider->_Owner->transform->position->x + collider->_width / 2.0f &&
			this->_Owner->transform->position->y < collider->_Owner->transform->position->y + collider->_height / 2.0f &&
			collider->_Owner->transform->position->x - collider->_width / 2.0f + 10.0f < this->_Owner->transform->position->x + this->_width &&
			collider->_Owner->transform->position->y - collider->_height / 2.0f + 10.0f < this->_Owner->transform->position->y + this->_height
			)
			{
				return true;
			}
			return false;
	}
	else
	{

	}
}

void Collider::DoIt(unsigned int _shader)
{

}