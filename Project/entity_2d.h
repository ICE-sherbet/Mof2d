#pragma once
#include "position.h"
#include "input_observer.h"
#include "component.h"
#include "Mof.h"

//�摜�ƃI�u�W�F�N�g�ɕt������R���|�[�l���g���Ǘ�����N���X
//ToDo ���̃N���X�ɂ͑��̃R���|�[�l���g���g�p����ȊO�̖����������Ȃ��悤�ɂ���B
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

