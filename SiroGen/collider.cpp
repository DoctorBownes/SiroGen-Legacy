#include "collider.h"
#include <iostream>

Collider::Collider(Entity* owner)
{
	_Owner = owner;
}

void Collider::SetUpSquare(float x, float y, float width, float height)
{
	_issquare = true;
	_x = x;
	_y = y;
	_width = width;
	_height = height;
}

void Collider::SetUpCircle(float x, float y, float diameter)
{
	_issquare = false;
	_x = x;
	_y = y;
	_diameter = diameter;
}

bool Collider::isColliding(Collider* collider)
{
	if (this->_issquare && collider->_issquare)
	{
		return square2square(collider);
	}
	else if (!this->_issquare && !collider->_issquare)
	{
		return circle2circle(collider);
	}
	return square2circle(collider);
}

bool Collider::square2square(Collider* collider)
{
	if (	this->_Owner->transform->position->x + this->_x - this->_width /2.0f	<	collider->_Owner->transform->position->x + collider->_x + collider->_width	/2.0f	&&
			this->_Owner->transform->position->y + this->_y - this->_height / 2.0f <	collider->_Owner->transform->position->y + collider->_y + collider->_height /2.0f	&&
		collider->_Owner->transform->position->x + collider->_x - collider->_width / 2.0f <		this->_Owner->transform->position->x + this->_x + this->_width / 2.0f &&
		collider->_Owner->transform->position->y + collider->_y - collider->_height / 2.0f <		this->_Owner->transform->position->y + this->_y + this->_height / 2.0f
		)
	{
		return true;
	}
	return false;
}

bool Collider::square2circle(Collider* collider)
{
	float testx = this->_Owner->transform->position->x + this->_x;
	float testy = this->_Owner->transform->position->y + this->_y;
	if (this->_Owner->transform->position->x + this->_x < collider->_Owner->transform->position->x + collider->_x - collider->_width / 2.0f){
		testx = collider->_Owner->transform->position->x + collider->_x - collider->_width / 2.0f;
	}
	else if (this->_Owner->transform->position->x + this->_x > collider->_Owner->transform->position->x + collider->_x + collider->_width /2.0F){
		testx = collider->_Owner->transform->position->x + collider->_x + collider->_width /2.0f;
	}

	if (this->_Owner->transform->position->y + this->_y < collider->_Owner->transform->position->y + collider->_y - collider->_height / 2.0f) {
		testy = collider->_Owner->transform->position->y + collider->_y - collider->_height / 2.0f;
	}
	else if (this->_Owner->transform->position->y + this->_y > collider->_Owner->transform->position->y + collider->_y + collider->_height /2.0f) {
		testy = collider->_Owner->transform->position->y + collider->_y + collider->_height / 2.0f;
	}

	float distx = this->_Owner->transform->position->x + this->_x - testx;
	float disty = this->_Owner->transform->position->y + this->_y - testy;
	float distance = std::sqrt((distx * distx) + (disty * disty));
	if (distance < this->_diameter /2.0f)
	{
		return true;
	}
	return false;
}

bool Collider::circle2circle(Collider* collider)
{
	float distx = this->_Owner->transform->position->x + this->_x - collider->_Owner->transform->position->x + collider->_x;
	float disty = this->_Owner->transform->position->y + this->_y - collider->_Owner->transform->position->y + collider->_y;
	float distance = std::sqrt((distx * distx) + (disty * disty));
	if (distance < this->_diameter /2.0f + collider->_diameter /2.0f)
	{
		return true;
	}
	return false;
}

void Collider::DoIt(unsigned int _shader)
{

}