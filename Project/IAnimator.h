#pragma once
#include "Mof.h"
#include "array" 



struct AnimationFrame
{
	int frame_index = 0;
	int next_frame_time = 1;
};
struct AnimationClip
{
	std::vector<AnimationFrame> frame_info;
	std::vector<void*> animation_frame;
	size_t type_size = 0;
	bool is_loop = false;
	AnimationClip(bool loop);
};

class IAnimator
{
protected:

public:
	virtual void on_next_animation() = 0;
};