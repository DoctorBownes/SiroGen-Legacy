#include "collider.h"
#include <iostream>

//Collider::Collider()
//{
//	_Owner = nullptr;
//}

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

bool Collider::isColliding(Entity* collider)
{
	Collider* tempcollider = collider->GetComponent<Collider>();
	if (tempcollider != nullptr && _Owner->Parent != nullptr && collider->Parent != nullptr)
	{
		if (this->_issquare && tempcollider->_issquare)
		{
			return square2square(tempcollider);
		}
		else if (!this->_issquare && !tempcollider->_issquare)
		{
			return circle2circle(tempcollider);
		}
		else if (this->_issquare && !tempcollider->_issquare)
		{
			return circle2square(tempcollider, this);
		}
		else
		{
			return circle2square(this, tempcollider);
		}
	}
	return false;
}

bool Collider::square2square(Collider* collider)
{
	if (	this->_Owner->worldtransform->position->x + this->_x - this->_width /2.0f	<	collider->_Owner->worldtransform->position->x + collider->_x + collider->_width	/2.0f	&&
			this->_Owner->worldtransform->position->y + this->_y - this->_height / 2.0f <	collider->_Owner->worldtransform->position->y + collider->_y + collider->_height /2.0f	&&
		collider->_Owner->worldtransform->position->x + collider->_x - collider->_width / 2.0f <		this->_Owner->worldtransform->position->x + this->_x + this->_width / 2.0f &&
		collider->_Owner->worldtransform->position->y + collider->_y - collider->_height / 2.0f <		this->_Owner->worldtransform->position->y + this->_y + this->_height / 2.0f
		)
	{
		return true;
	}
	return false;
}

bool Collider::circle2square(Collider* circle, Collider* square)
{
	float testx = circle->_Owner->worldtransform->position->x + circle->_x;
	float testy = circle->_Owner->worldtransform->position->y + circle->_y;
	if (circle->_Owner->worldtransform->position->x + circle->_x < square->_Owner->worldtransform->position->x + square->_x - square->_width / 2.0f){
		testx = square->_Owner->worldtransform->position->x + square->_x - square->_width / 2.0f;
	}
	else if (circle->_Owner->worldtransform->position->x + circle->_x > square->_Owner->worldtransform->position->x + square->_x + square->_width /2.0F){
		testx = square->_Owner->worldtransform->position->x + square->_x + square->_width /2.0f;
	}

	if (circle->_Owner->worldtransform->position->y + circle->_y < square->_Owner->worldtransform->position->y + square->_y - square->_height / 2.0f) {
		testy = square->_Owner->worldtransform->position->y + square->_y - square->_height / 2.0f;
	}
	else if (circle->_Owner->worldtransform->position->y + circle->_y > square->_Owner->worldtransform->position->y + square->_y + square->_height /2.0f) {
		testy = square->_Owner->worldtransform->position->y + square->_y + square->_height / 2.0f;
	}

	float distx = circle->_Owner->worldtransform->position->x + circle->_x - testx;
	float disty = circle->_Owner->worldtransform->position->y + circle->_y - testy;
	float distance = std::sqrt((distx * distx) + (disty * disty));
	if (distance < circle->_diameter /2.0f)
	{
		return true;
	}
	return false;
}

bool Collider::circle2circle(Collider* collider)
{
	float distx = this->_Owner->worldtransform->position->x + this->_x - collider->_Owner->worldtransform->position->x + collider->_x;
	float disty = this->_Owner->worldtransform->position->y + this->_y - collider->_Owner->worldtransform->position->y + collider->_y;
	float distance = std::sqrt((distx * distx) + (disty * disty));
	if (distance < this->_diameter /2.0f + collider->_diameter /2.0f)
	{
		return true;
	}
	return false;
}

void Collider::DoIt(unsigned int _shader)
{
	_shader = 0;
}