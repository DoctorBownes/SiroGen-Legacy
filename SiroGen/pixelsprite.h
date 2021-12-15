#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "sprite.h"
class PixelSprite : public Component
{
public:
	char _width;
	char _height;
	PixelSprite();
	~PixelSprite();
	GLuint sprite;
	GLuint spritetexture;
	GLuint uv;

	void AddSprite(char canvas[], char width, char height);
};

