#include "input_observer.h"

void input_observer::update()
{
	g_pInput->RefreshKey();

	if (g_pInput->IsKeyPush(MOFKEY_A))fire_observer->OnNext(MOFKEY_A);
	if (g_pInput->IsKeyPush(MOFKEY_W))fire_observer->OnNext(MOFKEY_W);
	if (g_pInput->IsKeyPush(MOFKEY_S))fire_observer->OnNext(MOFKEY_S);
	if (g_pInput->IsKeyPush(MOFKEY_D))fire_observer->OnNext(MOFKEY_D);
	if (g_pInput->IsKeyPush(MOFKEY_SPACE))fire_observer->OnNext(MOFKEY_SPACE);

	if(g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON)){
		Vector2 pos;
		g_pInput->GetMousePos(pos);
		mouse_observer->OnNext(pos);
	}
	if(g_pInput->IsKeyHold(LEFT_KEY))move_vec.x -= 1;
	if(g_pInput->IsKeyHold(RIGHT_KEY))move_vec.x += 1;
	if(g_pInput->IsKeyHold(UP_KEY))move_vec.y -= 1;
	if(g_pInput->IsKeyHold(DOWN_KEY))move_vec.y += 1;
	if(move_vec.x == 0 && move_vec.x == move_vec.y)return;
	dir = move_vec / move_vec.Length();
	move_observer->OnNext(dir);
	move_vec = Vector2(0, 0);
}

input_observer::~input_observer()
{
	delete move_observer;
	delete mouse_observer;
	delete fire_observer;
}
