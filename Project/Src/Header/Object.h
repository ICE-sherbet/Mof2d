#pragma once
#include "vector"

class Object
{
protected:
	Object* parent_ = nullptr;
	bool is_start_ = false;
	std::vector<Object*> child_;
    Object(Object* parent);
	Object();
public:
	virtual ~Object();

    virtual Object& GetRoot();
    virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};

