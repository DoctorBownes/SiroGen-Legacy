#pragma once
#include <vector>
#include <map>
#include <SiroGen/sprite.h>

class SpriteAnimation
{
public:
	void AddSprite(char canvas[], char width, char height, float timeonscreen = 0.5f);
	void AddSprite(const char* TGA, float timeonscreen = 0.5f);
	void ReUseSprite(int spriteinarray, float timeonscreen = 0.5f);
	std::map<GLuint, float> GetArray() { return AniArray; };
	std::map<GLuint, float> AniArray;
	std::map<GLuint, float>::iterator it;
private:
};