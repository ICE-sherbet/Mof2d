#pragma once
#include <vector>

#include "GameObject.h"
#include "Object.h"

class Scene : public Object
{
	std::vector<GameObject*> objects_{ 0 };
public:
    ~Scene(){
        for (auto elem:objects_)
        {
            delete elem;
        }
    }
	GameObject& Instantiate()
	{
		GameObject* obj = new GameObject;
        objects_.emplace_back(obj);
		return *obj;
	}
    GameObject& Instantiate(GameObject obj)
    {
        objects_.emplace_back(&obj);
        return obj;
    }


	void Start() override
	{
        for (auto elem : objects_)
        {
            elem->Start();
        }
	}
	void Update() override
	{
        for (auto elem : objects_)
        {
            elem->Update();
        }
	}
	void Render() override
	{
        for (auto elem : objects_)
        {
            elem->Render();
        }
	}
};

