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