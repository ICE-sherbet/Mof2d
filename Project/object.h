#pragma once
#include <list>
#include "Mof.h"
#include "Component.h"
class Component;

//オブジェクトクラス
class Object
{
	std::list<Component*> components_;
public:
	Object();

	~Object();

	void Start();

	void Update();

	void Render();

	template <typename type>
	type* GetComponent()
	{
		for (auto elem : components_)
		{
			type* buff = dynamic_cast<type*>(elem);
			if (buff != nullptr) return buff;
		}
		return nullptr;
	}

	template <typename type>
	type* AddComponent()
	{
		type* buff = new type();
		buff->parent_ = this;
		components_.push_back(buff);
		return buff;
	}

	template <typename type>
	type* AddComponent(type* component)
	{

		component->parent_ = this;
		components_.push_back(component);
		return component;
	}
};

