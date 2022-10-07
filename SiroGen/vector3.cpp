#include "Vector3.h"
#include <cmath>

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{

}

Vector2 Vector2::add(Vector2 vector)
{
	this->x += vector.x;
	this->y += vector.y;
	return *this;
}

Vector2 Vector2::mult(float mult)
{
	this->x *= mult;
	this->y *= mult;
	return *this;
}

void Vector2::MoveTowards(Vector2 vector, float speed)
{
	Vector2 thisvector = Vector2(vector.x, vector.y);
	Vector2 dir = thisvector.sub(*this);

	//normalize
	//std::cout << std::sqrt((dir->x * dir->x) + (dir->y * dir->y) + (dir->z * dir->z)) << std::endl;
	dir.Normalize();

	dir.mult(speed);
	this->add(dir);
}

float Vector2::DistanceBetween(Vector2 vector)
{
	float nx = this->x - vector.x;
	float ny = this->y - vector.y;
	return std::sqrt((nx * nx) + (ny * ny));
}

void Vector2::Normalize()
{
	this->x = this->x / std::sqrt((this->x * this->x) + (this->y * this->y) + 0.00001f);
	this->y = this->y / std::sqrt((this->x * this->x) + (this->y * this->y) + 0.00001f);
}

Vector2 Vector2::sub(Vector2 vector)
{
	this->x -= vector.x;
	this->y -= vector.y;
	return *this;
}
