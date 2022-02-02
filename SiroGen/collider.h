#pragma once
#include <SiroGen/component.h>

class Collider :
    public Component
{
public:
    Collider();

    void SetUpCollider(bool square, float x, float y, float width, float height);
    bool isColliding(Collider* collider);
private:
    bool _issquare = 1;
    float _x = 0;
    float _y = 0;
    float _width = 0;
    float _height = 0;
    virtual void DoIt(unsigned int shader);
};