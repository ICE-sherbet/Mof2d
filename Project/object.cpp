#include "object.h"

Object::Object()
{}

Object::~Object()
{
	for (auto elem:components_)
	{
		delete elem;
	}
}

void Object::Start()
{
	for (auto elem : components_)
	{
		elem->Start();
	}
}

void Object::Update()
{
	for (auto elem : components_)
	{
		elem->Update();
	}
}

void Object::Render()
{
	for (auto elem : components_)
	{
		elem->Render();
	}
}


