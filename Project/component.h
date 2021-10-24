#pragma once
#include "object.h"
class object;

//�R���|�[�l���g�N���X
class Component
{
public:
	virtual ~Component() {}
	object* parent_ = nullptr;
	virtual void start() {}
	virtual void update() {}
	virtual void render() {}
};

