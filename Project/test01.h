#pragma once
#include "Mof.h"
#include "entity_2d.h"
class test01
{
	Vector3 pos = Vector3(1,0,0);
	Vector3 vel = Vector3(0, 1, 0);
	Vector3 pivot = Vector3(0, 0, 1);
	entity_2d entity_ = entity_2d();
public:
	void update()
	{
		pos = vel + pivot;
	}
};

class test02
{
	Vector3 pos = Vector3(1, 0, 0);
	Vector3 vel = Vector3(0, 1, 0);
	Vector3 pivot = Vector3(0, 0, 1);
public:
	test02()
	{
		
	};

	void update()
	{
		pos = vel + pivot;
	}
};