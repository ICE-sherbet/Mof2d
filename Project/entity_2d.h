#pragma once
#include "position.h"
#include "input_observer.h"
#include "component.h"
#include "Mof.h"

//画像とオブジェクトに付属するコンポーネントを管理するクラス
//ToDo このクラスには他のコンポーネントを使用する以外の役割をもたないようにする。
class Entity2D : public Component
{
	Position* position_ = nullptr;
    InputObserver* input_ = nullptr;
public:
    Entity2D()
    {
	    
    }
	~Entity2D();
    void SetInput(InputObserver* input);
    Entity2D& Move(Vector2 dir);

	void Update() override;
	void Start() override;



};

