#include <SiroGen/scene.h>

Scene::Scene()
{
}

Scene::~Scene()
{

}

void Scene::update(float deltaTime)
{

}

void Scene::Addchild(Entity* entity)
{
	_children.push_back(entity);
}