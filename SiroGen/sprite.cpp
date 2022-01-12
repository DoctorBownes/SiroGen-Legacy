#include "sprite.h"
#include <SiroGen/renderer.h>

Sprite::Sprite()
{
    sprite = 0;
    spritetexture = 0;
    uv = 0;
    frame = 0;
}

Sprite::~Sprite()
{

}

void Sprite::AddSprite(const char* TGA)
{
    Texture* texture = new Texture();
    spritetexture = texture->LoadTGAImage(TGA);
    const GLfloat temp_vertex_buffer_data[] = {
        0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
       -0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
       -0.5f * texture->_width, -0.5f * texture->_height, 0.0f,
                                               
       -0.5f * texture->_width, -0.5f * texture->_height, 0.0f,
        0.5f * texture->_width, -0.5f * texture->_height, 0.0f,
        0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
    };

    sprites.push_back(spritetexture);
    
    static const GLfloat temp_uv_buffer_data[] = {
        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,

        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
    };

    glGenBuffers(1, &sprite);
    glBindBuffer(GL_ARRAY_BUFFER, sprite);
    glBufferData(GL_ARRAY_BUFFER, sizeof(temp_vertex_buffer_data), temp_vertex_buffer_data, GL_STATIC_DRAW);

    glGenBuffers(1, &uv);
    glBindBuffer(GL_ARRAY_BUFFER, uv);
    glBufferData(GL_ARRAY_BUFFER, sizeof(temp_uv_buffer_data), temp_uv_buffer_data, GL_STATIC_DRAW);
    SetSprite(0);

    delete texture;
}

void Sprite::SetSprite(int number)
{
    frame = sprites.at(number);
}

void Sprite::DoIt(GLuint shader)
{
    glBindTexture(GL_TEXTURE_2D, frame);

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