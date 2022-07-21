#ifndef TRANSFORM_H_
#define TRANSFORM_H_
#include <SiroGen/vector3.h>

class Transform
{
public:
	Transform();
	~Transform();
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;
};

#endif
