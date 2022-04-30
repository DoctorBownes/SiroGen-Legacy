#ifndef COLOR_H_
#define COLOR_H_
#include <vector>
#include <cstdint>

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


class Palette
{
public:
    Palette(const Palette&) = delete;

    static Palette* GetInstance()
    {
        if (!_palette)
        {
            _palette = new Palette();
        }
        return _palette;
    }

    //Based on ZX Spectrum color palette.
    const Color Colors[16] =
    {
        ALPHA, //0
        BLACK, //1
        DARKBLUE, //2
        BLUE, //3
        DARKRED, //4
        RED, //5
        DARKMAGENTA, //6
        MAGENTA, //7
        DARKGREEN, //8
        GREEN, //9
        DARKCYAN, //10 0xa
        CYAN, //11 0xb
        DARKYELLOW, //12 0xc
        YELLOW, //13 0xd
        GRAY, //14 0xe
        WHITE //15 0xf
    };

private:
    Palette();
    ~Palette();
    static Palette* _palette;
};

#endif
