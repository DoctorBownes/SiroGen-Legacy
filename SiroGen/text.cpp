#include "text.h"

void Text::initText2D(const char* texturePath)
{

}

void Text::printText2D(const char* text, int x, int y, int size, const char* TGAfont)
{
    _texture = new Texture();
    texture_buffer = _texture->LoadTGAImage(TGAfont);
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

void Text::cleanupText2D()
{

}

void Text::DoIt(GLuint shader)
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