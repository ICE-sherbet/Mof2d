#include "RigidBody2D.h"

Vector2 RigidBody2D::GetVelocity() const
{
	return velocity_;
}

RigidBody2D& RigidBody2D::SetVelocity(const Vector2& velocity)
{
	velocity_ = velocity;
	return *this;
}

RigidBody2D& RigidBody2D::RotateRight()
{
	velocity_ = Vector2(-velocity_.y, velocity_.x);
	return *this;
}

RigidBody2D& RigidBody2D::RotateLeft()
{
	velocity_ = Vector2(velocity_.y, -velocity_.x);
	return *this;
}

RigidBody2D::RigidBody2D(const Vector2& velocity): velocity_(velocity)
{
}

RigidBody2D::RigidBody2D()
{
	RigidBody2D(Vector2(0,0));
}

void RigidBody2D::Start()
{
	position_ = parent_->GetComponent<Position>();
}

void RigidBody2D::Update()
{
	if (velocity_.x == velocity_.y == 0)return;
	position_->Move(velocity_);
}
