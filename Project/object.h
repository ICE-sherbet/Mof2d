#pragma once
#include <list>
#include "Mof.h"
#include "component.h"
class component;

//オブジェクトクラス
class object
{
	std::list<component*> components_;
public:
	object();

	~object();

	void start();

	void update();

	void render();

	template <typename type>
	type* get_component()
	{
		for (auto elem : components_)
		{
			type* buff = dynamic_cast<type*>(elem);
			if (buff != nullptr) return buff;
		}
		return nullptr;
	}

	template <typename type>
	type* add_component()
	{
		type* buff = new type();
		buff->parent_ = this;
		components_.push_back(buff);
		return buff;
	}

	template <typename type>
	type* add_component(type* component)
	{

		component->parent_ = this;
		components_.push_back(component);
		return component;
	}
};

