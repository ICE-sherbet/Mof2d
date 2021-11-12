#pragma once
#include "CollisionPoint.h"
#include "ICollision.h"

class CollisionCircle : public ICollision
{

    Circle circle_;
public:
    const Circle& GetCircle() const;

    CollisionCircle(const Vector2* position);

    CollisionCircle(const Vector2* position, const Circle& circle);

    virtual bool CollisionHit(ICollision* collision);

    virtual bool CollisionHit(CollisionRect* rect);

    virtual bool CollisionHit(CollisionCircle* circle);

    virtual bool CollisionHit(CollisionPoint* point);
};

