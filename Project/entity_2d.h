#pragma once
#include "componen_headert.h"
#include "Mof.h"

//画像とオブジェクトに付属するコンポーネントを管理するクラス
//ToDo このクラスには他のコンポーネントを使用する以外の役割をもたないようにする。
class Entity2D : public Component
{
	Position* position_ = nullptr;
	Collider2DBox* collision_ = nullptr;
	Rigidbody2D* rigidbody2d_ = nullptr;
    SpriteRenderer* sprite_ = nullptr;
    InputObserver* input_ = nullptr;
    bool can_control_ = false;
public:
    Entity2D()
    {
	    
    }
	~Entity2D();
    void SetInput(InputObserver* input);
    Entity2D& Move(Vector2 dir);

    SpriteRenderer* GetSprite() const;
	void Update() override;
	void Start() override;



};

