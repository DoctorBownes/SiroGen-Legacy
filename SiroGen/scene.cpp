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

void Scene::InputInit(Entity* entity, GLFWwindow* window)
{
	entity->GetInput()->Init(window);
	std::vector<Entity*> child = entity->Getchildren();
	std::vector<Entity*>::iterator it;
	for (it = child.begin(); it != child.end(); it++)
	{
		InputInit(*it, window);
	}
}

void Scene::updateEntities(Entity* entity, float deltaTime)
{
	entity->update(deltaTime);
	std::vector<Entity*> child = entity->Getchildren();
	std::vector<Entity*>::iterator it;
	for (it = child.begin(); it != child.end(); it++)
	{
		updateEntities(*it, deltaTime);
	}
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

void Scene::AddSceneText(std::string text, float x, float y, float size, uint8_t Color, const char* TGAfont)
{
	Text temptext = Text();
	temptext.SetText(text, x / 480.0f, y / 540.0f, size / 64.0f, Color, TGAfont);
	scenetexts.push_back(temptext);
}


void Scene::EditSceneText(std::string text, int pos)
{
	scenetexts[pos].EditText(text);
}

void Scene::RemoveSceneText(int pos)
{
	if (scenetexts.size() > 0)
	{
		scenetexts.erase(scenetexts.begin());
	}
}

void Scene::ClearSceneText()
{
	scenetexts.clear();
}