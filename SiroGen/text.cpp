#include "text.h"

void Text::initText2D(const char* texturePath)
{

}

void Text::printText2D(const char* text, float x, float y, float size, uint8_t Color, const char* TGAfont)
{
    _texture = new Texture();
    texture_buffer = _texture->LoadTGAImage(TGAfont);
    textColor = _texture->Palette[Color];
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
        vertex_buffer_vector.push_back((x / 960.0f -2.0f  + i / (1 / size)) / 2);//keep
        vertex_buffer_vector.push_back(y / 540.0f + (1 / (1 / size) - 1.0f) );//change
        vertex_buffer_vector.push_back( 0.0f);
        vertex_buffer_vector.push_back((x / 960.0f + (1 / (1 / size) - 2.0f) + i / (1 / size)) / 2);//change
        vertex_buffer_vector.push_back(y / 540.0f + (1 / (1/size) - 1.0f));//change
        vertex_buffer_vector.push_back( 0.0f);
        vertex_buffer_vector.push_back((x / 960.0f + (1 / (1 / size) - 2.0f) + i / (1 / size)) / 2);//change
        vertex_buffer_vector.push_back(y / 540.0f -1.0f );//keep
        vertex_buffer_vector.push_back( 0.0f);

        vertex_buffer_vector.push_back((x / 960.0f + (1 / (1 / size) - 2.0f) + i / (1 / size)) / 2);//change
        vertex_buffer_vector.push_back(y / 540.0f -1.0f );//keep
        vertex_buffer_vector.push_back(0.0f);
        vertex_buffer_vector.push_back((x / 960.0f -2.0f  + i / (1 / size)) / 2);//keep
        vertex_buffer_vector.push_back(y / 540.0f -1.0f );//keep
        vertex_buffer_vector.push_back(0.0f);
        vertex_buffer_vector.push_back((x / 960.0f -2.0f  + i / (1 / size)) / 2);//keep
        vertex_buffer_vector.push_back(y / 540.0f + (1 / (1 / size) - 1.0f));//change
        vertex_buffer_vector.push_back(0.0f);

        char character = text[i];
        float uv_x = (character % 16) / 16.0f;
        float uv_y = (character / 16) / 8.0f;

        uv_buffer_vector.push_back(uv_x);
        uv_buffer_vector.push_back((1.0f - uv_y) + 0.25f);

        uv_buffer_vector.push_back(uv_x + 0.0625f /1.5f);
        uv_buffer_vector.push_back((1.0f - uv_y) + 0.25f);

        uv_buffer_vector.push_back(uv_x + 0.0625f /1.5f);
        uv_buffer_vector.push_back(1.0f - uv_y + 0.1251f);

        uv_buffer_vector.push_back(uv_x + 0.0625f /1.5f);
        uv_buffer_vector.push_back(1.0f - uv_y + 0.1251f);

        uv_buffer_vector.push_back(uv_x);
        uv_buffer_vector.push_back(1.0f - uv_y + 0.1251f);

        uv_buffer_vector.push_back(uv_x);
        uv_buffer_vector.push_back((1.0f - uv_y) + 0.25f);
    }
    vertex_buffer_data = new GLfloat[]{
        0.5f * _texture->_width,  0.5f * _texture->_height, 0.0f,
       -0.5f * _texture->_width,  0.5f * _texture->_height, 0.0f,
       -0.5f * _texture->_width, -0.5f * _texture->_height, 0.0f,

       -0.5f * _texture->_width, -0.5f * _texture->_height, 0.0f,
        0.5f * _texture->_width, -0.5f * _texture->_height, 0.0f,
        0.5f * _texture->_width,  0.5f * _texture->_height, 0.0f,
    };
    uv_buffer_data = new GLfloat[]{
        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,

        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
    };
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, 72 * count, vertex_buffer_vector.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &uv_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, uv_buffer);
    glBufferData(GL_ARRAY_BUFFER, 48 * count, uv_buffer_vector.data(), GL_STATIC_DRAW);
    vertex_buffer_vector.clear();
    uv_buffer_vector.clear();
    delete _texture;
}

void Text::cleanupText2D()
{

}

void Text::DoIt(GLuint shader)
{
    GLuint ColorID = glGetUniformLocation(shader, "blendColor");
    glUniform4f(ColorID, textColor.r / 255.0f, textColor.g / 255.0f, textColor.b / 255.0f, 1.0f);
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