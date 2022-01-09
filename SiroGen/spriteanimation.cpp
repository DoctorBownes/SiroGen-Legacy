#include "spriteanimation.h"

void SpriteAnimation::AddSprite(char canvas[], char width, char height, float timeonscreen)
{
	PixelSprite* tempPS = new PixelSprite();
	tempPS->AddSprite(canvas, width, height);
	AniArray.push_back(std::make_pair(tempPS, timeonscreen));
	//delete tempPS;
}

void SpriteAnimation::AddSprite(const char* TGA, float timeonscreen)
{
	Sprite* tempS = new Sprite();
	tempS->AddSprite(TGA);
	AniArray.push_back(std::make_pair(tempS, timeonscreen));
	//delete tempS;
}