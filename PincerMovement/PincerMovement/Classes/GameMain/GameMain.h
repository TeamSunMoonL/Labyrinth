//************************************************/
//* @file  :GameMain.h
//* @brief :ゲーム本体のヘッダー
//* @date  :2017/03/27
//* @author:S.Katou&K.Yamamoto
//************************************************/
#pragma once
#include <memory>
#include "../../pch.h"
#include "../../DeviceResources.h"

#include <CommonStates.h>
#include <SpriteFont.h>
#include <SpriteFont.h>

// テスト
#include "../Wrapper/Model/Model.h"
#include "../Wrapper/Matrix/Matrix.h"

class GameMain
{
private:

	// ビュー行列
	ShunLib::Matrix m_view;

	// プロジェクション行列
	ShunLib::Matrix m_proj;

	// モデル
	ShunLib::Model* m_model;

public:
	//マップサイズ
	static const int MAP_X = 25;
	static const int MAP_Y = 16;
	 
	//マップチップサイズ
	static const int CHIP_SIZE = 32;

	// デバイスリソース
	static std::shared_ptr<DX::DeviceResources> m_deviceResources;

	// コモンステート
	static DirectX::CommonStates* m_state;

	// スプライトバッチ
	static DirectX::SpriteBatch* m_spriteBatch;

	// スプライトフォント
	static DirectX::SpriteFont* m_spriteFont;

public:
	GameMain(std::shared_ptr<DX::DeviceResources> deviceResources);
	~GameMain();

	// 初期化
	void Initialize();

	//更新処理
	void Update();

	//描画処理
	void Render();
};