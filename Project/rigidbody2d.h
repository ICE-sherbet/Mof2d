#pragma once
#include "rigidbody.h"
#include "component.h"
#include "Mof.h"

//移動量などを管理するクラス
class rigidbody2d : public rigidbody,public component
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

