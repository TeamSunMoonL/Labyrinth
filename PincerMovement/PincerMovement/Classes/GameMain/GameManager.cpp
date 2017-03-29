//************************************************/
//* @file  :gameManager.cpp
//* @brief :ゲームを管理するクラスのソースファイル
//* @date  :2017/03/29
//* @author:S.Katou
//************************************************/

// ヘッダファイルのインクルード
#include "GameManager.h"
#include <fstream>
#include <sstream>
#include "GameMain.h"
#include "../AI/Astar/Node.h"

using namespace std;

void GameManager::Update()
{
	//Mapクラスから基礎マップ情報を取得
	
	vector<int>::iterator itrY;
	vector<vector<int>>::iterator itrX;

	for (itrX = m_map.begin(); itrX != m_map.end(); itrX++)
	{
		for (itrY = itrX->begin(); itrY < itrX->end(); itrY++)
		{
			//マップデータコピー
			m_map;
		}
	}

	//プレイヤーの位置の属性を変更
	m_player;

	//敵の位置の属性を変更
	m_enemy;
}



/*--[以下隠蔽]--*/

GameManager::GameManager()
	:m_map(GameMain::MAP_Y,vector<int>(GameMain::MAP_X))
{

}

GameManager::~GameManager()
{

}
