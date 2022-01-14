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

    void AddSprite(const char* TGA);
    void AddSprite(char canvas[], char width, char height);

    void SetSprite(int number);
private:
    Texture* texture;
    const GLfloat* vertex_buffer_data;
    const GLfloat* uv_buffer_data;
    bool dynamic = 0;
    void GenerateSprite();
    virtual void DoIt(GLuint shader);

protected:
    GLuint sprite;
    GLuint spritetexture;
    GLuint uv;
    GLuint frame;
    std::vector<GLuint> sprites;

    int _height = 0;
    int _width = 0;
};