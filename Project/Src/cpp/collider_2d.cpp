#include "collider_2d.h"

Collider2D::Collider2D(ICollision* collision):collision_(collision)
{}

void Collider2D::Start()
{
    collision_->SetPosition(parent_->GetComponent<Position>()->LGetPosition());
}

void Collider2D::Update()
{
    if (!collision_)return;
    for (auto target : targets_)
    {
        if(!target->collision_)continue;
        if(collision_->CollisionHit(target->collision_))
        {
            hit_objects->OnNext(target->parent_);
        }
    }
}

Collider2D& Collider2D::TargetAdd(const Collider2D* target)
{
    targets_.emplace_back(target);
    return *this;
}

Collider2D::~Collider2D()
{
    delete hit_objects;
    delete collision_;
}
