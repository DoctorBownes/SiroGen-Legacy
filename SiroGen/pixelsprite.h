#pragma once
#include <glm/glm.hpp>
#include <SiroGen/color.h>
#include <SiroGen/sprite.h>
class PixelSprite : public Component
{
public:
	PixelSprite();
	~PixelSprite();
	char _width;
	char _height;
	GLuint sprite;
	GLuint spritetexture;
	GLuint uv;

	void AddSprite(char canvas[], char width, char height);
};

