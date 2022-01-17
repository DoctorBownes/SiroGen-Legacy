#pragma once
#include <vector>

class Color
{
public:
	Color();
	Color(uint8_t r, uint8_t g, uint8_t b);
	~Color();

	uint8_t r = 0;
	uint8_t g = 0;
	uint8_t b = 0;
};

#define ALPHA		Color(0,0,0)
#define BLACK		Color(0,0,0)
#define DARKBLUE	Color(0,0,224)
#define BLUE		Color(0,0,255)
#define DARKRED		Color(224,0,0)
#define RED			Color(255,0,0)
#define DARKMAGENTA Color(224,0,224)
#define MAGENTA		Color(255,0,255)
#define DARKGREEN	Color(0,224,0)
#define GREEN		Color(0,255,0)
#define DARKCYAN	Color(0,224,224)
#define CYAN		Color(0,255,255)
#define DARKYELLOW	Color(224,224,0)
#define YELLOW		Color(255,255,0)
#define GRAY		Color(224,224,224)
#define WHITE		Color(255,255,255)
