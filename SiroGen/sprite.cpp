#include "sprite.h"

Sprite::Sprite()
{
}

Sprite::~Sprite()
{

}

void Sprite::DrawSprite(const char* TGA)
{
    static const GLfloat temp_vertex_buffer_data[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f,

     0.5f,  0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    };
    sprite.LoadTGAImage(TGA);
    // Send vertices to GPU
    glGenBuffers(1, &spritetexture);
    glBindBuffer(GL_ARRAY_BUFFER, spritetexture);
    glBufferData(GL_ARRAY_BUFFER, sizeof(temp_vertex_buffer_data), temp_vertex_buffer_data, GL_STATIC_DRAW);

   // GLuint textureID;
   // glGenTextures(1, &textureID);
    //glBindTexture2D()
}

