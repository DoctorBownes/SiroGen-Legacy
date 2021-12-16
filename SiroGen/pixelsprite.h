#pragma once
#include <glm/glm.hpp>
#include <SiroGen/color.h>
#include "sprite.h"
class PixelSprite : public Component
{
public:
	std::vector<uint8_t>* pixelCanvas;

	char _width;
	char _height;
	PixelSprite();
	~PixelSprite();
	GLuint sprite;
	GLuint spritetexture;
	GLuint uv;

	void AddSprite(char canvas[], char width, char height);
};

