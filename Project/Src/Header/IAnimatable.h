#pragma once

template<class T>
class IAnimatable
{
public:
	virtual T* GetTarget() = 0;
};

