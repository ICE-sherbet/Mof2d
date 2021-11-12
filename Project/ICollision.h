#pragma once
#include "position.h"
class CollisionRect;
class CollisionCircle;
class CollisionPoint;

class ICollision
{
protected:
    const Vector2* position_ = nullptr;
public:
    ICollision(const Vector2* position) :position_(position){}
    void SetPosition(const Vector2* position)
    {
        position_ = position;
    }
    bool virtual CollisionHit(ICollision* collision) = 0;
    bool virtual CollisionHit(CollisionRect* rect) = 0;
    bool virtual CollisionHit(CollisionCircle* circle) = 0;
    bool virtual CollisionHit(CollisionPoint* point) = 0;
};

