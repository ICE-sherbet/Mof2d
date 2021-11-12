#pragma once
#include "Component.h"
#include "IShapeStrategy.h"
#include "position.h"

class Shape : public Component
{
    IShapeStrategy* shape_ = nullptr;
    CRectangle rectangle_;
    MofU32 color_ = MOF_XRGB(255,255,255);
    const Vector2* position_ = nullptr;
public:
    ~Shape()
    {

    }
    Shape()
    {

    }
    Shape& SetShape(CRectangle rectangle)
    {
        rectangle_ = rectangle;
        return *this;
    }
    Shape& SetShape(CRectangle rectangle, MofU32 color)
    {
        rectangle_ = rectangle;
        color_ = color;
        return *this;
    }
    Shape& SetShapePattern(IShapeStrategy* shape)
    {
        shape_ = shape;
        return *this;
    }
    void Start() override
    {
        position_ = parent_->GetComponent<Position>()->LGetPosition();
    }
    void Render() override
    {
        if(shape_ && position_)
        {
            CRectangle rect = rectangle_ + *position_;
            shape_->Draw(&rect,color_);
        }
    };
};

