#include "GameObject.h"

#include "position.h"

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
	is_start_ = true;
	for (auto elem : components_)
	{
		elem->Start();
	}
    for (auto elem : child_) 
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
    for (auto elem : child_) 
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
    for (auto elem : child_) {
        elem->Render();
    }
}

GameObject* GameObject::Instantiate()
{
    auto* obj = new GameObject(this);
	child_.emplace_back(obj);
	obj->AddComponent<Position>();
    if(is_start_)obj->Start();
    return obj;
}


