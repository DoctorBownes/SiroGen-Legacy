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
    bool isColliding(Entity* collider);
private:
    bool _issquare = 1;
    float _x = 0.0f;
    float _y = 0.0f;
    float _width = 0.0f;
    float _height = 0.0f;
    float _diameter = 0.0f;
    virtual void DoIt(unsigned int shader);
    bool square2square(Collider* collider);
    bool circle2square(Collider* circle, Collider* square);
    bool circle2circle(Collider* collider);
};

#endif
