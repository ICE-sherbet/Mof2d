#pragma once
#include "Mof.h"
#include "subject.h"
#include "Component.h"
#include "functional"

#define LEFT_KEY MOFKEY_LEFT
#define RIGHT_KEY MOFKEY_RIGHT
#define UP_KEY MOFKEY_UP
#define DOWN_KEY MOFKEY_DOWN

struct KeyCommand{
    MofU8 Key;
    std::function<bool(MofU8)> identification;
    std::function<void(MofU8)> execute;
};

class InputObserver final : public Component
{
    CVector2 move_vec_{0,0};
    Vector2 dir_{0,0};

public:

    subject<Vector2&>* move_observer = new subject<Vector2&>;
    subject<Vector2&>* mouse_observer = new subject<Vector2&>;
    subject<MofInt>* fire_observer =  new subject<MofInt>;

    template<int KEY>
    void IsKeyPush() {
        if (g_pInput->IsKeyPush(KEY))fire_observer->OnNext(KEY);
    }
    void Update() override;

    ~InputObserver();
};

