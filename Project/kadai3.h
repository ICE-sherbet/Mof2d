#pragma once
#include "Component.h"
#include "input_observer.h"
#include "entity_2d.h"
#include "vector"

class kadai3 final :
    public Component
{
    std::vector<Entity2D*> entity = std::vector<Entity2D*>();
    int target = 0;
    InputObserver* input_ = nullptr;

    void MoveArrow(Vector2& dir);
    void KeyFire(MofInt key);
    void MouseLeftClick();
public:

    kadai3& set_input_(InputObserver *input);
    void push(Entity2D* entity);;
    void Start() override;


};

