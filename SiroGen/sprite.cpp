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
    texture = nullptr;
    vertex_buffer_vector.clear();
    uv_buffer_vector.clear();
    GenerateSprite();
}

void Sprite::SetSprite(const char* TGA)
{
    texture = _instance->GetTexture(TGA);
    GenerateSprite();
}

void Sprite::SetSprite(char staticcanvas[], char width, char height)
{
    texture = _instance->GetTexture(staticcanvas,width,height);
    GenerateSprite();
}

void Sprite::SetTileSprite(char* staticcanvas[], unsigned short width, unsigned short height, char TileSizes)
{
    char* tempcanvas = (char*)malloc(width * height * TileSizes * TileSizes + 1);
    int var = 0;
    int var2 = 0;
    int var3 = 0;
    for (int y = 1; y <= height; y++)
    {
        for (int j = 1; j <= TileSizes; j++)
        {
            for (int x = 0 + var2; x < width * y; x++)
            {
                for (int i = 0 + var; i < TileSizes * j; i++)
                {
                    tempcanvas[var3] = (staticcanvas[x][i]);
                    var3++;
                }
            }
            var += TileSizes;
        }
        var = 0;
        var2 += width;
    }
    //F*ck this code ;)
    texture = _instance->GetTexture(tempcanvas, width * TileSizes, height * TileSizes);
    free(tempcanvas);
    GenerateSprite();
}

void Sprite::GenerateSprite()
{
    if (texture)
    {
        texture_buffer = texture->GetTexBuffer();
        vertex_buffer_vector.insert(vertex_buffer_vector.begin(), {

            -0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
             0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
             0.5f * texture->_width, -0.5f * texture->_height, 0.0f,

             0.5f * texture->_width, -0.5f * texture->_height, 0.0f,
            -0.5f * texture->_width, -0.5f * texture->_height, 0.0f,
            -0.5f * texture->_width,  0.5f * texture->_height, 0.0f,
            //TODO 
            // Implement pivot change. X = +0.5f Y = -0.5f
             //0.0f * texture->_width,  0.0f * texture->_height, 0.0f,
             //1.0f * texture->_width,  0.0f * texture->_height, 0.0f,
             //1.0f * texture->_width, -1.0f * texture->_height, 0.0f,

             //1.0f * texture->_width, -1.0f * texture->_height, 0.0f,
             //0.0f * texture->_width, -1.0f * texture->_height, 0.0f,
             //0.0f * texture->_width,  0.0f * texture->_height, 0.0f,
            });
        uv_buffer_vector.insert(uv_buffer_vector.begin(), {
            0.0f, 0.0f,
            1.0f, 0.0f,
            1.0f, 1.0f,

            1.0f, 1.0f,
            0.0f, 1.0f,
            0.0f, 0.0f,
            });
    }
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
    glUniform4f(ColorID, texture->_palette->Colors[blendColor].r / 255.0f, texture->_palette->Colors[blendColor].g / 255.0f, texture->_palette->Colors[blendColor].b / 255.0f, 1.0f);
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