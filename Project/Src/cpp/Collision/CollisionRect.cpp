#include "Collision/CollisionRect.h"

const Mof::Rectangle CollisionRect::GetRect() const
{
    return rectangle_ + *position_;
}

CollisionRect::CollisionRect(const Vector2* position):ICollision(position)
{
}

CollisionRect::CollisionRect(const Vector2* position, const Mof::Rectangle& rectangle):ICollision(position), rectangle_(rectangle)
{
}

bool CollisionRect::CollisionHit(ICollision* collision)
{
    return collision->CollisionHit(this);
}

bool CollisionRect::CollisionHit(CollisionRect* rect)
{
    return  CRectangleUtilities::CollisionRect(rect->GetRect(), GetRect());;
}

bool CollisionRect::CollisionHit(CollisionCircle* circle)
{
    return false;
}

bool CollisionRect::CollisionHit(CollisionPoint* point)
{
    return CRectangleUtilities::CollisionPoint(GetRect(), point->GetPoint());
}
