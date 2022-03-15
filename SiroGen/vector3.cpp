#include "vector3.h"
#include <iostream>

Vector3::Vector3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3::Vector3(float x, float y)
{
	this->x = x;
	this->y = y;
	this->z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{

}

Vector3* Vector3::add(Vector3* vector)
{
	this->x += vector->x;
	this->y += vector->y;
	this->z += vector->z;
	return this;
}

Vector3* Vector3::mult(float mult)
{
	this->x *= mult;
	this->y *= mult;
	this->z *= mult;
	return this;
}

void Vector3::MoveTowards(Vector3* vector, float speed)
{
	Vector3* thisvector = new Vector3(vector->x, vector->y);
	Vector3* dir = thisvector->sub(this);

	//normalize
	//std::cout << std::sqrt((dir->x * dir->x) + (dir->y * dir->y) + (dir->z * dir->z)) << std::endl;
	dir->Normalize();

	dir->mult(speed);
	this->add(dir);
	delete thisvector;
}

float Vector3::DistanceBetween(Vector3* vector)
{
	float nx = this->x - vector->x;
	float ny = this->y - vector->y;
	return std::sqrt((nx * nx) + (ny * ny));
}

void Vector3::Normalize()
{
	this->x = this->x / std::sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z) + 0.00001f);
	this->y = this->y / std::sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z) + 0.00001f);
	this->z = this->z / std::sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z) + 0.00001f);
}

Vector3* Vector3::sub(Vector3* vector)
{
	this->x -= vector->x;
	this->y -= vector->y;
	this->z -= vector->z;
	return this;
}
