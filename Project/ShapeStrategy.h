#pragma once
#include "IShapeStrategy.h"
#include "Mof.h"
class ShapeRect :
    public IShapeStrategy
{
public:
    void Draw(CRectangle* rect,MofU32 col) override
    {
        CGraphicsUtilities::RenderRect(*rect, col);
    }
};

class ShapeFillRect :
    public IShapeStrategy
{
public:
    void Draw(CRectangle* rect, MofU32 col) override
    {
        CGraphicsUtilities::RenderFillRect(*rect, col);
    }
};

class ShapeCircle :
    public IShapeStrategy
{
public:
    void Draw(CRectangle* rect, MofU32 col) override
    {
        const Circle c{rect->GetCenter(),rect->GetWidth()/2.0f};
        CGraphicsUtilities::RenderCircle(c, col);
    }
};

class ShapeFillCircle :
    public IShapeStrategy
{
public:
    void Draw(CRectangle* rect, MofU32 col) override
    {
        const Circle c{ rect->GetCenter(),rect->GetWidth() / 2.0f };
        CGraphicsUtilities::RenderFillCircle(c, col);
    }
};
class ShapeLine :
    public IShapeStrategy
{
public:
    void Draw(CRectangle* rect, MofU32 col) override
    {
        CGraphicsUtilities::RenderLine(rect->GetTopLeft(),rect->GetBottomRight(), col);
    }
};