#include "Collider2DBox.h"

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
