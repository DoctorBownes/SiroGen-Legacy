#include "sprite.h"

Sprite::Sprite()
{
    sprite = 0;
    spritetexture = 0;
    uv = 0;
    frame = 0;
    //sprites = new std::vector<GLuint>[10];
}

Sprite::~Sprite()
{

}

void Sprite::AddSprite(const char* TGA)
{
    Texture texture;
    //glGenVertexArrays(1, &VertexArrayID);
    spritetexture = texture.LoadTGAImage(TGA);
    const GLfloat temp_vertex_buffer_data[] = {
        0.5f * texture._width,  0.5f * texture._height, 0.0f,
       -0.5f * texture._width,  0.5f * texture._height, 0.0f,
       -0.5f * texture._width, -0.5f * texture._height, 0.0f,

       -0.5f * texture._width, -0.5f * texture._height, 0.0f,
        0.5f * texture._width, -0.5f * texture._height, 0.0f,
        0.5f * texture._width,  0.5f * texture._height, 0.0f,
    };
    
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
}

