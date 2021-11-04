/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	基本ゲームアプリ。

															@author	濱田　享
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"

//CTexture型の変数gTextureを宣言
mylib::HSV* bg_hsv_color_;
mylib::RGBA* bg_rgb_color_;

CTexture* g_texture = new CTexture;
CTexture* g_texture2 = new CTexture;

SpriteManager sprite_manager_ = SpriteManager();

Scene* root = new Scene;

InputObserver* input_observer_;


/*************************************************************************//*!
		@brief			アプリケーションの初期化
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Initialize(void){
	//リソースフォルダを指定
	CUtilities::SetCurrentDirectoryA("Resource");

	auto& world = root->Instantiate();
	world.AddComponent<Position>(new Position(0,0));
	input_observer_ = world.AddComponent<InputObserver>();
	auto& kadai = world.AddComponent<kadai3>()->set_input_(input_observer_);

	g_texture->Load("texture01.png");
	g_texture2->Load("texture02.png");
	auto frame = sprite_manager_.AddSpriteSlice(g_texture, 2, 1);
	std::vector<AnimationKeyFrame> frame_info = {{0,1},{1,1}};
	AnimationClipData<const Sprite*> clip_data = { frame_info,frame };
	AnimationClip<const Sprite*> clip;
	clip.SetClip(clip_data);
	sprite_manager_.AddSprite(new Sprite(g_texture2,Vector2(0,0)));

	auto& girl = root->Instantiate();
	auto& boy = root->Instantiate();
    girl.AddComponent<RigidBody2D>();

    girl.AddComponent<Position>(new Position(g_pGraphics->GetTargetWidth() / 2, g_pGraphics->GetTargetHeight() / 2));
    boy.AddComponent<Position>(new Position(0,0));
	auto sprite_render = girl.AddComponent<SpriteRenderer>()->SetSprite(sprite_manager_[0]);
	boy.AddComponent<SpriteRenderer>()->SetSprite(sprite_manager_[2]);
	auto animator = new Animator<const Sprite*>(&sprite_render);
    girl.AddComponent(animator)->PushBack(clip);
    kadai.animator_ = animator;

    kadai.push(&girl.AddComponent<Entity2D>()->SetInput(input_observer_));
    kadai.push(&boy.AddComponent<Entity2D>()->SetInput(input_observer_));

    root->Start();
	bg_hsv_color_ = new mylib::HSV(0, 1.0f, 1.0f);
	bg_rgb_color_ = new mylib::RGBA();
	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの更新
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Update(void){
	//色調1度加算
	bg_hsv_color_->set_h(bg_hsv_color_->hue() + 1);
	//hsvをrgbに変換
	bg_rgb_color_->to_convert(*bg_hsv_color_);

    root->Update();
	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの描画
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Render(void){
	//描画開始
	g_pGraphics->RenderStart();
	//画面のクリア
	g_pGraphics->ClearTarget(bg_rgb_color_->red(), bg_rgb_color_->green(), bg_rgb_color_->blue(), 0.0f, 1.0f, 0);

	//描画
    root->Render();
	
	//描画の終了
	g_pGraphics->RenderEnd();
	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの解放
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Release(void){
	
	//画像リソースを解放
	delete bg_hsv_color_;
	delete bg_rgb_color_;
	g_texture->Release();
	g_texture2->Release();

	return TRUE;
}