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
    GLuint sprite;
    GLuint spritetexture;
    GLuint uv;
    Texture texture;

    void DrawSprite(const char* TGA);

private:

};

