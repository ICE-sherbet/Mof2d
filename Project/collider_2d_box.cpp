#include "collider_2d_box.h"

CRectangle Collider2DBox::ColliderRectangle() const
{
	return collider_rectangle_;
}

Collider2DBox& Collider2DBox::SetDebug(bool debug)
{
	is_debug_ = debug;
	return *this;
}

Collider2DBox& Collider2DBox::SetColliderRectangle(const CRectangle& collider_rectangle)
{
	collider_rectangle_ = collider_rectangle;
	return *this;
}

Collider2DBox::Collider2DBox()
{
	Collider2DBox(CRectangle(0,0,0,0));
}

Collider2DBox::Collider2DBox(const CRectangle collider): collider_rectangle_(collider)
{}


bool Collider2DBox::CollisionInRect(const Collider2DBox& rect,const Vector2 vector = 0) const
{
	Mof::Rectangle r = rect.collider_rectangle_ + vector;
	if (collider_rectangle_.Left <= r.Left && r.Right <= collider_rectangle_.Right && collider_rectangle_.Top <= r.Top && r.Bottom <= collider_rectangle_.Bottom)
	{
		return TRUE;
	}

	rect.parent_->GetComponent<Collider2DBox>()->hit_objects->OnNext(*parent_);
	return FALSE;
}

Vector2 Collider2DBox::Radius() const
{
	return collider_rectangle_.GetCenter() -collider_rectangle_.GetTopLeft();
}

void Collider2DBox::Start()
{
	parent_->GetComponent<Position>()->position_sub->Subscribe(
		[&](Vector2 pos)->void { collider_rectangle_.SetPosition(pos - Radius()); }
	);
}

void Collider2DBox::Render()
{
	if (!is_debug_)return;
	CGraphicsUtilities::RenderRect(collider_rectangle_,MOF_XRGB(255,0,0));
}
