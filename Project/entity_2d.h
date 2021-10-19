#pragma once
#include "componen_headert.h"
#include "Mof.h"

//画像とオブジェクトに付属するコンポーネントを管理するクラス
//ToDo このクラスには他のコンポーネントを使用する以外の役割をもたないようにする。
class entity_2d : public component
{
	position* position_ = nullptr;
	collider_2d_box* collision_ = nullptr;
	rigidbody2d* rigidbody2d_ = nullptr;
    sprite_renderer* sprite_ = nullptr;
    input_observer* input_ = nullptr;
    bool can_control_ = false;
public:
    entity_2d()
    {
	    
    }
	~entity_2d();
    void set_input_(input_observer* input);
    entity_2d& move(Vector2 dir);

    sprite_renderer* getSprite() const;
	void update() override;
	void start() override;



};

