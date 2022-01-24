#include "sprite.h"
#include <SiroGen/renderer.h>

Sprite::Sprite()
{
    vertex_buffer = 0;
    texture_buffer = 0;
    uv_buffer = 0;
    texture = new Texture();
    vertex_buffer_data = nullptr;
    uv_buffer_data = nullptr;
}

Sprite::~Sprite()
{
    delete texture;
}

void Sprite::SetSprite(const char* TGA)
{
    texture_buffer = texture->LoadTGAImage(TGA);
    vertex_buffer_data = new GLfloat[]{
        0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
       -0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
       -0.5f * texture->_width, -0.5f * texture->_height, 0.0f,

       -0.5f * texture->_width, -0.5f * texture->_height, 0.0f,
        0.5f * texture->_width, -0.5f * texture->_height, 0.0f,
        0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
    };
    uv_buffer_data = new GLfloat[]{
        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,

        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
    };
    GenerateSprite();
}

void Sprite::printText2D(const char* TGAfont, const char* text, int x, int y, int size)
{
    texture_buffer = texture->LoadTGAImage(TGAfont);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    int count = 0;
    for (int i = 0; text[i]; i++)
    {
        count++;
    }
    _count = count;
    for (int i = 0; i < count; i++)
    {
        vertex_buffer_vector.push_back(-0.5f * size + i * size);
        vertex_buffer_vector.push_back(0.5f * size);
        vertex_buffer_vector.push_back(0.0f);
        vertex_buffer_vector.push_back(0.5f * size + i * size);
        vertex_buffer_vector.push_back(0.5f * size);
        vertex_buffer_vector.push_back(0.0f);
        vertex_buffer_vector.push_back(0.5f * size + i * size);
        vertex_buffer_vector.push_back(-0.5f * size);
        vertex_buffer_vector.push_back(0.0f);

        vertex_buffer_vector.push_back(0.5f * size + i * size);
        vertex_buffer_vector.push_back(-0.5f * size);
        vertex_buffer_vector.push_back(0.0f);
        vertex_buffer_vector.push_back(-0.5f * size + i * size);
        vertex_buffer_vector.push_back(-0.5f * size);
        vertex_buffer_vector.push_back(0.0f);
        vertex_buffer_vector.push_back(-0.5f * size + i * size);
        vertex_buffer_vector.push_back(0.5f * size);
        vertex_buffer_vector.push_back(0.0f);

        char character = text[i];
        float uv_x = (character % 16) / 16.0f;
        float uv_y = (character / 16) / 8.0f;
        //H =     72
        //Xbegin =  -0.5f
        //Ybegin =  -0.25f
        //% 16 = 8

        //voor e = 101
        //Xbegin =  0.3125f
        //Ybegin =    -0.5f
        //% 16 = 5

        uv_buffer_vector.push_back(uv_x);
        uv_buffer_vector.push_back((1.0f - uv_y) + 0.25f);

        uv_buffer_vector.push_back(uv_x + 0.0625f);
        uv_buffer_vector.push_back((1.0f - uv_y) + 0.25f);

        uv_buffer_vector.push_back(uv_x + 0.0625f);
        uv_buffer_vector.push_back(1.0f - uv_y + 0.125f);

        uv_buffer_vector.push_back(uv_x + 0.0625f);
        uv_buffer_vector.push_back(1.0f - uv_y + 0.125f);

        uv_buffer_vector.push_back(uv_x);
        uv_buffer_vector.push_back(1.0f - uv_y + 0.125f);

        uv_buffer_vector.push_back(uv_x);
        uv_buffer_vector.push_back((1.0f - uv_y) + 0.25f);
    }
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, 72 * count, vertex_buffer_vector.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &uv_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
    glBufferData(GL_ARRAY_BUFFER, 48 * count, uv_buffer_vector.data(), GL_STATIC_DRAW);

}

void Sprite::SetSprite(char canvas[], char width, char height)
{
    texture_buffer = texture->LoadPixelImage(canvas, width, height);
    vertex_buffer_data = new GLfloat[]{
        -0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
         0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
         0.5f * texture->_width, -0.5f * texture->_height, 0.0f,

         0.5f * texture->_width, -0.5f * texture->_height, 0.0f,
        -0.5f * texture->_width, -0.5f * texture->_height, 0.0f,
        -0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
    };
    uv_buffer_data = new GLfloat[]{
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,

        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
    };
    GenerateSprite();
}

void Sprite::GenerateSprite()
{
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, 72, vertex_buffer_data, GL_STATIC_DRAW);

    glGenBuffers(1, &uv_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
    glBufferData(GL_ARRAY_BUFFER, 48, uv_buffer_data, GL_STATIC_DRAW);

    delete vertex_buffer_data;
    delete uv_buffer_data;
}

void Sprite::DoIt(GLuint shader)
{
    glBindTexture(GL_TEXTURE_2D, texture_buffer);

    GLuint vertexPositionID = glGetAttribLocation(shader, "vertexPosition");
    glEnableVertexAttribArray(vertexPositionID);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glVertexAttribPointer(
        vertexPositionID,   // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );
    // Draw the triangle !
    GLuint vertexUVID = glGetAttribLocation(shader, "vertexUV");
    glEnableVertexAttribArray(vertexUVID);
    glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
    glVertexAttribPointer(
        vertexUVID,                       // attribute. No particular reason for 1, but must match the layout in the shader.
        2,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );

    //glBindVertexArray(entity->GetComponent<Sprite>()->VertexArrayID);
    glDrawArrays(GL_TRIANGLES, 0, 6 * _count); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(vertexPositionID);
    glDisableVertexAttribArray(vertexUVID);
}