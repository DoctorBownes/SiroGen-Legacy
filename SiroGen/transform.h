#pragma once
#include <SiroGen/vector3.h>

class Transform
{
public:
	Transform();
	~Transform();
	Vector3* position = nullptr;
	Vector3* rotation = nullptr;
	Vector3* scale = nullptr;
};

