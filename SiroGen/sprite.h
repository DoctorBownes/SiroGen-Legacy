#pragma once
#include "component.h"
#include "texture.h"
#include <vector>
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
    int _height = 0;
    int _width = 0;
    //std::vector<GLuint> sprites;

    void AddSprite(const char* TGA);

private:
};

