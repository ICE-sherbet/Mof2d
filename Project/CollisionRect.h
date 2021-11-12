#pragma once
#include "CollisionPoint.h"
#include "ICollision.h"

class CollisionRect : public ICollision
{
    Mof::Rectangle rectangle_;
public:
    const Mof::Rectangle& GetRect() const;

    CollisionRect(const Vector2* position);

    CollisionRect(const Vector2* position, const Mof::Rectangle& rectangle);

    virtual bool CollisionHit(ICollision* collision);

    virtual bool CollisionHit(CollisionRect* rect);

    virtual bool CollisionHit(CollisionCircle* circle);

    virtual bool CollisionHit(CollisionPoint* point);
};

