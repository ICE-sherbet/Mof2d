
#include "Collision/CollisionCircle.h"

const Circle CollisionCircle::GetCircle() const
{
    return circle_ + *position_;
}

CollisionCircle::CollisionCircle(const Vector2* position):ICollision(position)
{
}

CollisionCircle::CollisionCircle(const Vector2* position, const Circle& circle):ICollision(position),circle_(circle)
{
}

bool CollisionCircle::CollisionHit(ICollision* collision)
{
    return collision->CollisionHit(this);
}

bool CollisionCircle::CollisionHit(CollisionRect* rect)
{
    return false;
}

bool CollisionCircle::CollisionHit(CollisionCircle* circle)
{
    return CCircleUtilities::CollisionCircle(GetCircle(), circle->GetCircle());
}

bool CollisionCircle::CollisionHit(CollisionPoint* point)
{
    return CCircleUtilities::CollisionPoint(GetCircle(), point->GetPoint());
}
