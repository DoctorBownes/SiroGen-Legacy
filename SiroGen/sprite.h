#pragma once
#include "component.h"
#include "texture.h"
#include <vector>
#include <SiroGen/animation.h>
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
    //std::vector<GLuint> sprites;

    void AddSprite(const char* TGA);
    void SetSprite(int number);
    //bool PlayAnimation(Animation animation, bool loop = true);
private:
};

