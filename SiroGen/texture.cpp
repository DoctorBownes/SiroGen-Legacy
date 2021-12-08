#include "texture.h"
#include <glm/glm.hpp>

Texture::Texture()
{
	_width = 0;
	_height = 0;
}

Texture::~Texture()
{

}

GLuint* Texture::LoadTGAImage(const char* imagepath)
{
	// Data read from the header of the BMP file
	unsigned char header[18];
	unsigned char type;
	unsigned short info[3];
	unsigned int imageSize;
	// Actual RGB data
	unsigned char* data;
	FILE* file;
	file = fopen(imagepath, "rb");
	if (!file)
	{
		printf("File could not be opened");
		return nullptr;
	}

	if (fread(header, 1, 18, file) != 18)
	{
		printf("Not a correct TGA file");
		return nullptr;
	}

	fseek(file, 2, SEEK_SET);
	fread(&type, sizeof(char), 1, file);

	if (type != 1 && type != 2 && type != 3 && type != 10)
	{
		printf("TGA image was compressed");
		return nullptr;
	}
	fseek(file, 12, SEEK_SET);
	fread(info, sizeof(short), 3, file);
	if (info[2] != 8 && info[2] != 16 && info[2] != 24 && info[2] != 32)
	{
		printf("Unsupported pixel depth");
		return nullptr;
	}

	_width = info[0];
	_height = info[1];

	imageSize = _width * _height * (info[2] / 8);

	data = new unsigned char[imageSize];

	fread(data, 1, imageSize, file);

	fclose(file);
	GLuint textureID;
	glGenTextures(1, &textureID);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Give the image to OpenGL

	//GL_RED
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, _width, _height, 0, GL_RED, GL_UNSIGNED_BYTE, data);
	const GLint swizzleMask[] = { GL_RED, GL_RED, GL_RED, GL_ONE };
	glTexParameteriv(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_RGBA, swizzleMask);
	glGenerateMipmap(GL_TEXTURE_2D);



	delete []data;

	return &textureID;
}