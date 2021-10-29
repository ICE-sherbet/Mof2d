#include "Rigidbody2D.h"

Vector2 Rigidbody2D::GetVelocity() const
{
	return velocity_;
}

Rigidbody2D& Rigidbody2D::SetVelocity(const Vector2& velocity)
{
	velocity_ = velocity;
	return *this;
}

Rigidbody2D& Rigidbody2D::RotateRight()
{
	velocity_ = Vector2(-velocity_.y, velocity_.x);
	return *this;
}

Rigidbody2D& Rigidbody2D::RotateLeft()
{
	velocity_ = Vector2(velocity_.y, -velocity_.x);
	return *this;
}

Rigidbody2D::Rigidbody2D(const Vector2& velocity): velocity_(velocity)
{
}

Rigidbody2D::Rigidbody2D()
{
	Rigidbody2D(Vector2(0,0));
}
