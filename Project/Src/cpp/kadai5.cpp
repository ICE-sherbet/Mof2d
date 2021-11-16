#include "kadai5.h"

void kadai5::Build(GameObject& target, CRectangle rect)
{
    const Vector2* pos = target.AddComponent<Position>()->LGetPosition();
    const Mof::Rectangle rectangle = (Mof::Rectangle)rect;
    ICollision* collision = new CollisionRect(pos, rectangle);
    target.AddComponent<Collider2D>(new Collider2D(collision));
}

void kadai5::Build(GameObject& target, CRectangle rect, Collider2D* mouse, IShapeStrategy* shape_pattern, MofU32 color)
{
    Build(target, rect);
    Shape& shape = target.AddComponent<Shape>()->SetShape(rect, color);
    target.GetComponent<Collider2D>()->TargetAdd(mouse);
    shape.SetShapePattern(shape_pattern);
}

void kadai5::Build(GameObject& target, CCircle Ccircle)
{
    const Vector2* pos = target.AddComponent<Position>()->LGetPosition();
    const Circle circle = (Circle)Ccircle;
    ICollision* collision = new CollisionCircle(pos, circle);
    target.AddComponent<Collider2D>(new Collider2D(collision));
}

void kadai5::Build(GameObject& target, CCircle circle, Collider2D* mouse, IShapeStrategy* shape_pattern, MofU32 color)
{
    Build(target, circle);
    Shape& shape = target.AddComponent<Shape>()->SetShape(circle, color);
    target.GetComponent<Collider2D>()->TargetAdd(mouse);
    shape.SetShapePattern(shape_pattern);
}

void kadai5::Kadai5Func(GameObject* object)
{
    if (click) {
        object->GetComponent<kadai5_1>()->change();
        click = false;
    }
}

void kadai5::Start()
{
    rect_mouse_ = parent_->Instantiate();
    Build(*rect_mouse_, { -1,-1,1,1 });
    rect_mouse_2 = parent_->Instantiate();
    Build(*rect_mouse_2, { -1,-1,1,1 });
    circle_mouse_ = parent_->Instantiate();
    Build(*circle_mouse_, { 0,0,5 });
    obj_rec1_ = parent_->Instantiate();
    obj_rec1_->AddComponent<kadai5_1>();
    Build(*obj_rec1_, rec1, rect_mouse_->GetComponent<Collider2D>(), new ShapeFillRect(), reccol);


    obj_cir_ = parent_->Instantiate();
    obj_cir_->AddComponent<kadai5_1>();
    Build(*obj_cir_, cir, circle_mouse_->GetComponent<Collider2D>(), new ShapeFillCircle(), reccol);

    rect_mouse_->GetComponent<Collider2D>()->TargetAdd(obj_rec1_->GetComponent<Collider2D>()).hit_objects->Subscribe(
        [&](auto obj) {Kadai5Func(obj); }
    );
    circle_mouse_->GetComponent<Collider2D>()->TargetAdd(obj_cir_->GetComponent<Collider2D>()).hit_objects->Subscribe(
        [&](auto obj) {Kadai5Func(obj); }
    );

    obj_rec2_ = parent_->Instantiate();
    auto kadai_rec2 = obj_rec2_->AddComponent<kadai5_3>();
    Build(*obj_rec2_, rec2, rect_mouse_2->GetComponent<Collider2D>(), new ShapeRect(), MOF_COLOR_BLACK);
    rect_mouse_2->GetComponent<Collider2D>()->TargetAdd(obj_rec2_->GetComponent<Collider2D>());


    obj_rec3_ = parent_->Instantiate();
    auto kadai_rec3 = obj_rec3_->AddComponent<kadai5_3>();
    Build(*obj_rec3_, rec3, rect_mouse_2->GetComponent<Collider2D>(), new ShapeRect(), MOF_COLOR_BLACK);
    rect_mouse_2->GetComponent<Collider2D>()->TargetAdd(obj_rec3_->GetComponent<Collider2D>());


    kadai_rec2->FriendSet(kadai_rec3);
    kadai_rec3->FriendSet(kadai_rec2);

    rect_mouse_2->GetComponent<Collider2D>()->hit_objects->Subscribe([&](auto obj) {
        obj->GetComponent<kadai5_3>()->change(count % 2);
        count++;
        }
    );
}

void kadai5::Update()
{
    count = 0;
    obj_rec2_->GetComponent<Shape>()->SetShapePattern(new ShapeRect());
    obj_rec3_->GetComponent<Shape>()->SetShapePattern(new ShapeRect());
    obj_rec2_->GetComponent<kadai5_3>()->changeColor(MOF_COLOR_WHITE);
    obj_rec3_->GetComponent<kadai5_3>()->changeColor(MOF_COLOR_WHITE);
}

kadai5& kadai5::SetInput(InputObserver* input)
{
    input_ = input;
    input_->mouse_observer->Subscribe([&](auto dir)
    {
        rect_mouse_2->GetComponent<Position>()->SetPosition(dir);
    });
    input_->mouse_push_observer->Subscribe([&](auto dir)
    {
        click = true;
        rect_mouse_->GetComponent<Position>()->SetPosition(dir);
        circle_mouse_->GetComponent<Position>()->SetPosition(dir);
    });
    return *this;
}
