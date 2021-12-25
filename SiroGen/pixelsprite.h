#pragma once
#include <SiroGen/color.h>
#include <SiroGen/sprite.h>
class PixelSprite : public Sprite
{
public:
	void AddSprite(char canvas[], char width, char height);
private:
    Color Palette[15] =
    {
        BLACK,
        DARKBLUE,
        BLUE,
        DARKRED,
        RED,
        DARKMAGENTA,
        MAGENTA,
        DARKGREEN,
        GREEN,
        DARKCYAN,
        CYAN,
        DARKYELLOW,
        YELLOW,
        GRAY,
        WHITE
    };
	std::vector<char> pixelCanvas;
};

