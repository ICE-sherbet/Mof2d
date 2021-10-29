#pragma once
#include "object.h"
class Object;

//コンポーネントクラス
class Component
{
public:
	virtual ~Component() {}
	Object* parent_ = nullptr;
	virtual void Start() {}
	virtual void Update() {}
	virtual void Render() {}
};

