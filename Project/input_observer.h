#pragma once
#include "Mof.h"
#include "subject.h"
#include "vector"
#include "Component.h"

#define LEFT_KEY MOFKEY_LEFT
#define RIGHT_KEY MOFKEY_RIGHT
#define UP_KEY MOFKEY_UP
#define DOWN_KEY MOFKEY_DOWN

class InputObserver final : public Component
{

    CVector2 move_vec_ = CVector2(0,0);
    Vector2 dir_;

public:

    subject<Vector2&>* move_observer = new subject<Vector2&>;
    subject<Vector2&>* mouse_observer = new subject<Vector2&>;
    subject<MofInt>* fire_observer =  new subject<MofInt>;

    void Update() override;

    ~InputObserver();
};

