#ifndef SPRITEANIMATION_H_
#define SPRITEANIMATION_H_
#include <SiroGen/sprite.h>

class SpriteAnimation
{
public:
	SpriteAnimation();
	~SpriteAnimation();

	//Sprite* tempS;
	void AddSprite(char* canvas, unsigned char width, unsigned char height, float timeonscreen = 0.5f);
	void AddSprite(const char* TGA, float timeonscreen = 0.5f);
	//void ReUseSprite(int spriteinarray, float timeonscreen = 0.5f);
	int startframe = 0;
	int endframe = 0;
	std::vector<std::pair<Sprite*, float> > GetArray() { return AniArray; };
private:
	std::vector<std::pair<Sprite*, float> > AniArray = std::vector<std::pair<Sprite*, float> >();
};
#endif