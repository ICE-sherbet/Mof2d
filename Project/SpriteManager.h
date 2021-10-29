#pragma once
#include "vector"
#include "Sprite.h"

class SpriteManager
{
	std::vector<Sprite*> sprites_ = std::vector<Sprite*>(0);
public:
	void Initialize()
	{
	}
	Sprite* AddSprite(Sprite* sprite);
	Sprite* AddSprite(const LPTexture texture);
	std::vector<const Sprite*> AddSpriteSlice(const LPTexture texture,int cel_x = 1,int cel_y = 1);

	const Sprite* operator[](int index);

	~SpriteManager();
};

