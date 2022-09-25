#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>
#include <SiroGen/color.h>


int main(int argc, char* argv[])
{
	std::cout << argv[1] << std::endl;
	unsigned char header[18];
	unsigned char type;
	unsigned short widtheight[2];
	unsigned char bitdepth;
	unsigned int imageSize;
	unsigned char* data;
	FILE* file;
	file = fopen(argv[1], "rb");
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

	imageSize = widtheight[0] * widtheight[1] * (bitdepth / 8);

	std::stringstream ArrayString;
	ArrayString << "static char PixelSprite[]{\n";
	data = new unsigned char[imageSize];

	fseek(file, 18, SEEK_SET);
	fread(data, 1, imageSize, file);

	fclose(file);
	Palette* palette = palette->GetInstance();
	int n = sizeof(palette->Colors) / sizeof(palette->Colors[0]);
	std::vector<Color> TGAPalette;

	std::string temparray;
	std::stringstream ArrayString2;
	std::vector<std::string> temparray2;

	int widthcounter = 0;
	for (int i = 0; i < n; i++)
	{
		TGAPalette.push_back(palette->Colors[i]);
	}
	int counter = 0;
	//int x = 0;
	for (int y = 1; y <= widtheight[1]; y++)
	{
		ArrayString2.clear();
		ArrayString2.str("");
		ArrayString2.str().clear();
		for (int x = 0 + counter; x < widtheight[0] * 4 * y; x += 4)
		{
			Color OmniColor = Color(data[x + 2], data[x + 1], data[x + 0]);
			if (data[x + 3] == 0)
			{
				ArrayString2 << 0 << ",";
			}
			else
			{
				for (int j = 1; j < TGAPalette.size(); j++)
				{
					if (TGAPalette[j].r == OmniColor.r && TGAPalette[j].g == OmniColor.g && TGAPalette[j].b == OmniColor.b)
					{
						ArrayString2 << j << ',';
					}
				}
			}
		}
		ArrayString2 << '\n';
		counter += widtheight[0] * 4;
		temparray2.push_back(ArrayString2.str().c_str());
	}
	ArrayString << "};";
	std::cout << temparray2[0] << std::endl;
	std::cout << temparray2[1] << std::endl;
	std::cout << temparray2[2] << std::endl;
	//std::getchar();

	FILE* pFile;
	pFile = fopen("alphabet.c", "wt");
	const char* c;
	std::ofstream creatMyFile("alphabet.c");
	// Here we are writing contents to the file
	for (int i = temparray2.size() -1; i >= 0; i--)
	{
		creatMyFile << temparray2[i];
	}
	// Once done with the writing closing the file
	creatMyFile.close();
	delete[]data;
	
	return 0;
}