#pragma once
#include "Component.h"
#include "ICollision.h"
#include "Subject.h"

//TODO ���ƏՓ˔�����s�������Ǘ�����N���X���쐬����

class Collider2D final : public Component
{
	ICollision* collision_ = nullptr;
	std::vector<const Collider2D*> targets_{};
public:

	subject<GameObject&>* hit_objects = new subject<GameObject&>();
	Collider2D(ICollision* collision);

	void Start() override;

    void Update() override;

    void TargetAdd(const Collider2D* target);

    ~Collider2D();
};
