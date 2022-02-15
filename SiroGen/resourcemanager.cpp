#include "resourcemanager.h"
ResourceManager* ResourceManager::_instance = 0;

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{
	cleanup();
}

Texture* ResourceManager::GetTexture(const char* imagepath, bool isFont)
{
	if (_textures[imagepath] != nullptr)
	{
		return _textures[imagepath];
	}
	Texture* temptexture = new Texture();
	temptexture->LoadTGAImage(imagepath, isFont);
	_textures[imagepath] = temptexture;
	return temptexture;
}

Texture* ResourceManager::GetTexture(char canvas[], unsigned char width, unsigned char height)
{
	if (_textures[canvas] != nullptr)
	{
		return _textures[canvas];
	}
	Texture* temptexture = new Texture();
	temptexture->LoadPixelImage(canvas, width, height);
	_textures[canvas] = temptexture;
	return temptexture;
}

void ResourceManager::DeleteTexture(Texture* texture)
{
	delete texture;
}

void ResourceManager::cleanup()
{
	std::map<const char*, Texture*>::iterator it;
	for (it = _textures.begin(); it != _textures.end(); it++)
	{
		delete it->second;
	}
	_textures.clear();
}