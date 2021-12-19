#include "pixelsprite.h"

void PixelSprite::AddSprite(char canvas[], char width, char height)
{
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
    std::vector<char>* pixelCanvas = new std::vector<char>[width * height * 3];
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

    delete[]pixelCanvas;

    const GLfloat temp_vertex_buffer_data[] = {
      -0.5f * width,  0.5f * height, 0.0f,
       0.5f * width,  0.5f * height, 0.0f,
       0.5f * width, -0.5f * height, 0.0f,
                             
       0.5f * width, -0.5f * height, 0.0f,
      -0.5f * width, -0.5f * height, 0.0f,
      -0.5f * width,  0.5f * height, 0.0f,
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