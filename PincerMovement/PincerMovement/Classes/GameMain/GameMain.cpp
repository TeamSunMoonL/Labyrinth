//************************************************/
//* @file  :GameMain.cpp
//* @brief :ゲーム本体のソース
//* @date  :2017/03/27
//* @author:S.Katou&K.Yamamoto
//************************************************/

// ヘッダファイルのインクルード
#define _USE_MATH_DEFINES // for C++  
#include <cmath>  

#include "GameMain.h"
#include "../Wrapper/Vec3/Vec3.h"
#include "../../Game.h"

const int GameMain::MAP_X;
const int GameMain::MAP_Y;
const int GameMain::CHIP_SIZE;

// 名前空間使用
using namespace ShunLib;

// 静的変数宣言
// デバイスリソース
std::shared_ptr<DX::DeviceResources> GameMain::m_deviceResources;

// コモンステート
DirectX::CommonStates* GameMain::m_state;

// スプライトバッチ
DirectX::SpriteBatch* GameMain::m_spriteBatch;

// スプライトフォント
DirectX::SpriteFont* GameMain::m_spriteFont;


GameMain::GameMain(std::shared_ptr<DX::DeviceResources> deviceResources)
{
	// リソース登録
	m_deviceResources = deviceResources;

	// コモンステート作成
	m_state = new DirectX::CommonStates(m_deviceResources->GetD3DDevice());

	// スプライトバッチ作成
	m_spriteBatch = new DirectX::SpriteBatch(m_deviceResources->GetD3DDeviceContext());

	// スプライトフォント作成
	m_spriteFont = new DirectX::SpriteFont(m_deviceResources->GetD3DDevice(), L"Font//myfile.spritefont");

	//ビュー座標の設定(位置,注視点,上方向)
	m_view = Matrix::CreateLookAt(Vec3(1 * 10 / 2.0f, 18.0f, 20.0f),
		Vec3(1 * 10 / 2.0f, 0.0f, 1 * 10 / 2.0f),
		Vec3(0.0f, 1.0f, 0.0f));
	
	float windowHeight = static_cast<float>(m_deviceResources->GetOutputSize().bottom);	// 画面の高さ
	float windowWidth = static_cast<float>(m_deviceResources->GetOutputSize().left);	// 画面の幅

	// プロジェクション行列設定
	m_proj = Matrix::CreateProj(M_PI_4, windowHeight / windowWidth, 0.1f, 1000.0f);

	// モデル作成
	m_model = new Model;
}

GameMain::~GameMain()
{
	// 動的変数破棄
	delete m_state;

	delete m_spriteBatch;

	delete m_spriteFont;
}

void GameMain::Update()
{

}

void GameMain::Render()
{

	
	// ワールド座標
	Matrix world = Matrix::Identity*Matrix::CreateTranslation(Vec3(0.0f, 0.0f, 0.0f));

	// モデルの描画
	m_model->Draw(world, m_view, m_proj);

}
