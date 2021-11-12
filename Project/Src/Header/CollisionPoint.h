#pragma once
#include "CollisionCircle.h"
#include "CollisionRect.h"
#include "ICollision.h"

class CollisionPoint :
    public ICollision
{
    Vector2 offset_{ 0,0 };
public:
    const Vector2& GetPoint() const;

    CollisionPoint(const Vector2* position, const Vector2& offset);

    CollisionPoint(const Vector2* position);

    virtual bool CollisionHit(ICollision* collision);

    virtual bool CollisionHit(CollisionRect* rect);

    virtual bool CollisionHit(CollisionCircle* circle);

    virtual bool CollisionHit(CollisionPoint* point);
};

