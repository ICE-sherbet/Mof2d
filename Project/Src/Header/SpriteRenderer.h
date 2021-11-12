#pragma once
#include "vector"
#include "Component.h"
#include "Sprite.h"
#include "position.h"
#include "Animator.h"
#include "IAnimatable.h"

class SpriteRenderer final : public Component,public IAnimatable<const Sprite*>
{
	// ���W
	const Vector2* position_ = nullptr;

	const Sprite* sprite_ = nullptr;
	const Sprite** pointer_sprite_ = nullptr;

	// �g��
	Vector2 scale_ = Vector2(1,1);

	// ��]�p
	Vector3 angle_ = Vector3(0,0,0);

	// ��`�`��͈�
	CRectangle image_rect_;
	

	// �\��/��\��
	bool is_show_ = true;

public:
	SpriteRenderer(const Sprite* sprite);

    SpriteRenderer();

	SpriteRenderer& SetSprite(const Sprite* sprite);


	const Sprite** GetTarget() override;
	void Start() override;

	void Render() override;
};

