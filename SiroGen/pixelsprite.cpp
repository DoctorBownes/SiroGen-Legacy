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
    char pixelCanvas[128 * 3];
    short p = 0;
    for (int i = 0; i < width * height; i++)
    {
        if (canvas[i] == 0)
        {
            glm::vec3 tempVec = glm::vec3(255, 255, 0);
            pixelCanvas[p] = tempVec[0];
            pixelCanvas[p + 1] = tempVec[1];
            pixelCanvas[p + 2] = tempVec[2];
        }
        else
        {
            glm::vec3 tempVec = glm::vec3(0, 0, 0);
            pixelCanvas[p] = tempVec[0];
            pixelCanvas[p + 1] = tempVec[1];
            pixelCanvas[p + 2] = tempVec[2];
        }
        p += 3;
    }
    glGenTextures(1, &spritetexture);
    glBindTexture(GL_TEXTURE_2D, spritetexture);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelCanvas);
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