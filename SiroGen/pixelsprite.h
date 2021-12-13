#pragma once
#include <glm/glm.hpp>
#include "sprite.h"
class PixelSprite : public Component
{
public:
	char width;
	char height;
	PixelSprite();
	~PixelSprite();
	GLuint sprite;
	GLuint spritetexture;
	GLuint uv;

	void AddSprite(char canvas[], char width, char height);
};

