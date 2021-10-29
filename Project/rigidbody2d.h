#pragma once
#include "rigidbody.h"
#include "position.h"
#include "Component.h"
#include "Mof.h"

//�ړ��ʂȂǂ�Ǘ�����N���X
class Rigidbody2D : public Rigidbody,public Component
{
	Vector2 velocity_ = Vector2(0,0);
	const Vector2* positon_ = nullptr;
public:
	Vector2 GetVelocity() const;

	Rigidbody2D& SetVelocity(const Vector2& velocity);

	Rigidbody2D& RotateRight();

	Rigidbody2D& RotateLeft();

	Rigidbody2D(const Vector2& velocity);

	Rigidbody2D();
	void Start() override
	{
		
	}
	void Update() override
	{
		
	};
};

