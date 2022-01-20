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
    void printText2D(const char* TGAfont, const char* text, int x, int y, int size);

private:
    Texture* texture;
    const GLfloat* vertex_buffer_data;
    const GLfloat* uv_buffer_data;
    std::vector<const GLfloat*> vertex_buffer_vector;
    std::vector<const GLfloat*> uv_buffer_vector;
    void GenerateSprite();
    virtual void DoIt(GLuint shader);

    GLuint texture_buffer;
    GLuint vertex_buffer;
    GLuint uv_buffer;

    int _height = 0;
    int _width = 0;
};