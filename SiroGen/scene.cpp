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

void Scene::AddTexttoScene(const char* text, float x, float y, float size, const char* TGAfont)
{
	Text* temptext = new Text();
	temptext->printText2D(text, x, y, size, TGAfont);
	scenetexts.push_back(temptext);
}