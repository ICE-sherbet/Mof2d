#pragma once
#include "Component.h"
#include "input_observer.h"
#include "position.h"
#include "Shape.h"
#include "ShapeStrategy.h"
#include "Collision/collider_2d.h"

class kadai5_1 : public Component
{
    bool is_red_ = true;
public:

    void change()
    {
        is_red_ = !is_red_;
        parent_->GetComponent<Shape>()->SetColor(is_red_ ? MOF_COLOR_RED : MOF_COLOR_GREEN);
    }
};
class kadai5_3 : public Component
{
    bool is_fill_ = false;
    kadai5_3* frend_ = nullptr;
public:
    void FriendSet(kadai5_3* frend)
    {
        frend_ = frend;
    }
    void change(int count)
    {
        if (count == 0)
        {
            changeColor(MOF_COLOR_BLACK);
        }
        else {
            changeColor(MOF_COLOR_WHITE); frend_->changeColor(MOF_COLOR_WHITE);
        }
        parent_->GetComponent<Shape>()->SetShapePattern(new ShapeFillRect());
    }
    void changeColor(MofU32 col)
    {
        parent_->GetComponent<Shape>()->SetColor(col);
    }
};
class kadai5 : public Component
{

    //ï`âÊópèÓïÒ
    CRectangle	rec1{ 100, 100, 200, 200 };
    CRectangle	rec2{ 500, 400, 800, 600 };
    CRectangle	rec3{ 600, 500, 900, 700 };
    CCircle		cir{ 500, 150, 50 };
    //ï`âÊópêF
    MofU32		reccol = MOF_COLOR_RED;
    MofU32		circol = MOF_COLOR_RED;
    bool click = false;
    int count = 0;
    InputObserver* input_ = nullptr;
    GameObject* rect_mouse_ = nullptr;
    GameObject* rect_mouse_2 = nullptr;
    GameObject* circle_mouse_ = nullptr;
    GameObject* obj_rec1_ = nullptr;
    GameObject* obj_rec2_ = nullptr;
    GameObject* obj_rec3_ = nullptr;
    GameObject* obj_cir_ = nullptr;
    void Build(GameObject& target, CRectangle rect);

    void Build(GameObject& target, CRectangle rect, Collider2D* mouse, IShapeStrategy* shape_pattern, MofU32 color);

    static void Build(GameObject& target, CCircle Ccircle);

    void Build(GameObject& target, CCircle circle, Collider2D* mouse, IShapeStrategy* shape_pattern, MofU32 color);
public:
    void Kadai5Func(GameObject* object);

    void Start() override;

    void Update() override;

    kadai5& SetInput(InputObserver* input);
};

