#include <SiroGen/transform.h>

Transform::Transform()
{
	position = new Vector3();
	rotation = new Vector3();
	scale = new Vector3(1.0f,1.0f,1.0f);
}

Transform::~Transform()
{
	delete position;
	delete rotation;
	delete scale;
}
