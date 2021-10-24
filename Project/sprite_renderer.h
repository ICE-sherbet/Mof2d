#pragma once
#include "Mof.h"
#include "vector"
#include "Component.h"
#include "position.h"

class sprite_renderer : public Component
{
private:
	// ���W
	const Vector2* position_ = nullptr;

    // ���S�_
    Vector2 pivot_ = Vector2(0.5f,0.5f);
    Vector2 size_;
    // �e�N�X�`��
	LPTexture lp_texture_ = nullptr;


	// �g��
	Vector2 scale_ = Vector2(1,1);

	// ��]�p
	Vector3 angle_ = Vector3(0,0,0);

	// ��`�`��
	CRectangle image_rect_;

	// ��`���X�g
    int index = 0;
	std::vector<CRectangle> rect_list_ = std::vector<CRectangle>(0);

	// �\��/��\��
	MofBool is_show_ = true;

public:
	sprite_renderer(const LPCMofChar path);

	sprite_renderer(LPTexture texture);

    sprite_renderer();

    ~sprite_renderer();

    const Vector2 &getPivot() const;

	sprite_renderer& setPivot(const Vector2 &pivot);

    sprite_renderer& texture_load(const LPCMofChar path);
    sprite_renderer& texture_load(LPTexture texture);

	CRectangle image_rect() const;

	sprite_renderer& set_image_rect(const CRectangle& image_rect);

	sprite_renderer& grid_split(int sx,int sy);

    Vector2 size();
    sprite_renderer& set_size(Vector2 vec);;

    void next_sprite();

	void start() override;

	void render() override;
};

