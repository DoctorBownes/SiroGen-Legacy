#pragma once
#include <SiroGen/sprite.h>

class SpriteAnimation
{
public:
	SpriteAnimation();
	~SpriteAnimation();

	//Sprite* tempS;
	void AddSprite(char canvas[], char width, char height, float timeonscreen = 0.5f);
	void AddSprite(const char* TGA, float timeonscreen = 0.5f);
	void ReUseSprite(int spriteinarray, float timeonscreen = 0.5f);
	std::vector<std::pair<Sprite*, float> > GetArray() { return AniArray; };
private:
	std::vector<std::pair<Sprite*, float> > AniArray;
};