#ifndef TEXTURE_H_
#define TEXTURE_H_
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <SiroGen/color.h>

class Texture
{
public:
	Texture();
	~Texture();

	int _width = 0;
	int _height = 0;

	GLuint LoadTGAImage(const char* imagepath, bool isFont = false);
	GLuint LoadPixelImage(char* canvas, unsigned char width, unsigned char height);

    //Based on ZX Spectrum color palette.
    const Color Palette[16] =
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
    GLuint GetTexBuffer() { return _texture; };
private:
	GLuint _texture = 0;

    std::vector<unsigned char> pixelCanvas;
};
#endif