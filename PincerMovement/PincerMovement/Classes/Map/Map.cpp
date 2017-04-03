//************************************************/
//* @file  :Map.cpp
//* @brief :マップクラスのソースファイル
//* @date  :2017/04/03
//* @author:S.Katou
//************************************************/
#include "Map.h"
#include <fstream>
#include <sstream>

#include "../AI/Astar/Astar.h"
#include "../GameMain/GameMain.h"
#include "../Wrapper/Vec3/Vec3.h"

using namespace std;
using namespace ShunLib;

//＋ーーーーーーーーーーーーーー＋
//｜機能  :コンストラクタ
//｜引数  :マップの番号(int)
//＋ーーーーーーーーーーーーーー＋
Map::Map(int number)
	:m_map(GameMain::MAP_Y,vector<int>(GameMain::MAP_X))
	, m_wall(DirectX::GeometricPrimitive::CreateBox(GameMain::m_deviceResources->GetD3DDeviceContext(), Vec3(1, 1, 1).GetDirectVec3()))
	, m_road(DirectX::GeometricPrimitive::CreateBox(GameMain::m_deviceResources->GetD3DDeviceContext(), Vec3(1, 1, 1).GetDirectVec3()))
{
	//マップのパス
	string mapPath;

	//マップのパスを設定
	switch (number)
	{
	case 0:	
		mapPath = "Map\\Map1.csv";
		break;
	default:
		break;
	}

	//csvからマップを読み込み
	LoadMap(mapPath);
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :デストラクタ
//＋ーーーーーーーーーーーーーー＋
Map::~Map()
{

}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :描画処理
//｜引数  :なし(void)
//｜戻り値:なし(void)
//＋ーーーーーーーーーーーーーー＋
void Map::Draw(const Matrix& world,
			   const Matrix& view,
			   const Matrix& proj)const
{
	for (int i = 0; i < GameMain::MAP_Y; i++)
	{
		for (int j = 0; j < GameMain::MAP_X; j++)
		{
			//座標設定
			Matrix w = world;
			w = w * Matrix::CreateTranslation(Vec3(static_cast<float>(j)*GameMain::CHIP_SIZE, 0.0f, static_cast<float>(i)*GameMain::CHIP_SIZE));
			
			switch (m_map[i][j])
			{
			//壁描画
			case O:		
				m_wall->Draw(w.GetDirectMatrix(), view.GetDirectMatrix(), proj.GetDirectMatrix(), DirectX::Colors::Gray);
				break;

			//通路描画
			case P:		
				m_road->Draw(w.GetDirectMatrix(), view.GetDirectMatrix(), proj.GetDirectMatrix(), DirectX::Colors::Brown);
				break;

			default:
				break;
			}
		}
	}


}



//＋ーーーーーーーーーーーーーー＋
//｜機能  :指定位置のマップの属性を取得
//｜引数  :座標(Tile)
//｜戻り値:属性(int)
//＋ーーーーーーーーーーーーーー＋
int Map::Get(const Tile& tile)
{
	return m_map[tile.row][tile.column]; 
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :指定したプレイヤーor敵の初期位置を取得
//｜引数  :PLAYER or ENEMY (int)
//｜引数  :オブジェクト番号(int)
//｜戻り値:初期位置(Tile)
//＋ーーーーーーーーーーーーーー＋
const Tile& Map::Get(int charactor, int num)
{
	Tile pos = { 0,0 };

	//敵orプレイヤーの初期位置を取得
	switch (charactor)
	{
	case PLAYER:
		pos = m_playerInitialPos[num];
		break;

	case ENEMY:
		pos = m_enemyInitialPos[num];
		break;
	default:
		break;
	}

	return pos;
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :csvからマップを読み込む
//｜引数  :csvのパス(string)
//｜戻り値:なし(void)
//＋ーーーーーーーーーーーーーー＋
void Map::LoadMap(string path)
{
	//データ読み込み用
	ifstream ifs(path);
	string str;
	const int MAP_MAX = GameMain::MAP_X*GameMain::MAP_Y;
	int data[MAP_MAX];
	
	int dataCnt = 0;

	//csvのデータをカンマを飛ばして読み込む
	while (getline(ifs, str))
	{
		string token;
		istringstream stream(str);

		while (getline(stream, token, ','))
		{
			data[dataCnt] = atoi(token.c_str());
			dataCnt++;
		}

		if (dataCnt >= MAP_MAX)
		{
			break;
		}
	}
	
	int num = 0;

	// データを代入
	for (int i = 0; i < GameMain::MAP_Y; i++)
	{
		for (int j = 0; j < GameMain::MAP_X; j++)
		{
			// データを代入
			m_map[i][j] = data[num];
			num++;

			//プレイヤーの初期位置を保存
			if (m_map[i][j] == PLAYER)
			{
				m_playerInitialPos.push_back(Tile{ i, j });
				m_map[i][j] = P;
			}

			//敵の初期位置を保存
			if (m_map[i][j] == ENEMY)
			{
				m_enemyInitialPos.push_back(Tile{ i, j });
				m_map[i][j] = P;
			}
		}
	}
}
