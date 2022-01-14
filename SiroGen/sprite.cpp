#include "sprite.h"
#include <SiroGen/renderer.h>

Sprite::Sprite()
{
    sprite = 0;
    spritetexture = 0;
    uv = 0;
    frame = 0;
    texture = new Texture();
    vertex_buffer_data = nullptr;
    uv_buffer_data = nullptr;
}

Sprite::~Sprite()
{
    delete texture;
}

void Sprite::AddSprite(const char* TGA)
{
    spritetexture = texture->LoadTGAImage(TGA);
    dynamic = false;
    GenerateSprite();
}

void Sprite::AddSprite(char canvas[], char width, char height)
{
    spritetexture = texture->LoadPixelImage(canvas, width, height);
    dynamic = true;
    GenerateSprite();
}

void Sprite::GenerateSprite()
{
    sprites.push_back(spritetexture);
    if (dynamic)
    {
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
    }
    else
    {
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
    }
    glGenBuffers(1, &sprite);
    glBindBuffer(GL_ARRAY_BUFFER, sprite);
    glBufferData(GL_ARRAY_BUFFER, 72, vertex_buffer_data, GL_STATIC_DRAW);

    glGenBuffers(1, &uv);
    glBindBuffer(GL_ARRAY_BUFFER, uv);
    glBufferData(GL_ARRAY_BUFFER, 48, uv_buffer_data, GL_STATIC_DRAW);

    delete vertex_buffer_data;
    delete uv_buffer_data;
}

void Sprite::SetSprite(int number)
{
    frame = sprites.at(number);
}

void Sprite::DoIt(GLuint shader)
{
    glBindTexture(GL_TEXTURE_2D, spritetexture);

    GLuint vertexPositionID = glGetAttribLocation(shader, "vertexPosition");
    glEnableVertexAttribArray(vertexPositionID);
    glBindBuffer(GL_ARRAY_BUFFER, sprite);
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
    glBindBuffer(GL_ARRAY_BUFFER, uv);
    glVertexAttribPointer(
        vertexUVID,                       // attribute. No particular reason for 1, but must match the layout in the shader.
        2,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );

    //glBindVertexArray(entity->GetComponent<Sprite>()->VertexArrayID);
    glDrawArrays(GL_TRIANGLES, 0, 6); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(vertexPositionID);
    glDisableVertexAttribArray(vertexUVID);
}