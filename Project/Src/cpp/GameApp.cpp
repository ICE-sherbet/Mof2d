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

SpriteManager sprite_manager_ = SpriteManager();

Scene* root = new Scene;


/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void){
	//���\�[�X�t�H���_���w��
	CUtilities::SetCurrentDirectoryA("Resource");

	auto world = root->Instantiate();
	world->AddComponent<Position>(new Position(0,0));
	InputObserver* input_observer_ = world->AddComponent<InputObserver>();
	auto kadai = world->AddComponent<kadai5>();
	kadai->SetInput(input_observer_);
    root->Start();
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

    root->Update();
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
	CGraphicsUtilities::RenderFillRect(0,0,10,1,MOF_XRGB(255,255,255));
	CGraphicsUtilities::RenderLine(12,1,20,1,MOF_XRGB(255,255,255));
	//�`��
    root->Render();
	
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
	delete root;
	g_texture->Release();
	g_texture2->Release();

	return TRUE;
}