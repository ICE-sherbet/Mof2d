#include "GameObject.h"

GameObject::GameObject(Object* parent):Object(parent)
{
}

GameObject::GameObject(){

}

GameObject::~GameObject()
{
	for (auto elem:components_)
	{
		delete elem;
	}
}

void GameObject::Start()
{
	for (auto elem : components_)
	{
		elem->Start();
	}
}

void GameObject::Update()
{
	for (auto elem : components_)
	{
		elem->Update();
	}
}

void GameObject::Render()
{
	for (auto elem : components_)
	{
		elem->Render();
	}
}


