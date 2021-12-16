#include "pixelsprite.h"

PixelSprite::PixelSprite()
{
    _width = 0;
    _height = 0;
}

PixelSprite::~PixelSprite()
{

}

void PixelSprite::AddSprite(char canvas[], char width, char height)
{
    pixelCanvas = new std::vector<uint8_t>[width * height * 3];
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
    for (int i = 0; i < width * height; i++)
    {
        pixelCanvas->push_back(Palette[canvas[i]].r);
        pixelCanvas->push_back(Palette[canvas[i]].g);
        pixelCanvas->push_back(Palette[canvas[i]].b);
    }
    glGenTextures(1, &spritetexture);
    glBindTexture(GL_TEXTURE_2D, spritetexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelCanvas->data());
    glGenerateMipmap(GL_TEXTURE_2D);

    const GLfloat temp_vertex_buffer_data[] = {
        -0.5f * width,  0.5f * height, 0.0f,
       0.5f * width,  0.5f * height, 0.0f,
       0.5f * width, -0.5f * height, 0.0f,

       0.5f * width, -0.5f * height, 0.0f,
        -0.5f * width, -0.5f * height, 0.0f,
        -0.5f * width,  0.5f * height, 0.0f,
    };

    //sprite.LoadTGAImage(TGA);
    // Send vertices to GPU

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