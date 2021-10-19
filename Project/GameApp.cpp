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
input_observer* input_observer_;
/*************************************************************************//*!
		@brief			アプリケーションの初期化
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Initialize(void){
	//リソースフォルダを指定
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
	world->update();
	for (auto obj : objct_list_) 
	{
		obj->update();
		
	}
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
	for (auto obj : objct_list_) {
		obj->render();
	}
	
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
	for (auto &obj : objct_list_)
	{
		delete obj;
	}
    delete world;
	return TRUE;
}