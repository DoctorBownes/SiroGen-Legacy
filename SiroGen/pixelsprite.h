#pragma once
#include "sprite.h"
class PixelSprite
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

