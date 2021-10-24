#pragma once
#include "object.h"
#include "Mof.h"
#include "Subject.h"

//���W��Ǘ�����N���X
class position : public Component
{
	Vector2 position_ = Vector2(0, 0);
public:
	subject<Vector2>* position_sub = new subject<Vector2>();

	position(const Vector2 position_);
	position(float x,float y);

	Vector2 get_position() const;
	Vector2* get_position_addres() 
	{
		return &position_;
	};

	position& set_position(const Vector2& position);
};

