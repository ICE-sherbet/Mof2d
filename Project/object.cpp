#include "object.h"

object::object()
{}

object::~object()
{
	for (auto elem:components_)
	{
		delete elem;
	}
}

void object::start()
{
	for (auto elem : components_)
	{
		elem->start();
	}
}

void object::update()
{
	for (auto elem : components_)
	{
		elem->update();
	}
}

void object::render()
{
	for (auto elem : components_)
	{
		elem->render();
	}
}


