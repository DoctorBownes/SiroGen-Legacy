#include "color.h"
Palette* Palette::_palette = 0;


Palette::Palette()
{
}

Palette::~Palette()
{
	delete _palette;
}

Color::Color()
{
	this->r = 0;
	this->g = 0;
	this->b = 0;
}

Color::~Color()
{

}

Color::Color(uint8_t r, uint8_t g, uint8_t b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}
