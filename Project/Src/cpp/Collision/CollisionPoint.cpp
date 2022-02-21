#include "Collision/CollisionPoint.h"

const Mof::Vector2 CollisionPoint::GetPoint() const
{
    return offset_ + *position_;
}

CollisionPoint::CollisionPoint(const Vector2* position, const Vector2& offset):ICollision(position),offset_(offset)
{
}

CollisionPoint::CollisionPoint(const Vector2* position):ICollision(position)
{
}

bool CollisionPoint::CollisionHit(ICollision* collision)
{
        
    return collision->CollisionHit(this);
}

bool CollisionPoint::CollisionHit(CollisionRect* rect)
{
    return CRectangleUtilities::CollisionPoint(rect->GetRect(), GetPoint());
}

bool CollisionPoint::CollisionHit(CollisionCircle* circle)
{
    return CCircleUtilities::CollisionPoint(circle->GetCircle(), GetPoint());
}

bool CollisionPoint::CollisionHit(CollisionPoint* point)
{
    return GetPoint() == point->GetPoint();
}
