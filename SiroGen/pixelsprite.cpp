#include "pixelsprite.h"

PixelSprite::PixelSprite()
{
    spritetexture = 0;
    sprite = 0;
    uv = 0;
    _width = 0;
    _height = 0;
}

PixelSprite::~PixelSprite()
{
    glDeleteTextures(1, &spritetexture);
}

void PixelSprite::AddSprite(char canvas[], char width, char height)
{
    pixelCanvas = new std::vector<char>[width * height * 3];
    _width = width;
    _height = height;
    Color Palette[15] =
    {
        BLACK,
        DARKBLUE,
        BLUE,
        DARKRED,
        RED,
        DARKMAGENTA,
        MAGENTA,
        DARKGREEN,
        GREEN,
        DARKCYAN,
        CYAN,
        DARKYELLOW,
        YELLOW,
        GRAY,
        WHITE
    };
    for (int i = 0; i < _width * _height; i++)
    {
        pixelCanvas->push_back(Palette[canvas[i]].r);
        pixelCanvas->push_back(Palette[canvas[i]].g);
        pixelCanvas->push_back(Palette[canvas[i]].b);
    }

    GLuint testtexture;
    glGenTextures(1, &testtexture);
    glBindTexture(GL_TEXTURE_2D, testtexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelCanvas->data());
    glGenerateMipmap(GL_TEXTURE_2D);

    const GLfloat temp_vertex_buffer_data[] = {
      -0.5f * _width,  0.5f * _height, 0.0f,
       0.5f * _width,  0.5f * _height, 0.0f,
       0.5f * _width, -0.5f * _height, 0.0f,
                              
       0.5f * _width, -0.5f * _height, 0.0f,
      -0.5f * _width, -0.5f * _height, 0.0f,
      -0.5f * _width,  0.5f * _height, 0.0f,
    };

    static const GLfloat temp_uv_buffer_data[] = {
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        
        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
    };


    glGenBuffers(1, &sprite);
    glBindBuffer(GL_ARRAY_BUFFER, sprite);
    glBufferData(GL_ARRAY_BUFFER, sizeof(temp_vertex_buffer_data), temp_vertex_buffer_data, GL_STATIC_DRAW);

    glGenBuffers(1, &uv);
    glBindBuffer(GL_ARRAY_BUFFER, uv);
    glBufferData(GL_ARRAY_BUFFER, sizeof(temp_uv_buffer_data), temp_uv_buffer_data, GL_STATIC_DRAW);

}