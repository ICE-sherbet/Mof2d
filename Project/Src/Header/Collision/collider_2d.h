#pragma once
#include "Component.h"
#include "ICollision.h"
#include "CollisionPoint.h"
#include "CollisionCircle.h"
#include "CollisionRect.h"
#include "CollisionPoint.h"
#include "Subject.h"

//TODO 何と衝突判定を行うかを管理するクラスを作成する

class Collider2D final : public Component
{
	ICollision* collision_ = nullptr;
	std::vector<const Collider2D*> targets_{};
public:

	subject<GameObject*>* hit_objects = new subject<GameObject*>();
	Collider2D(ICollision* collision);
	Collider2D() = default;
	void Start() override;

    void Update() override;

    Collider2D& TargetAdd(const Collider2D* target);

    ~Collider2D();
};
