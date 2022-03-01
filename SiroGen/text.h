#pragma once
#include <vector>
#include <SiroGen/sprite.h>
#include <glm/glm.hpp>

class Text : private Sprite
{
public:
	Text();
	Text(Entity* owner);
	~Text();
	void SetText(std::string text, float x, float y, float size, uint8_t Color = 0xf, const char* TGAfont = "");
	void EditText(std::string text);
	void DoItext(GLuint shader);

private:
	ResourceManager* _instance = _instance->GetInstance();

	float _x = 0.0f;
	float _y = 0.0f;
	float _size = 0.0f;
	float _linedepth = 0.0f;

	void Init();

	int _count = 0;
};
