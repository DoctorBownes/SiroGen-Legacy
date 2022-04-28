#ifndef SPRITE_H_
#define SPRITE_H_
#include "component.h"
#include <SiroGen/texture.h>
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
    char blendColor = 0xf;

protected:
    Texture* texture = nullptr;
    std::vector<GLfloat> vertex_buffer_vector;
    std::vector<GLfloat> uv_buffer_vector;
    GLuint texture_buffer = 0;
    GLuint vertex_buffer = 0;
    GLuint uv_buffer = 0;
    void GenerateSprite();
    virtual void DoIt(GLuint shader);

private:
    ResourceManager* _instance = _instance->GetInstance();

    int _height = 0;
    int _width = 0;
};

#endif
