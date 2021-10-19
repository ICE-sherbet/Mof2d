/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	��{�Q�[���A�v���B

															@author	�_�c�@��
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"

//CTexture�^�̕ϐ�gTexture��錾
mylib::HSV* bg_hsv_color_;
mylib::RGBA* bg_rgb_color_;

CTexture* g_texture = new CTexture;
CTexture* g_texture2 = new CTexture;
input_observer* input_observer_;
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void){
	//���\�[�X�t�H���_���w��
	CUtilities::SetCurrentDirectoryA("Resource");

	world = new object();
	world->add_component<position>(new position(0,0));
	input_observer_ = world->add_component<input_observer>();
	auto& kadai = world->add_component<kadai3>()->set_input_(input_observer_);
	world->start();
	
	g_texture->Load("texture01.png");
	g_texture2->Load("texture02.png");
	for (auto &obj: objct_list_) 
	{
		obj = new object();
        obj->add_component<rigidbody2d>();
		kadai.push(obj->add_component<entity_2d>());
	}
	objct_list_[0]->add_component<position>(new position(g_pGraphics->GetTargetWidth() / 2, g_pGraphics->GetTargetHeight() / 2));
	objct_list_[1]->add_component<position>(new position(0,0));
	objct_list_[0]->add_component<sprite_renderer>()->texture_load(g_texture).grid_split(2, 1);
	objct_list_[1]->add_component<sprite_renderer>()->setPivot(Vector2(0, 0)).texture_load(g_texture2);

	objct_list_[0]->start();
	objct_list_[1]->start();

	bg_hsv_color_ = new mylib::HSV(0, 1.0f, 1.0f);
	bg_rgb_color_ = new mylib::RGBA();
	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̍X�V
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Update(void){
	//�F��1�x���Z
	bg_hsv_color_->set_h(bg_hsv_color_->hue() + 1);
	//hsv��rgb�ɕϊ�
	bg_rgb_color_->to_convert(*bg_hsv_color_);
	world->update();
	for (auto obj : objct_list_) 
	{
		obj->update();
		
	}
	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̕`��
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Render(void){
	//�`��J�n
	g_pGraphics->RenderStart();
	//��ʂ̃N���A
	g_pGraphics->ClearTarget(bg_rgb_color_->red(), bg_rgb_color_->green(), bg_rgb_color_->blue(), 0.0f, 1.0f, 0);

	//�`��
	for (auto obj : objct_list_) {
		obj->render();
	}
	
	//�`��̏I��
	g_pGraphics->RenderEnd();
	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̉��
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Release(void){
	
	//�摜���\�[�X�����
	delete bg_hsv_color_;
	delete bg_rgb_color_;
	for (auto &obj : objct_list_)
	{
		delete obj;
	}
    delete world;
	return TRUE;
}