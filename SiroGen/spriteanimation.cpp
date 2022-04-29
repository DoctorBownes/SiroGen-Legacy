#include "spriteanimation.h"

SpriteAnimation::SpriteAnimation()
{
}

SpriteAnimation::~SpriteAnimation()
{
	for (int i = 0; i < AniArray.size(); i++)
	{
		delete AniArray.at(i).first;
	}
	AniArray.clear();
}

void SpriteAnimation::AddSprite(char staticcanvas[], unsigned char width, unsigned char height, float timeonscreen)
{
	Sprite* tempS = new Sprite();
	tempS->SetSprite(staticcanvas, width, height);
	AniArray.push_back(std::make_pair(tempS, timeonscreen));
}

void SpriteAnimation::AddSprite(const char* TGA, float timeonscreen)
{
	Sprite* tempS = new Sprite();
	tempS->SetSprite(TGA);
	AniArray.push_back(std::make_pair(tempS, timeonscreen));
}