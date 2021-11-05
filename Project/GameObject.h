#pragma once
#include <list>
#include "Component.h"
#include "Mof.h"
#include "Object.h"

class Component;
//オブジェクトクラス
class GameObject final : public Object
{
	
	Object* root_object_ = nullptr;
	std::list<Component*> components_;

public:
    GameObject(Object* parent);
	GameObject();

	~GameObject();


	void Start() override;

	void Update() override;

	void Render() override;


    GameObject& Instantiate(){
        auto&& obj = new GameObject(this);
        if(is_start_)obj->Start();
        return *obj;
    }


	template <typename type>
	type* GetComponent();

	template <typename type>
	type* AddComponent();

	template <typename type>
	type* AddComponent(type* component);
};

template <typename type>
type* GameObject::GetComponent()
{
	for (auto elem : components_)
	{
		type* buff = dynamic_cast<type*>(elem);
		if (buff != nullptr) return buff;
	}
	return nullptr;
}

template <typename type>
type* GameObject::AddComponent()
{
	type* buff = new type();
	buff->parent_ = this;
	components_.push_back(buff);
	return buff;
}

template <typename type>
type* GameObject::AddComponent(type* component)
{

	component->parent_ = this;
	components_.push_back(component);
	return component;
}
