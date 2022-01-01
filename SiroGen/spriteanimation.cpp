#include "spriteanimation.h"
#include <SiroGen/pixelsprite.h>

void SpriteAnimation::AddSprite(char canvas[], char width, char height, float timeonscreen)
{
	PixelSprite tempPS;
	tempPS.AddSprite(canvas, width, height);
	AniArray.emplace(tempPS.spritetexture, timeonscreen);
}

void SpriteAnimation::AddSprite(const char* TGA, float timeonscreen)
{
	Sprite tempS;
	tempS.AddSprite(TGA);
	AniArray.emplace(tempS.spritetexture, timeonscreen);
}

void SpriteAnimation::ReUseSprite(int spriteinarray, float timeonscreen)
{
	AniArray.emplace(AniArray.at(spriteinarray), timeonscreen);
}