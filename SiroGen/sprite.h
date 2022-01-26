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

    void SetSprite(const char* TGA);
    void SetSprite(char canvas[], char width, char height);

private:
    Texture* texture;
    GLfloat* vertex_buffer_data;
    GLfloat* uv_buffer_data;
    std::vector<GLfloat> vertex_buffer_vector;
    std::vector<GLfloat> uv_buffer_vector;
    int _count = 1;
    void GenerateSprite();
    virtual void DoIt(GLuint shader);

    GLuint texture_buffer;
    GLuint vertex_buffer;
    GLuint uv_buffer;

    int _height = 0;
    int _width = 0;
};