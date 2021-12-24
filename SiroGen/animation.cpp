#include "animation.h"
#include <SiroGen/pixelsprite.h>

void Animation::AddSprite(char canvas[], char width, char height, float timeonscreen)
{
	PixelSprite tempPS;
	tempPS.AddSprite(canvas, width, height);
	AniArray.emplace(tempPS.spritetexture, timeonscreen);
}

void Animation::AddSprite(const char* TGA, float timeonscreen)
{
	Sprite tempS;
	tempS.AddSprite(TGA);
	AniArray.emplace(tempS.spritetexture, timeonscreen);
}

void Animation::ReUseSprite(int spriteinarray, float timeonscreen)
{
	AniArray.emplace(AniArray.at(spriteinarray), timeonscreen);
}