#include "rigidbody2d.h"

Vector2 rigidbody2d::velocity() const
{
	return velocity_;
}

rigidbody2d& rigidbody2d::set_velocity(const Vector2& velocity)
{
	velocity_ = velocity;
	return *this;
}

rigidbody2d& rigidbody2d::rotateRight()
{
	velocity_ = Vector2(-velocity_.y, velocity_.x);
	return *this;
}

rigidbody2d& rigidbody2d::rotateLeft()
{
	velocity_ = Vector2(velocity_.y, -velocity_.x);
	return *this;
}

rigidbody2d::rigidbody2d(const Vector2& velocity): velocity_(velocity)
{
}

rigidbody2d::rigidbody2d()
{
	rigidbody2d(Vector2(0,0));
}
