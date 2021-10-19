#pragma once
#include "object.h"
class object;

//コンポーネントクラス
class component
{
public:
	virtual ~component() {}
	object* parent_ = nullptr;
	virtual void start() {}
	virtual void update() {}
	virtual void render() {}
};

