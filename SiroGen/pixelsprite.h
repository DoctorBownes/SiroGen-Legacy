#pragma once
#include <glm/glm.hpp>
#include <SiroGen/color.h>
#include <SiroGen/sprite.h>
#include <vector>
class PixelSprite : public Component
{
public:

	std::vector<char>* pixelCanvas;//TODO FIX ERROR HERE
	char _width;
	char _height;
	PixelSprite();
	~PixelSprite();
	GLuint sprite;
	GLuint spritetexture;
	GLuint uv;

	void AddSprite(char canvas[], char width, char height);
};

