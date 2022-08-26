#ifndef HASHMAP_H_
#define HASHMAP_H_
#include <sirogen/entity.h>
#include <map>

class HashMap 
{
public:
	HashMap(int posX, int posY, int width, int height, int cellAmount);
	void Insert(Entity* entity);
	std::vector<Entity*> getCell(int x, int y);

	float* getPos(Entity* entity);

	std::map<std::pair<int, int>, std::vector<Entity*>> cells;
private:
	float x,y,w,h = 0;
	int _cellAmount = 0;
	//float cellsize = 0;
};

#endif
