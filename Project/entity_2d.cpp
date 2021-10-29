#include "entity_2d.h"

Entity2D::~Entity2D()
{
}

void Entity2D::Update()
{


}

void Entity2D::Start()
{

	position_ = parent_->GetComponent<Position>();
	rigidbody2d_ = parent_->GetComponent<Rigidbody2D>();
	sprite_ = parent_->GetComponent<SpriteRenderer>();

}

void Entity2D::SetInput(InputObserver *input) {
    input_ = input;


}

Entity2D& Entity2D::Move(const Vector2 dir)
{
    position_->Move(dir);
    return *this;
}

SpriteRenderer *Entity2D::GetSprite() const {
    return sprite_;
}
