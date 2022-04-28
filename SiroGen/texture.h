#ifndef TEXTURE_H_
#define TEXTURE_H_
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SiroGen/color.h>
#include <SiroGen/resourcemanager.h>

class Texture
{
public:
	Texture();
	~Texture();

	int _width = 0;
	int _height = 0;

	GLuint LoadTGAImage(const char* imagepath, bool isFont = false);
	GLuint LoadPixelImage(char canvas[], unsigned char width, unsigned char height);
    GLuint GetTexBuffer() { return _texture; };
	ResourceManager* _instance = _instance->GetInstance();
private:
	GLuint _texture = 0;

    std::vector<unsigned char> pixelCanvas;
};

#endif
