#pragma once
#include <utility>

#include "Mof.h"
#include "array" 



struct AnimationKeyFrame
{
	int frame_index = 0;
	int next_frame_time = 1;
};
template<class T>
class AnimationClip
{
	std::vector<AnimationKeyFrame> frame_info_ = std::vector<AnimationKeyFrame>();
	std::vector<T*> animation_frame_ = std::vector<T*>();
	bool is_loop_ = false;
	int now_frame_ = 0;
	int wait_count_ = 0;
public:
	AnimationClip(std::vector<T*> frames):animation_frame_(std::move(frames)){}
	AnimationClip(std::vector<T*> frames, std::vector<AnimationKeyFrame> info):
		frame_info_(std::move(info)), animation_frame_(std::move(frames)) {}
	void next_frame()
	{
		if(frame_info_[now_frame_].next_frame_time <= wait_count_)
		{
			
		}

		wait_count_++;
	}
	void change_frame(int target_index)
	{
		if (target_index < 0 && target_index >= animation_frame_.size())return;
		now_frame_ = target_index;
	}

};

template<class T>
class Animator
{
protected:
	std::vector<AnimationClip<T>> animation_clip_ = std::vector<AnimationClip<T>>();
	int clip_num_ = 0;
	T* target_ = nullptr;
public:
	void push_back(const AnimationClip<T>& clip)
	{
		animation_clip_.emplace_back(clip);
	}
	T* on_next_frame() override
	{
		if (animation_clip_.empty())return nullptr;
		animation_clip_[clip_num_]
		return target_;
	}
	T* get_frame() override
	{

	};
};