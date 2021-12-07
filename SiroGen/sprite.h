#pragma once
#include "component.h"
#include "texture.h"
#include "transform.h"
class Sprite :
    public Component
{
public:
    Sprite();
    ~Sprite();

    //Texture GetTexture() { return spritetexture; };
    GLuint spritetexture;
    Texture sprite;

    void DrawSprite(const char* TGA);

private:

};

