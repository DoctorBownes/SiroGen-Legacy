#ifndef SPRITE_H_
#define SPRITE_H_
#include "component.h"
#include <SiroGen/resourcemanager.h>
#include <vector>
class Sprite :
    public Component
{
public:
    Sprite();
    Sprite(Entity* owner);
    ~Sprite();

    void SetSprite(const char* TGA);
    void RemoveSprite();
    void SetSprite(char canvas[], char width, char height);

private:
    ResourceManager* _instance = _instance->GetInstance();
    Texture* texture;
    char blendColor = 0xf;
    GLfloat* vertex_buffer_data;
    GLfloat* uv_buffer_data;
    std::vector<GLfloat> vertex_buffer_vector;
    std::vector<GLfloat> uv_buffer_vector;
    void GenerateSprite();
    virtual void DoIt(GLuint shader);

    GLuint texture_buffer;
    GLuint vertex_buffer;
    GLuint uv_buffer;

    int _height = 0;
    int _width = 0;
};
#endif