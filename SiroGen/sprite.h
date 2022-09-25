#ifndef SPRITE_H_
#define SPRITE_H_
#include "component.h"
#include <SiroGen/resourcemanager.h>
#include <vector>
class Sprite :
    public Component
{
public:
    Sprite(Entity* owner = nullptr);
    ~Sprite();

    void SetSprite(const char* TGA);
    void RemoveSprite();
    void SetSprite(char staticcanvas[], char width, char height);
    void SetTileSprite(char* staticcanvas[], unsigned short width, unsigned short height, char TileSizes);
    char blendColor = WHT;

protected:
    Texture* texture = nullptr;
    std::vector<GLfloat> vertex_buffer_vector;
    std::vector<GLfloat> uv_buffer_vector;
    GLuint texture_buffer = 0;
    GLuint vertex_buffer = 0;
    GLuint uv_buffer = 0;
    void GenerateSprite();
    virtual void DoIt(GLuint shader);
    ResourceManager* _instance = _instance->GetInstance();

private:
    bool drawn = 0;
    int _height = 0;
    int _width = 0;
};

#endif
