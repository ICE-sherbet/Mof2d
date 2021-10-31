#pragma once
#include "rigidbody.h"
#include "position.h"
#include "Component.h"
#include "Mof.h"


class RigidBody2D final : public Rigidbody,public Component
{
	Vector2 velocity_ = Vector2(0,0);
	Position* position_ = nullptr;
public:
	Vector2 GetVelocity() const;

	RigidBody2D& SetVelocity(const Vector2& velocity);

	RigidBody2D& RotateRight();

	RigidBody2D& RotateLeft();

	RigidBody2D(const Vector2& velocity);

	RigidBody2D();
	void Start() override;

	void Update() override;;
};

