#pragma once
#include <map>
#include <SiroGen/texture.h>

class ResourceManager
{
public:
	ResourceManager(const ResourceManager&) = delete;

	static ResourceManager* GetInstance()
	{
		if (!_instance)
		{
			_instance = new ResourceManager();
		}
		return _instance;
	}

	Texture* GetTexture(const char* imagepath, bool isFont = false);
	Texture* GetTexture(char* canvas, unsigned char width, unsigned char height);
	void DeleteTexture(Texture* texture);
	void cleanup();

	std::map<const char*, Texture*> _textures;


private:
	ResourceManager();
	~ResourceManager();
	static ResourceManager* _instance;
};