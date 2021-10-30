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

}

void Entity2D::SetInput(InputObserver *input) {
    input_ = input;


}

Entity2D& Entity2D::Move(const Vector2 dir)
{
    position_->Move(dir);
    return *this;
}
