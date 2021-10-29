#include "position.h"

Position::Position(const Vector2 position_): position_(position_)
{}

Position::Position(float x, float y): position_(x,y)
{}

Vector2 Position::GetPosition() const
{
	return position_;
}

const Vector2* Position::LGetPosition() const
{
	return &position_;
}
Position& Position::Move(const Vector2& dir)
{
	position_ += dir;
	position_sub->OnNext(position_);
	return *this;
}
Position& Position::SetPosition(const Vector2& position)
{
	position_sub->OnNext(position);
	position_ = position;
	return *this;
}
