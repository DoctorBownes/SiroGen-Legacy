#pragma once
#include <cmath>
class Vector3
{
public:
	Vector3();
	Vector3(float x, float y);
	Vector3(float x, float y, float z);
	Vector3* add(Vector3 vector);
	Vector3* sub(Vector3 vector);
	Vector3* mult(float mult);
	void Normalize(Vector3* vector);
	void MoveTowards(Vector3 vector, float speed = 10.0f);
	virtual ~Vector3();
	float x;
	float y;
	float z;
};

