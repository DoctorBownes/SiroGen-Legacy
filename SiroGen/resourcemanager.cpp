#include "resourcemanager.h"
#include <SiroGen/texture.h>
ResourceManager* ResourceManager::_instance = 0;

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
	cleanup();
}

Texture* ResourceManager::GetTexture(const std::string imagepath, bool isFont)
{
	if (_textures[imagepath.c_str()] != nullptr)
	{
		return _textures[imagepath.c_str()];
	}
	_textures.erase(imagepath.c_str());
	Texture* temptexture = new Texture();
	temptexture->LoadTGAImage(imagepath.c_str(), isFont);
	_textures[imagepath.c_str()] = temptexture;
	return temptexture;
}

Texture* ResourceManager::GetTexture(char staticcanvas[], unsigned char width, unsigned char height)
{
	//MAKE SURE THE CANVAS IS STATIC!
	if (_textures[canvas] != nullptr)
	{
		return _textures[canvas];
	}
	_textures.erase(canvas);
//	std::cout << "New Texture number: " << _textures.size() << std::endl;
	Texture* temptexture = new Texture();
	temptexture->LoadPixelImage(canvas, width, height);
	_textures[canvas] = temptexture;
	return temptexture;
}

void ResourceManager::DeleteTexture(Texture* texture)
{
	Texture* temptexture = texture;
	std::map<const char*, Texture*>::iterator it;
	for (it = _textures.begin(); it != _textures.end(); it++)
	{
		if (it->second == temptexture)
		{
	//		std::cout << "Deleting Textures" << std::endl;
			delete texture;
			_textures[it->first] = nullptr;
			//_textures.erase(it);
		}
	}
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