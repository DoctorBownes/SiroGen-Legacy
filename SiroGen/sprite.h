#pragma once
#include "component.h"
#include "texture.h"
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
    //GLuint VertexArrayID;

    void AddSprite(const char* TGA);

private:

};

