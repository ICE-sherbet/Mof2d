#pragma once
#include <vector>

#include "GameObject.h"
#include "Object.h"

class Scene : public Object
{
	std::vector<GameObject*> objects_;
public:
    ~Scene();

	GameObject* Instantiate();

	GameObject& Instantiate(GameObject obj);


	void Start() override;

	void Update() override;

	void Render() override;
};

