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
#include "../AI/AttackAI.h"

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

}

GameMain::~GameMain()
{
	// 動的変数破棄
	delete m_state;

	delete m_spriteBatch;

	delete m_spriteFont;

	delete m_map;

	delete m_tmpAI;

	delete m_tile;
}

// 初期化
void GameMain::Initialize()
{
	//ビュー座標の設定(位置,注視点,上方向)
	float x = MAP_X*CHIP_SIZE / 2.0f;
	float z = MAP_Y*CHIP_SIZE * 1.5f;
	m_view = Matrix::CreateLookAt(Vec3(x,20.0f,z),Vec3(x,0.0f,5.0f),Vec3(0.0f,1.0f,0.0f));

	float windowHeight = static_cast<float>(m_deviceResources->GetOutputSize().bottom);	// 画面の高さ
	float windowWidth = static_cast<float>(m_deviceResources->GetOutputSize().right);	// 画面の幅

	// プロジェクション行列設定 M_PI_4
	m_proj = Matrix::CreateProj(180.0f/4, windowWidth/windowHeight, 1.0f, 100.0f);

	// モデル作成
	m_model = new Model(m_deviceResources->GetD3DDevice(), L"CMedia\\robot.cmo");

	m_map = new Map(0);
	GameManager* manager = GameManager::GetInstance();
	manager->Register(m_map);

	m_tmpAI = new AttackAI(ENEMY);
	m_tmpAI->RandamTarget();
	m_tile = new Tile{ 1,1 };
}

int g_interval = 0;
float g_modelAngle = 0.0f;
float g_modelPosX = 0.0f;
float g_modelPosZ = 0.0f;

void GameMain::Update()
{
	g_interval++;

	if (g_interval >= 5)
	{
		m_tmpAI->Update(*m_tile);

		Tile next= m_tmpAI->GetNext();
	
		//ターゲットの位置まで来たら
		//ターゲット再決定
		if (m_tile->row == next.row
		  &&m_tile->column == next.column)
		{
			m_tmpAI->RandamTarget();
		}
		else
		{
			//方向転換
			if (m_tile->row != next.row)
			{
				g_modelAngle = 90.0f + 90.0f*(m_tile->row - next.row);
				g_modelPosX = 0.0f;
				g_modelPosZ = -(next.row - m_tile->row);
			}

			if(m_tile->column != next.column)
			{
				g_modelAngle = 90.0f*(m_tile->column - next.column);
				g_modelPosX = -(next.column - m_tile->column);
				g_modelPosZ = 0.0f;
			}
			*m_tile = next;
		}

		g_interval = 0;
	}
}

void GameMain::Render()
{

	// ワールド座標
	Matrix world;

	// 描画開始
	m_spriteBatch->Begin();


	float x = static_cast<float>(m_tile->column);
	float z = static_cast<float>(m_tile->row);

	Matrix modelAngle = Matrix::CreateRotationY(g_modelAngle);
	Matrix modelPos = modelAngle*Matrix::CreateTranslation(Vec3(x, 0.0f, z));
	
	// モデルの描画
	m_model->Draw(modelPos, m_view, m_proj);

	m_tmpAI->DrawDebug(m_view, m_proj);


	wchar_t str[128];
	swprintf(str, 128, L"test");
	m_spriteFont->DrawString(m_spriteBatch, str, DirectX::XMFLOAT2(10.0f, 10.0f));

	//マップ描画
	Matrix mapPos = Matrix::CreateTranslation(Vec3(0.0f, -1.5f, 0.0f));
	m_map->Draw(mapPos, m_view, m_proj);

	// 描画終わり
	m_spriteBatch->End();
}
