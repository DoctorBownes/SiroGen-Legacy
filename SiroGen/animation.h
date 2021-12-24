#pragma once
#include <map>
//#include <SiroGen/pixelsprite.h> TODO Makes things crash
class Animation
{
public:
	void AddSprite(char canvas[],char width, char height, float timeonscreen = 0.5f);
	void AddSprite(const char* TGA, float timeonscreen = 0.5f);
	void ReUseSprite(int spriteinarray, float timeonscreen);
private:
	//std::map<GLuint, float> AniArray;
};
