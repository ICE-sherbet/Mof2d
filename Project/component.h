#pragma once
#include "object.h"
class object;

//コンポーネントクラス
class Component
{
public:
	virtual ~Component() {}
	object* parent_ = nullptr;
	virtual void start() {}
	virtual void update() {}
	virtual void render() {}
};

