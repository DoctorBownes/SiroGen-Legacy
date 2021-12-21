#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Texture
{
public:
	Texture();
	~Texture();

	int _width;
	int _height;

	GLuint LoadTGAImage(const char* imagepath);
private:
	GLuint _texture;
};
