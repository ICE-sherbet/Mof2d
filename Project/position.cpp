#include "position.h"

position::position(const Vector2 position_): position_(position_)
{}

position::position(float x, float y): position_(x,y)
{}

Vector2 position::get_position() const
{
	return position_;
}

position& position::set_position(const Vector2& position)
{
	position_sub->OnNext(position);
	position_ = position;
	return *this;
}
