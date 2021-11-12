#include "input_observer.h"

void InputObserver::Update()
{
	g_pInput->RefreshKey();

    IsKeyPush<MOFKEY_A>();
    IsKeyPush<MOFKEY_W>();
    IsKeyPush<MOFKEY_S>();
    IsKeyPush<MOFKEY_D>();
    IsKeyPush<MOFKEY_SPACE>();

	g_pInput->GetMousePos(pos);
	if(g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON)){
		mouse_push_observer->OnNext(pos);
	}
	mouse_observer->OnNext(pos);
	if(g_pInput->IsKeyHold(LEFT_KEY))move_vec_.x -= 1;
	if(g_pInput->IsKeyHold(RIGHT_KEY))move_vec_.x += 1;
	if(g_pInput->IsKeyHold(UP_KEY))move_vec_.y -= 1;
	if(g_pInput->IsKeyHold(DOWN_KEY))move_vec_.y += 1;
	if(move_vec_.x == 0 && 0==move_vec_.y)return;
	dir_ = move_vec_ / move_vec_.Length();
	move_observer->OnNext(dir_);
	move_vec_ = Vector2(0, 0);
}

InputObserver::~InputObserver()
{
	delete move_observer;
	delete mouse_observer;
	delete fire_observer;
}

