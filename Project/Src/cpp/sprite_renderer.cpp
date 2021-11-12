#include "SpriteRenderer.h"


SpriteRenderer::SpriteRenderer(const Sprite* sprite)
{
	sprite_ = sprite;
	pointer_sprite_ = &sprite_;
}


SpriteRenderer::SpriteRenderer()
{
	pointer_sprite_ = &sprite_;
};

SpriteRenderer& SpriteRenderer::SetSprite(const Sprite* sprite)
{
	sprite_ = sprite;
	return *this;
}

const Sprite** SpriteRenderer::GetTarget()
{
	return pointer_sprite_;
}

void SpriteRenderer::Start()
{
	position_ = parent_->GetComponent<Position>()->LGetPosition();
}


void SpriteRenderer::Render()
{
	sprite_->Render(*position_);
}

