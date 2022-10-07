#ifndef VECTOR2_H_
#define VECTOR2_H_
class Vector2
{
public:
	Vector2(float x = 0.0f, float y = 0.0f);
	Vector2 add(Vector2 vector);
	Vector2 sub(Vector2 vector);
	Vector2 mult(float mult);
	void Normalize();
	float DistanceBetween(Vector2 vector);
	void MoveTowards(Vector2 vector, float speed = 10.0f);
	virtual ~Vector2();
	float x = 0.0f;
	float y = 0.0f;
};

#endif
