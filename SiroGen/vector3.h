#ifndef VECTOR3_H_
#define VECTOR3_H_
#include <cmath>
class Vector3
{
public:
	Vector3();
	Vector3(float x, float y);
	Vector3(float x, float y, float z);
	Vector3* add(Vector3* vector);
	Vector3* sub(Vector3* vector);
	Vector3* mult(float mult);
	void Normalize();
	float DistanceBetween(Vector3* vector);
	void MoveTowards(Vector3* vector, float speed = 10.0f);
	virtual ~Vector3();
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

#endif
