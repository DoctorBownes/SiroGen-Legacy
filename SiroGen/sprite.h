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

    void AddSprite(const char* TGA);
    void AddSprite(char canvas[], char width, char height);

private:
    Texture* texture;
    const GLfloat* vertex_buffer_data;
    const GLfloat* uv_buffer_data;
    void GenerateSprite();
    virtual void DoIt(GLuint shader);

    GLuint texture_buffer;
    GLuint vertex_buffer;
    GLuint uv_buffer;

    int _height = 0;
    int _width = 0;
};