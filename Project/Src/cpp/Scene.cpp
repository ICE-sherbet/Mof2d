#include "Scene.h"

Scene::~Scene()
{
	for (auto elem:objects_)
	{
		delete elem;
	}
}

GameObject* Scene::Instantiate()
{
	GameObject* obj = new GameObject(this);

	if(is_start_)obj->Start();
	objects_.emplace_back(obj);
	return obj;
}

GameObject& Scene::Instantiate(GameObject obj)
{
	objects_.emplace_back(&obj);
	if (is_start_)objects_.back()->Start();
	return *objects_.back();
}

void Scene::Start()
{
	is_start_ = true;
	for (auto elem : objects_)
	{
		elem->Start();
	}
}

void Scene::Update()
{
	for (auto elem : objects_)
	{
		elem->Update();
	}
}

void Scene::Render()
{
	for (auto elem : objects_)
	{
		elem->Render();
	}
}
