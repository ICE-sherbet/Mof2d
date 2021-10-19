#include "collider_2d_box.h"

CRectangle collider_2d_box::collider_rectangle() const
{
	return collider_rectangle_;
}

collider_2d_box& collider_2d_box::set_debug(bool debug)
{
	is_debug_ = debug;
	return *this;
}

collider_2d_box& collider_2d_box::set_collider_rectangle(const CRectangle& collider_rectangle)
{
	collider_rectangle_ = collider_rectangle;
	return *this;
}

collider_2d_box::collider_2d_box()
{
	collider_2d_box(CRectangle(0,0,0,0));
}

collider_2d_box::collider_2d_box(const CRectangle collider): collider_rectangle_(collider)
{}


bool collider_2d_box::CollisionInRect(const collider_2d_box& rect,const Vector2 vector = 0) const
{
	Mof::Rectangle r = rect.collider_rectangle_ + vector;
	if (collider_rectangle_.Left <= r.Left && r.Right <= collider_rectangle_.Right && collider_rectangle_.Top <= r.Top && r.Bottom <= collider_rectangle_.Bottom)
	{
		return TRUE;
	}

	rect.parent_->get_component<collider_2d_box>()->hit_objects->OnNext(*parent_);
	return FALSE;
}

Vector2 collider_2d_box::radius() const
{
	return collider_rectangle_.GetCenter() -collider_rectangle_.GetTopLeft();
}

void collider_2d_box::start()
{
	parent_->get_component<position>()->position_sub->Subscribe(
		[&](Vector2 pos)->void { collider_rectangle_.SetPosition(pos - radius()); }
	);
}

void collider_2d_box::render()
{
	if (!is_debug_)return;
	CGraphicsUtilities::RenderRect(collider_rectangle_,MOF_XRGB(255,0,0));
}
