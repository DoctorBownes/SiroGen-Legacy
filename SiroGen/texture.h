#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <SiroGen/color.h>

class Texture
{
public:
	Texture();
	~Texture();

	int _width;
	int _height;

	GLuint LoadTGAImage(const char* imagepath, bool isFont = false);
	GLuint LoadPixelImage(char canvas[], unsigned char width, unsigned char height);
    const Color Palette[16] =
    {
        ALPHA,
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
private:
	GLuint _texture;

    //Based on ZX Spectrum color palette.
    std::vector<unsigned char> pixelCanvas;
};
