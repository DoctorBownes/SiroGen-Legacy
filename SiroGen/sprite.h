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
    GLuint frame;
    std::vector<GLuint> sprites;

    int _height = 0;
    int _width = 0;

    void AddSprite(const char* TGA);
    void SetSprite(int number);
private:
};