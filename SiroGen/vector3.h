#pragma once
class Vector3
{
public:
	Vector3();
	Vector3(float x, float y);
	Vector3(float x, float y, float z);
	virtual ~Vector3();
	float x;
	float y;
	float z;
};

