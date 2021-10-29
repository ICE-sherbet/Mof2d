#pragma once
#include "componen_headert.h"
#include "Mof.h"

//�摜�ƃI�u�W�F�N�g�ɕt������R���|�[�l���g���Ǘ�����N���X
//ToDo ���̃N���X�ɂ͑��̃R���|�[�l���g���g�p����ȊO�̖����������Ȃ��悤�ɂ���B
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

