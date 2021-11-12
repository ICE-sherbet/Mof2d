#pragma once
#include "CollisionCircle.h"
#include "CollisionRect.h"
#include "ICollision.h"
class CollisionRect;
class CollisionCircle;
class ICollision;
class CollisionPoint :
    public ICollision
{
    Vector2 offset_{ 0,0 };
public:
    const Vector2& GetPoint() const
    {
        return offset_ + *position_;
    }
    CollisionPoint(const Vector2* position, const Vector2& offset):ICollision(position),offset_(offset)
    {
    }
    CollisionPoint(const Vector2* position) :ICollision(position)
    {
    }

    virtual bool CollisionHit(ICollision* collision)
    {
        
        return collision->CollisionHit(this);
    }
protected:
    virtual bool CollisionHit(CollisionRect* rect)
    {
        return CRectangleUtilities::CollisionPoint(rect->GetRect(), GetPoint());
    }
    virtual bool CollisionHit(CollisionCircle* circle)
    {
        return CCircleUtilities::CollisionPoint(circle->GetCircle(), GetPoint());
    }
    virtual bool CollisionHit(CollisionPoint* point)
    {
        return GetPoint() == point->GetPoint();
    }
};

