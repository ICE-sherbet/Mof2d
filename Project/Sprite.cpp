#include "Sprite.h"

Sprite::Sprite(const LPTexture texture): texture_(texture)
{
	SetRect(CRectangle(Vector2(0,0),Vector2(texture->GetWidth(), texture->GetHeight())));
}

Sprite::Sprite(const LPTexture texture, const Vector2 pivot): texture_(texture),pivot_(pivot)
{
	SetRect(CRectangle(Vector2(0, 0), Vector2(texture->GetWidth(), texture->GetHeight())));
}

void Sprite::SetPivot(const Vector2 pivot)
{
	pivot_ = pivot;
}

void Sprite::SetRect(CRectangle texture_rect)
{
	texture_rect_ = texture_rect;
}

void Sprite::Render(const CRectangle position_rectangle) const
{
	texture_->Render(position_rectangle - texture_rect_ * pivot_, texture_rect_);
}

void Sprite::Render(const Vector2& position) const
{
	auto drag = texture_rect_ + position;
	texture_->Render(drag - texture_rect_.GetBottomRight() * pivot_, texture_rect_);
}

Sprite& Sprite::TextureLoad(const LPCMofChar path)
{
	if (texture_ == nullptr)texture_ = new CTexture;
	if (!texture_->Load(path))
	{

	}
	return *this;
}

Sprite& Sprite::TextureLoad(LPTexture texture)
{
	texture_ = texture;
	return *this;
}
