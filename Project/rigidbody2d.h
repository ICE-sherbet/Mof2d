#pragma once
#include "rigidbody.h"
#include "Component.h"
#include "Mof.h"

//�ړ��ʂȂǂ�Ǘ�����N���X
class rigidbody2d : public rigidbody,public Component
{
	Vector2 velocity_;
public:
	Vector2 velocity() const;

	rigidbody2d& set_velocity(const Vector2& velocity);

	rigidbody2d& rotateRight();

	rigidbody2d& rotateLeft();

	rigidbody2d(const Vector2& velocity);

	rigidbody2d();
};

