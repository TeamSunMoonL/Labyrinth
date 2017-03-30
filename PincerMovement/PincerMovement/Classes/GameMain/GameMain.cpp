//************************************************/
//* @file  :GameMain.cpp
//* @brief :ゲーム本体のソース
//* @date  :2017/03/27
//* @author:S.Katou&K.Yamamoto
//************************************************/
#include "GameMain.h"

const int GameMain::MAP_X;
const int GameMain::MAP_Y;
const int GameMain::CHIP_SIZE;

// 静的変数宣言
// デバイスリソース
std::shared_ptr<DX::DeviceResources>    GameMain::m_deviceResources;

// コモンステート
DirectX::CommonStates* GameMain::m_state;

// スプライトバッチ
DirectX::SpriteBatch* GameMain::m_spriteBatch;

// スプライトフォント
DirectX::SpriteFont* GameMain::m_spriteFont;


GameMain::GameMain(std::shared_ptr<DX::DeviceResources>  deviceResources)
{
	// デバイスリソース作成
	m_deviceResources = deviceResources;

	// コモンステート作成
	m_state = new DirectX::CommonStates(m_deviceResources->GetD3DDevice());

	// スプライトバッチ作成
	m_spriteBatch = new DirectX::SpriteBatch(m_deviceResources->GetD3DDeviceContext());

	// スプライトフォント作成
	m_spriteFont = new DirectX::SpriteFont(m_deviceResources->GetD3DDevice(), L"Font//myfile.spritefont");

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

}
