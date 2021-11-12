#pragma once
#include "Mof.h"

class IShapeStrategy
{
public:
    virtual ~IShapeStrategy() = default;
    virtual void Draw(CRectangle* rect,MofU32 col) = 0;
};

