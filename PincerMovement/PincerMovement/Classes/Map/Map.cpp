//************************************************/
//* @file  :Map.cpp
//* @brief :マップクラスのソースファイル
//* @date  :2017/03/30
//* @author:S.Katou
//************************************************/
#include "Map.h"
#include <fstream>
#include <sstream>

#include "../GameMain/GameMain.h"

using namespace std;

//＋ーーーーーーーーーーーーーー＋
//｜機能  :コンストラクタ
//｜引数  :マップの番号(int)
//＋ーーーーーーーーーーーーーー＋
Map::Map(int number)
	:m_map(GameMain::MAP_Y,vector<int>(GameMain::MAP_X))
{
	//マップのパス
	string mapPath;

	//マップのパスを設定
	switch (number)
	{
	case 0:	
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
void Map::Draw() const
{
	for (int i = 0; i < GameMain::MAP_Y; i++)
	{
		for (int j = 0; j < GameMain::MAP_X; j++)
		{
			switch (m_map[i][j])
			{
			//壁描画
			case O:		
				break;

			//通路描画
			case P:		
				break;

			default:
				break;
			}
		}
	}
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
	int data[GameMain::MAP_X*GameMain::MAP_Y];
	
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
	}
	
	// データを代入
	for (int i = 0; i < GameMain::MAP_Y; i++)
	{
		for (int j = 0; j < GameMain::MAP_X; j++)
		{
			int num = j + (i*j);

			// データを代入
			m_map[i][j] = data[num];
			
			//プレイヤーの初期位置を保存
			if (data[num] == PLAYER)
			{
				m_playerInitialPos.push_back(Tile{ i, j });
				m_map[i][j] = P;
			}

			//敵の初期位置を保存
			if (data[num] == ENEMY)
			{
				m_enemyInitialPos.push_back(Tile{ i, j });
				m_map[i][j] = P;
			}
		}
	}
}
