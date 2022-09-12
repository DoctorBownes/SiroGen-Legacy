#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_
#include <map>
#include <string>
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

	Texture* GetTexture(const std::string imagepath, bool isFont = false);
	Texture* GetTexture(char staticcanvas[], unsigned short width, unsigned short height);
	void DeleteTexture(Texture* texture);
	void cleanup();

	std::map<const char*, Texture*> _textures;

private:
	ResourceManager();
	~ResourceManager();
	static ResourceManager* _instance;
};

#endif
