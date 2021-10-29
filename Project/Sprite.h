#pragma once
#include "Mof.h"

class Sprite
{
    // ���S�_
    Vector2 pivot_ = Vector2(0.5f, 0.5f);
    LPTexture texture_ = nullptr;

    // �e�N�X�`������؂蔲���͈�
    CRectangle texture_rect_ = CRectangle(0,0,10,10);
public:
    Sprite(const LPTexture texture);

	Sprite(const LPTexture texture, const Vector2 pivot);


    void SetPivot(const Vector2 pivot);

    void SetRect(CRectangle texture_rect);
    void Render(const CRectangle position_rectangle) const;
    void Render(const Vector2& position) const;
    Sprite& TextureLoad(const LPCMofChar path);
    Sprite& TextureLoad(LPTexture texture);
};