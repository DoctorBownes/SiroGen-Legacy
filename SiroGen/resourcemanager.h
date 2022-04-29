#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_
#include <map>
#include <string>
#include <SiroGen/color.h>

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

	class Texture* GetTexture(const std::string imagepath, bool isFont = false);
	Texture* GetTexture(char staticcanvas[], unsigned char width, unsigned char height);
	void DeleteTexture(Texture* texture);
	void cleanup();

	std::map<const char*, Texture*> _textures;

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

private:
	ResourceManager();
	~ResourceManager();
	static ResourceManager* _instance;
};

#endif
