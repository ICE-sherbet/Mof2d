#include "entity_2d.h"

entity_2d::~entity_2d()
{
}

void entity_2d::update()
{


}

void entity_2d::start()
{

	position_ = parent_->get_component<position>();
	rigidbody2d_ = parent_->get_component<rigidbody2d>();
	sprite_ = parent_->get_component<sprite_renderer>();

}

void entity_2d::set_input_(input_observer *input) {
    input_ = input;


}

entity_2d &entity_2d::move(Vector2 dir) {
    position_->set_position(position_->get_position() + dir);
    return *this;
}

sprite_renderer *entity_2d::getSprite() const {
    return sprite_;
}
