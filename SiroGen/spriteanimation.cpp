#include "spriteanimation.h"
#include <SiroGen/pixelsprite.h>

void SpriteAnimation::AddSprite(char canvas[], char width, char height, float timeonscreen)
{
	PixelSprite tempPS;
	tempPS.AddSprite(canvas, width, height);
	tempPS.timeonscreen = timeonscreen;
	AniArray.push_back(tempPS);
}

void SpriteAnimation::AddSprite(const char* TGA, float timeonscreen)
{
	Sprite tempS;
	tempS.AddSprite(TGA);
	tempS.timeonscreen = timeonscreen;
	AniArray.push_back(tempS);
}

void SpriteAnimation::ReUseSprite(int spriteinarray, float timeonscreen)
{
	AniArray.push_back(AniArray.at(spriteinarray));
}