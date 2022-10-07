#ifndef TRANSFORM_H_
#define TRANSFORM_H_
#include <SiroGen/vector3.h>

class Transform
{
public:
	Transform();
	~Transform();
	Vector2 position;
	Vector2 rotation;
	Vector2 scale;
};

#endif
