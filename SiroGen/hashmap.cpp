#include "hashmap.h"

HashMap::HashMap(int posX, int posY, int width, int height, int cellAmount)
{
	x = posX;
	y = posY;
	w = width;
	h = height;
	_cellAmount = cellAmount;
	//cellsize = std::abs(x + w) / _cellAmount * std::abs(y + h) / _cellAmount;

	for (int i = 0; i < _cellAmount; i++)
	{
		for (int j = 0; j < _cellAmount; j++)
		{
			std::vector<Entity*> tempvector;
			cells[std::make_pair(i * (std::abs(w) / w), j * (std::abs(h) / h))] = tempvector;
		}
	}

	//std::cout << cellsize << std::endl;
	std::cout << cells.size() << std::endl;
}

void HashMap::Insert(Entity* entity)
{
	if (entity->transform.position.x < w && entity->transform.position.x >= x && entity->transform.position.y > h && entity->transform.position.y <= y)
		cells.find(std::make_pair((int)getPos(entity)[0], (int)getPos(entity)[1]))->second.push_back(entity);
	else
		printf("Error: Entity out of HashMap bounds\n");
}

float* HashMap::getPos(Entity* entity)
{
	float arrayint[2]{};
	arrayint[0] = entity->transform.position.x / (w / _cellAmount);
	arrayint[1] = entity->transform.position.y / (-h / _cellAmount);
	return arrayint;
}


std::vector<Entity*> HashMap::getCell(int x, int y)
{
	return cells[std::make_pair(x, y)];
}
