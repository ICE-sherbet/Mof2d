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
        if(target->collision_)continue;
        collision_->CollisionHit(target->collision_);
    }
}

void Collider2D::TargetAdd(const Collider2D* target)
{
    targets_.emplace_back(target);
}

Collider2D::~Collider2D()
{
    delete hit_objects;
    delete collision_;
}
