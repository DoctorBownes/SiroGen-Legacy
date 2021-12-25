#include "spriteanimation.h"
#include <SiroGen/pixelsprite.h>

void SpriteAnimation::AddSprite(char canvas[], char width, char height, float timeonscreen)
{
	PixelSprite tempPS;
	tempPS.AddSprite(canvas, width, height);
	AniArray.push_back(tempPS.spritetexture);
}

void SpriteAnimation::AddSprite(const char* TGA, float timeonscreen)
{
	Sprite tempS;
	tempS.AddSprite(TGA);
	AniArray.push_back(tempS.spritetexture);
}

void SpriteAnimation::ReUseSprite(int spriteinarray, float timeonscreen)
{
	AniArray.push_back(AniArray.at(spriteinarray));
}