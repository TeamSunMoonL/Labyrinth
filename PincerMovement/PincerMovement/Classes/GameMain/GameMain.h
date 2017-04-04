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
#include "../Map/Map.h"

class GameMain
{
private:

	// ビュー行列
	ShunLib::Matrix m_view;

	// プロジェクション行列
	ShunLib::Matrix m_proj;
	
	//マップ
	ShunLib::Model* m_model;

	//壁モデル
	std::unique_ptr<DirectX::GeometricPrimitive> m_wall;

	Map* m_map;

public:
	//マップサイズ
	static const int MAP_X = 26;
	static const int MAP_Y = 16;
	 
	//マップチップサイズ
	static const int CHIP_SIZE = 1;

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