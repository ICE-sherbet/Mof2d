#pragma once
#include "CollisionPoint.h"
#include "ICollision.h"
class CollisionPoint;
class CollisionCircle;
class ICollision;
class CollisionRect : public ICollision
{
    Mof::Rectangle rectangle_;
public:
    const Mof::Rectangle& GetRect() const
    {
        return rectangle_ + *position_;
    }
    CollisionRect(const Vector2* position) :ICollision(position)
    {
    }
    CollisionRect(const Vector2* position, const Mof::Rectangle& rectangle) :ICollision(position), rectangle_(rectangle)
    {
    }

    virtual bool CollisionHit(ICollision* collision)
    {
        collision->CollisionHit(this);
    }
protected:
    virtual bool CollisionHit(CollisionRect* rect)
    {
        return CRectangleUtilities::CollisionRect(GetRect(),rect->GetRect());
    }
    virtual bool CollisionHit(CollisionCircle* circle)
    {

    }
    virtual bool CollisionHit(CollisionPoint* point)
    {
        return CRectangleUtilities::CollisionPoint(GetRect(), point->GetPoint());
    }
};

