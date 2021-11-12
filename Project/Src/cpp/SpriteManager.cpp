#include "SpriteManager.h"

#include <iterator>

Sprite* SpriteManager::AddSprite(Sprite* sprite)
{
	sprites_.emplace_back(sprite);
	return sprite;
}

Sprite* SpriteManager::AddSprite(const LPTexture texture)
{
	auto sprite = new Sprite(texture);
	sprites_.emplace_back(sprite);
	return sprite;
}
std::vector<const Sprite*> SpriteManager::AddSpriteSlice(const LPTexture texture, int cel_x, int cel_y)
{
	auto result = std::vector<const Sprite*>();
	float texture_width = texture->GetWidth() / cel_x;
	float texture_height = texture->GetHeight() / cel_y;
	auto rect = CRectangle(0, 0, texture_width, texture_height);
	
	for (int y = 0; y < cel_y; ++y)
	{
		for (int x = 0; x < cel_x; ++x)
		{
			rect.SetPosition({ texture_width * x,texture_height * y });
			auto sprite = new Sprite(texture);
			sprite->SetRect(rect);
			sprites_.emplace_back(sprite);
		}
	}
	auto last = sprites_.end();
	std::copy(last - (cel_y*cel_x), last, std::back_inserter(result));
	return result;
}
const Sprite* SpriteManager::operator[](int index)
{
	return sprites_[index];
}

SpriteManager::~SpriteManager()
{
	for (auto& elem:sprites_)
	{
		delete elem;
	}
}
