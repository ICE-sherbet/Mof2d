#pragma once
#include "IAnimator.h"

class Animator : public IAnimator
{
public:
	void on_next_animation() override
	{
		auto ani = AnimationClip(true);
	};
};
