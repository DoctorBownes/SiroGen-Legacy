#ifndef COLLIDER_H_
#define COLLIDER_H_
#include <SiroGen/component.h>
#include <SiroGen/entity.h>

class Collider :
    public Component
{
public:
    Collider(Entity* owner);

    void SetUpSquare(float x, float y, float width, float height);
    void SetUpCircle(float x, float y, float diameter);
    bool isColliding(Collider* collider);
    bool square2square(Collider* collider);
    bool square2circle(Collider* collider);
    bool circle2circle(Collider* collider);
private:
    bool _issquare = 1;
    float _x = 0.0f;
    float _y = 0.0f;
    float _width = 0.0f;
    float _height = 0.0f;
    float _diameter = 0.0f;
    virtual void DoIt(unsigned int shader);
};
#endif