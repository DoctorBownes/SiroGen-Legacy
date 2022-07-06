#include <SiroGen/scene.h>

Scene::Scene()
{
	worldtransform = new Transform();
}

Scene::~Scene()
{
	for (int i = 0; i < _children.size(); i++)
	{
		delete _children[i];
	}
	_children.clear();
	delete MainCamera;
	//DeleteChildren(this);
}

//To make sure all found entities have their input properly initialized I use a recursive method
//this goed through all of the entities' children and their children and so on until all of them
// are set.
void Scene::InputInit(Entity* entity, GLFWwindow* window)
{
	/*if (!entity->shouldUpdate)
	{
		entity->RemoveComponent<Update>();
	}*/
	entity->GetInput()->Init(window);
	std::vector<Entity*> child = entity->Getchildren();
	std::vector<Entity*>::iterator it;
	for (it = child.begin(); it != child.end(); it++)
	{
		InputInit(*it, window);
	}
}

void Scene::AddSceneText(std::string text, float x, float y, float size,  uint8_t Color, const char* TGAfont)
{
	Text* temptext = new Text();
	temptext->SetText(text, x / 480.0f, y / 540.0f, size / 64.0f, Color, TGAfont);
	scenetexts.push_back(temptext);
}


void Scene::EditSceneText(std::string text, int pos)
{
	scenetexts[pos]->EditText(text);
}

void Scene::RemoveSceneText(int pos)
{
	if (scenetexts.size() > 0)
	{
		delete scenetexts[pos];
		scenetexts.erase(scenetexts.begin() + pos);
	}
}

void Scene::ClearSceneText()
{
	for (int i = 0; i < scenetexts.size(); i++)
	{
		delete scenetexts[i];
	}
	scenetexts.clear();
}