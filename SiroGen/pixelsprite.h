#pragma once
#include <SiroGen/color.h>
#include <SiroGen/sprite.h>
class PixelSprite : public Sprite
{
public:
	void AddSprite(char canvas[], char width, char height);
	//std::vector<char>* sprites;
	GLuint Frame;
	void PlayAnimation(GLuint canvas);
};

