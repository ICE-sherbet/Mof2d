#pragma once
#include "Mof.h"
#include "collider_2d.h"
#include "position.h"
#include "Component.h"

//短形の当たり判定クラス
class Collider2DBox : public Collider2D, public Component
{
	CRectangle collider_rectangle_;
	//デバッグ表示用
	bool is_debug_ = false;
public:
	subject<GameObject&>* hit_objects = new subject<GameObject&>();
	CRectangle ColliderRectangle() const;

	Collider2DBox& SetDebug(bool debug);
	Collider2DBox& SetColliderRectangle(const CRectangle& collider_rectangle);


	Collider2DBox(const CRectangle collider);
	Collider2DBox();

	bool CollisionInRect(const Collider2DBox& rect) const;
	bool CollisionInRect(const Collider2DBox& rect, const Vector2 vector) const;

	Vector2 Radius() const;

	void Start() override;
	void Render() override;
};
