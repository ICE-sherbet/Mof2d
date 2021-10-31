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

InputObserver* input_observer_;
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void){
	//���\�[�X�t�H���_���w��
	CUtilities::SetCurrentDirectoryA("Resource");

	world = new GameObject();
	world->AddComponent<Position>(new Position(0,0));
	input_observer_ = world->AddComponent<InputObserver>();
	auto& kadai = world->AddComponent<kadai3>()->set_input_(input_observer_);
	world->Start();

	g_texture->Load("texture01.png");
	g_texture2->Load("texture02.png");
	auto frame = sprite_manager_.AddSpriteSlice(g_texture, 2, 1);
	std::vector<AnimationKeyFrame> frame_info = {{0,1},{1,1}};
	AnimationClipData<const Sprite*> clip_data = { frame_info,frame };
	AnimationClip<const Sprite*> clip;
	clip.SetClip(clip_data);
	sprite_manager_.AddSprite(new Sprite(g_texture2,Vector2(0,0)));
	
	
	for (auto &obj: objct_list_) 
	{
		obj = new GameObject();
        obj->AddComponent<RigidBody2D>();
		kadai.push(obj->AddComponent<Entity2D>());
	}
	objct_list_[0]->AddComponent<Position>(new Position(g_pGraphics->GetTargetWidth() / 2, g_pGraphics->GetTargetHeight() / 2));
	objct_list_[1]->AddComponent<Position>(new Position(0,0));
	auto sprite_render = objct_list_[0]->AddComponent<SpriteRenderer>()->SetSprite(sprite_manager_[0]);
	objct_list_[1]->AddComponent<SpriteRenderer>()->SetSprite(sprite_manager_[2]);
	auto animator = new Animator<const Sprite*>(&sprite_render);
    objct_list_[0]->AddComponent(animator)->PushBack(clip);
    kadai.animator_ = animator;
	objct_list_[0]->Start();
	objct_list_[1]->Start();

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
	world->Update();
	for (auto obj : objct_list_) 
	{
		obj->Update();
		
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
		obj->Render();
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
	g_texture->Release();
	g_texture2->Release();
	for (auto &obj : objct_list_)
	{
		delete obj;
	}
    delete world;
	return TRUE;
}