#pragma once
#include "object.h"
class object;

//�R���|�[�l���g�N���X
class component
{
public:
	virtual ~component() {}
	object* parent_ = nullptr;
	virtual void start() {}
	virtual void update() {}
	virtual void render() {}
};

