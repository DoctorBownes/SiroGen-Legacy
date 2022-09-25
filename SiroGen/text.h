#ifndef TEXT_H_
#define TEXT_H_
#include <vector>
#include <SiroGen/sprite.h>

class Text : public Sprite
{
public:
	Text(Entity* owner = nullptr);
	~Text();
	void SetText(std::string text, float x, float y, float size, uint8_t Color = 0xf, const char* TGAfont = "");
	void EditText(std::string text);
	void DoItext(GLuint shader);

private:

	float _x = 0.0f;
	float _y = 0.0f;
	float _size = 0.0f;
	float _linedepth = 0.0f;
	int _count = 0;
};

#endif
