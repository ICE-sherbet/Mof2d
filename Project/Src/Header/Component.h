#pragma once
#include "GameObject.h"
#include "Object.h"
class GameObject;

//コンポーネントクラス
class Component
{
public:
	virtual ~Component();
	GameObject* parent_ = nullptr;
	void virtual Start();
	void virtual Update();
	void virtual Render();
};

