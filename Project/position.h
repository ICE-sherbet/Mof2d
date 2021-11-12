#pragma once
#include "Component.h"
#include "Subject.h"

class Position final : public Component
{
	Vector2 position_ = Vector2(0, 0);
public:
	subject<Vector2>* position_sub = new subject<Vector2>();

	Position(const Vector2 position_);
	Position(float x,float y);
	Position();
	Vector2 GetPosition() const;
	const Vector2* LGetPosition() const;
	Position& Move(const Vector2& dir);

	Position& SetPosition(const Vector2& position);
};

