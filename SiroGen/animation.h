#pragma once
#include <map>
#include <SiroGen/sprite.h>

class Animation
{
public:
	void AddSprite(char canvas[], char width, char height, float timeonscreen = 0.5f);
	void AddSprite(const char* TGA, float timeonscreen = 0.5f);
	void ReUseSprite(int spriteinarray, float timeonscreen);
private:
	std::map<bool, float> AniArray;
};