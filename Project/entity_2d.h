#pragma once
#include "componen_headert.h"
#include "Mof.h"

//�摜�ƃI�u�W�F�N�g�ɕt������R���|�[�l���g���Ǘ�����N���X
//ToDo ���̃N���X�ɂ͑��̃R���|�[�l���g���g�p����ȊO�̖����������Ȃ��悤�ɂ���B
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

