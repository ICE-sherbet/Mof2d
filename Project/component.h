#pragma once
#include "object.h"
class Object;

//�R���|�[�l���g�N���X
class Component
{
public:
	virtual ~Component() {}
	Object* parent_ = nullptr;
	virtual void Start() {}
	virtual void Update() {}
	virtual void Render() {}
};

