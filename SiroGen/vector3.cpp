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

Vector3* Vector3::add(Vector3 vector)
{
	this->x += vector.x;
	this->y += vector.y;
	this->z += vector.z;
	return this;
}

Vector3* Vector3::mult(float mult)
{
	this->x *= mult;
	this->y *= mult;
	this->z *= mult;
	return this;
}

void Vector3::MoveTowards(Vector3 vector, float speed)
{
	Vector3* thisvector = new Vector3(vector.x, vector.y);
	Vector3* dir = thisvector->sub(*this);

	//normalize
	//std::cout << std::sqrt((dir->x * dir->x) + (dir->y * dir->y) + (dir->z * dir->z)) << std::endl;
	Normalize(dir);

	dir->mult(speed);
	this->add(*dir);
	delete thisvector;
}

void Vector3::Normalize(Vector3* vector)
{
	vector->x = vector->x / std::sqrtf((vector->x * vector->x) + (vector->y * vector->y) + (vector->z * vector->z) + 0.00001f);
	vector->y = vector->y / std::sqrtf((vector->x * vector->x) + (vector->y * vector->y) + (vector->z * vector->z) + 0.00001f);
	vector->z = vector->z / std::sqrtf((vector->x * vector->x) + (vector->y * vector->y) + (vector->z * vector->z) + 0.00001f);
}

Vector3* Vector3::sub(Vector3 vector)
{
	this->x -= vector.x;
	this->y -= vector.y;
	this->z -= vector.z;
	return this;
}
