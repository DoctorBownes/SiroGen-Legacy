#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

class Texture
{
public:
	Texture();
	~Texture();

	int _width;
	int _height;

	unsigned char* LoadTGAImage(const char* imagepath);
	GLuint GetTexture() { return _texture; };
private:
	GLuint _texture;
};
