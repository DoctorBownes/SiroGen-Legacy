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
    GLuint ColorID = glGetUniformLocation(shader, "blendColor");
    glUniform4f(ColorID, 1.0f, 1.0f, 1.0f, 1.0f);
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