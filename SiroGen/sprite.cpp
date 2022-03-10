#include "sprite.h"

Sprite::Sprite()
{
    _Owner = nullptr;
    vertex_buffer = 0;
    texture_buffer = 0;
    uv_buffer = 0;
    texture = nullptr;
   // GenerateSprite();
}

Sprite::Sprite(Entity* owner)
{
    _Owner = owner;
    vertex_buffer = 0;
    texture_buffer = 0;
    uv_buffer = 0;
    texture = nullptr;
    //GenerateSprite();
}

Sprite::~Sprite()
{
    //_instance->DeleteTexture(texture);
}

void Sprite::RemoveSprite()
{
    vertex_buffer_vector.clear();
    uv_buffer_vector.clear();
    GenerateSprite();
}

void Sprite::SetSprite(const char* TGA)
{
    texture = _instance->GetTexture(TGA);
    texture_buffer = texture->GetTexBuffer();
    vertex_buffer_vector.insert(vertex_buffer_vector.begin(), {
        -0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
         0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
         0.5f * texture->_width, -0.5f * texture->_height, 0.0f,

         0.5f * texture->_width, -0.5f * texture->_height, 0.0f,
        -0.5f * texture->_width, -0.5f * texture->_height, 0.0f,
        -0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
        });
    uv_buffer_vector.insert(uv_buffer_vector.begin(), {
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,

        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
        });
    GenerateSprite();
}

void Sprite::SetSprite(char* canvas, char width, char height)
{
    texture = _instance->GetTexture(canvas,width,height);
    texture_buffer = texture->GetTexBuffer();
    vertex_buffer_vector.insert(vertex_buffer_vector.begin(), {
        -0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
         0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
         0.5f * texture->_width, -0.5f * texture->_height, 0.0f,

         0.5f * texture->_width, -0.5f * texture->_height, 0.0f,
        -0.5f * texture->_width, -0.5f * texture->_height, 0.0f,
        -0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
    });
    uv_buffer_vector.insert(uv_buffer_vector.begin(),{
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,

        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
    });
    GenerateSprite();
}

void Sprite::GenerateSprite()
{
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_buffer_vector.size() * 4, vertex_buffer_vector.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &uv_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
    glBufferData(GL_ARRAY_BUFFER, uv_buffer_vector.size() * 4, uv_buffer_vector.data(), GL_STATIC_DRAW);
}

void Sprite::DoIt(GLuint shader)
{
    GLuint ColorID = glGetUniformLocation(shader, "blendColor");
    glUniform4f(ColorID, texture->Palette[blendColor + 1 - blendColor % 2].r / 255.0f, texture->Palette[blendColor + 1 - blendColor % 2].g / 255.0f, texture->Palette[blendColor + 1 - blendColor % 2].b / 255.0f, 1.0f);
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
    glDrawArrays(GL_TRIANGLES, 0, uv_buffer_vector.size() / 2); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(vertexPositionID);
    glDisableVertexAttribArray(vertexUVID);
    glDisableVertexAttribArray(ColorID);
}