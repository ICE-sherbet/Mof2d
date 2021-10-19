#include "kadai3.h"

kadai3& kadai3::set_input_(input_observer* input)
{
	input_ = input;
	return *this;
}

void kadai3::start()
{

	input_->move_observer->Subscribe([&](auto dir){MoveArrow(dir);});
	input_->fire_observer->Subscribe([&](auto key){KeyFire(key);});
	input_->mouse_observer->Subscribe([&](auto pos){MouseLeftClick();});
}

void kadai3::MoveArrow(Vector2& dir)
{
	entity[target]->move(dir * 5);
}

void kadai3::KeyFire(MofInt key)
{
	Vector2 dir(0,0);
	if(key==MOFKEY_W)dir.y -= 1;
	if(key==MOFKEY_A)dir.x -= 1;
	if(key==MOFKEY_S)dir.y += 1;
    if(key==MOFKEY_D)dir.x += 1;
    if(key==MOFKEY_SPACE)target ^= 1;
	entity[target]->move(dir * 100);
}

void kadai3::MouseLeftClick()
{
	entity[0]->getSprite()->next_sprite();
}

void kadai3::push(entity_2d* elem) {
    entity.push_back(elem);
}
