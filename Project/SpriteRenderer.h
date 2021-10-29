#pragma once
#include "vector"
#include "Component.h"
#include "Sprite.h"
#include "position.h"
#include "Animator.h"
#include "IAnimatable.h"

class SpriteRenderer final : public Component,public IAnimatable<const Sprite*>
{
	// À•W
	const Vector2* position_ = nullptr;

	const Sprite* sprite_ = nullptr;
	const Sprite** pointer_sprite_ = nullptr;

	// Šg‘å
	Vector2 scale_ = Vector2(1,1);

	// ‰ñ“]Šp
	Vector3 angle_ = Vector3(0,0,0);

	// ‹éŒ`•`‰æ”ÍˆÍ
	CRectangle image_rect_;
	

	// •\¦/”ñ•\¦
	bool is_show_ = true;

public:
	SpriteRenderer(const Sprite* sprite);

    SpriteRenderer();

	SpriteRenderer& SetSprite(const Sprite* sprite);


	const Sprite** GetTarget() override;
	void Start() override;

	void Render() override;
};

