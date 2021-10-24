#pragma once
#include "Mof.h"
#include "collider_2d.h"
#include "position.h"
#include "Component.h"

//短形の当たり判定クラス
class collider_2d_box : public collider_2d, public Component
{
	CRectangle collider_rectangle_;
	//デバッグ表示用
	bool is_debug_ = false;
public:
	subject<object&>* hit_objects = new subject<object&>();
	CRectangle collider_rectangle() const;

	collider_2d_box& set_debug(bool debug);
	collider_2d_box& set_collider_rectangle(const CRectangle& collider_rectangle);


	collider_2d_box(const CRectangle collider);
	collider_2d_box();

	bool CollisionInRect(const collider_2d_box& rect) const;
	bool CollisionInRect(const collider_2d_box& rect, const Vector2 vector) const;

	Vector2 radius() const;

	void start() override;
	void render() override;
};
