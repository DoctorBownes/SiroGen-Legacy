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
        DARKCYAN, //10
        CYAN, //11
        DARKYELLOW, //12
        YELLOW, //13
        GRAY, //14
        WHITE //15
    };
private:
	GLuint _texture;

    //Based on ZX Spectrum color palette.
    std::vector<unsigned char> pixelCanvas;
};
