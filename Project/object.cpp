#include "Object.h"

Object::Object(Object* parent):parent_(parent)
{}

Object::Object()
{}

Object::~Object() = default;

Object& Object::GetRoot()
{

	if (!parent_) return *this;
	Object*& root = parent_;
	while (root->parent_)
	{
		root = root->parent_;
	}
	return *root;
}
