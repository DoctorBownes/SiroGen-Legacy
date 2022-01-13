#include "texture.h"
#include <glm/glm.hpp>

Texture::Texture()
{
	_texture = 0;
	_width = 0;
	_height = 0;
}

Texture::~Texture()
{

}

GLuint Texture::LoadTGAImage(const char* imagepath)
{
	// Data read from the header of the BMP file
	unsigned char header[18];
	unsigned char type;
	unsigned short widtheight[2];
	unsigned char bitdepth;
	unsigned int imageSize;
	// Actual RGB data
	unsigned char* data;
	FILE* file;
	file = fopen(imagepath, "rb");
	if (!file)
	{
		printf("File could not be opened");
		return 0;
	}

	if (fread(header, 1, 18, file) != 18)
	{
		printf("Not a correct TGA file");
		return 0;
	}

	fseek(file, 2, SEEK_SET);
	fread(&type, sizeof(char), 1, file);

	if (type != 1 && type != 2 && type != 3 && type != 10)
	{
		printf("TGA image was compressed");
		return 0;
	}
	
	fseek(file, 12, SEEK_SET);
	fread(widtheight, sizeof(short), 2, file);


	fseek(file, 16, SEEK_SET);
	fread(&bitdepth, sizeof(char), 1, file);
	if (bitdepth != 8 && bitdepth != 16 && bitdepth != 24 && bitdepth != 32)
	{
		printf("Unsupported pixel depth");
		return 0;
	}

	_width = widtheight[0];
	_height = widtheight[1];

	imageSize = _width * _height * (bitdepth / 8);

	data = new unsigned char[imageSize];

	fseek(file, 18, SEEK_SET);
	fread(data, 1, imageSize, file);

	fclose(file);
	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


	switch (bitdepth / 8)
	{
	case 1:
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, _width, _height, 0, GL_RED, GL_UNSIGNED_BYTE, data);
		const GLint swizzleMask[] = { GL_RED, GL_RED, GL_RED, GL_ONE };
		glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, swizzleMask);
		break;
	}
	case 2:
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RG, _width, _height, 0, GL_RED, GL_UNSIGNED_BYTE, data);
		const GLint swizzleMask[] = { GL_ZERO, GL_ZERO, GL_RED, GL_ONE };
		glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, swizzleMask);
		break;
	}
	case 3:
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
		break;
	case 4:
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		break;
	}
	glGenerateMipmap(GL_TEXTURE_2D);
	delete []data;

	return _texture;
}

GLuint Texture::LoadPixelImage(char canvas[], char width, char height)
{
	_width = width;
	_height = height;
	for (int i = 0; i < _width * _height; i++)
	{
		size_t index = canvas[i];
		pixelCanvas.push_back(Palette[index].r);
		pixelCanvas.push_back(Palette[index].g);
		pixelCanvas.push_back(Palette[index].b);
	}

	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelCanvas.data());
	glGenerateMipmap(GL_TEXTURE_2D);

	pixelCanvas.clear();

	return _texture;
}