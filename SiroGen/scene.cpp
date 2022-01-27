#include <SiroGen/scene.h>

Scene::Scene()
{
}

Scene::~Scene()
{
	delete MainCamera;
}

void Scene::update(float deltaTime)
{

}

void Scene::AddtoScene(Entity* entity)
{
	_children.push_back(entity);
}

void Scene::RemovefromScene(Entity* entity)
{
	if (std::find(_children.begin(), _children.end(), entity) != _children.end())
	{
		_children.erase(std::find(_children.begin(), _children.end(), entity));
	}
}

void Scene::DeleteEntity(Entity* entity)
{
	if (std::find(_children.begin(), _children.end(), entity) != _children.end())
	{
		_children.erase(std::find(_children.begin(), _children.end(), entity));
		delete entity;
	}
	std::cout << "Warning: DeleteEntity is unfinished" << std::endl;
}

void Scene::AddTexttoScene(std::string text, float x, float y, float size, uint8_t Color, const char* TGAfont)
{
	Text temptext;
	temptext.printText2D(text, x, y, size, Color, TGAfont);
	scenetexts.push_back(temptext);
}

void Scene::RemoveTextfromScene(int pos)
{
	if (scenetexts.size() > 0)
	{
		scenetexts.erase(scenetexts.begin() + pos);
	}
}