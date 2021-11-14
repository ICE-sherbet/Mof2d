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
    virtual ~ICollision();
    ICollision(const Vector2* position);

    void virtual SetPosition(const Vector2* position)
    {
        position_ = position;
    }
    bool virtual CollisionHit(ICollision* collision) = 0;
    bool virtual CollisionHit(CollisionRect* rect) = 0;
    bool virtual CollisionHit(CollisionCircle* circle) = 0;
    bool virtual CollisionHit(CollisionPoint* point) = 0;
};

inline ICollision::~ICollision() = default;

inline ICollision::ICollision(const Vector2* position):position_(position)
{}