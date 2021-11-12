#pragma once
#include "CollisionPoint.h"
#include "ICollision.h"

class CollisionCircle : public ICollision
{

    Circle circle_;
public:
    const Circle& GetCircle() const
    {
        return circle_ + *position_;
    }
    CollisionCircle(const Vector2* position) :ICollision(position)
    {
    }
    CollisionCircle(const Vector2* position, const Circle& circle) :ICollision(position),circle_(circle)
    {
    }
    virtual bool CollisionHit(ICollision* collision)
    {
        return collision->CollisionHit(this);
    }
protected:
    virtual bool CollisionHit(CollisionRect* rect) 
    {
        
    }
    virtual bool CollisionHit(CollisionCircle* circle)
    {
        return CCircleUtilities::CollisionCircle(GetCircle(), circle->GetCircle());
    }
    virtual bool CollisionHit(CollisionPoint* point)
    {
        return CCircleUtilities::CollisionPoint(GetCircle(), point->GetPoint());
    }
};

