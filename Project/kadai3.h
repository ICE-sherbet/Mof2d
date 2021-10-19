#pragma once
#include "component.h"
#include "input_observer.h"
#include "entity_2d.h"
#include "vector"

class kadai3 final :
    public component
{
    std::vector<entity_2d*> entity = std::vector<entity_2d*>();
    int target = 0;
    input_observer* input_ = nullptr;

    void MoveArrow(Vector2& dir);
    void KeyFire(MofInt key);
    void MouseLeftClick();
public:

    kadai3& set_input_(input_observer *input);
    void push(entity_2d* entity);;
    void start() override;


};

