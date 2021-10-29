#pragma once
#include "vector"
#include "Component.h"
#include "IAnimatable.h"
#include "SpriteRenderer.h"

struct AnimationKeyFrame
{
	int frame_index = 0;
	int next_frame_time = 1;
};

template<class T>
struct AnimationClipData
{
	std::vector<AnimationKeyFrame> frame_info;
	std::vector<T> animation_frame;
	bool is_loop_ = false;
	T& GetFrame(const int index);
};

template<class T>
class AnimationClip
{
	AnimationClipData<T> animation_clip_data_;
	int now_frame_ = 0;
	int wait_count_ = 0;
public:
	AnimationClip() {};

	AnimationClip(AnimationClipData<T> info);
	void SetClip(AnimationClipData<T> info)
	{
		animation_clip_data_ = info;
	}
	T& NextFrame();

	void ChangeFrame(int target_index);

	T& GetFrame();
};


template<class T>
class Animator : public Component
{
protected:
	std::vector<AnimationClip<T>> animation_clip_ = std::vector<AnimationClip<T>>();
	int clip_num_ = 0;
	T* target_ = nullptr;
public:
	Animator(IAnimatable<T>* target);
	void PushBack( AnimationClip<T> clip);

	T& OnNextFrame();

	T& GetFrame();
};



template <class T>
T& AnimationClipData<T>::GetFrame(const int index)
{
	return animation_frame[frame_info[index].frame_index];
}

template <class T>
AnimationClip<T>::AnimationClip(const AnimationClipData<T> info) :
	animation_clip_data_(info)
{}

template <class T>
T& AnimationClip<T>::NextFrame()
{
	if (animation_clip_data_.frame_info[now_frame_].next_frame_time <= ++wait_count_)
	{
		ChangeFrame(now_frame_ + 1);
	}

	return GetFrame();
}

template <class T>
void AnimationClip<T>::ChangeFrame(int target_index)
{
	if (target_index < 0 && target_index >= animation_clip_data_.animation_frame.size())return;
	wait_count_ = 0;
	now_frame_ = target_index;
	now_frame_ %= animation_clip_data_.animation_frame.size();
}

template <class T>
T& AnimationClip<T>::GetFrame()
{
	return animation_clip_data_.GetFrame(now_frame_);
}

template <class T>
Animator<T>::Animator(IAnimatable<T>* target)
{
	target_ = target->GetTarget();
}

template <class T>
void Animator<T>::PushBack(AnimationClip<T> clip)
{
	animation_clip_.emplace_back(clip);
	*target_ = clip.NextFrame();
	int a = 1;
}

template <class T>
T& Animator<T>::OnNextFrame()
{
	if (animation_clip_.empty())return nullptr;
	*target_ = &animation_clip_[clip_num_].NextFrame();

	return target_;
}

template <class T>
T& Animator<T>::GetFrame()
{
	return target_;
}