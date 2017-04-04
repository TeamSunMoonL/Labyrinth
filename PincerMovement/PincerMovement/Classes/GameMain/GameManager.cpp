//************************************************/
//* @file  :GameManager.cpp
//* @brief :ゲームを管理するクラスのソースファイル
//* @date  :2017/04/04
//* @author:S.Katou
//************************************************/

// ヘッダファイルのインクルード
#include "GameManager.h"
#include <fstream>
#include <sstream>
#include "GameMain.h"
#include "../AI/Astar/Node.h"
#include "../Map/Map.h"

using namespace std;
void GameManager::Register(Map* map)
{
	m_map = map;
	m_attributeMap = m_map->Get();
}

//＋ーーーーーーーーーーーーーー＋
//｜機能  :更新処理
//｜引数  :なし(void)
//｜戻り値:なし(void)
//＋ーーーーーーーーーーーーーー＋
void GameManager::Update()
{
	//Mapクラスから基礎マップ情報を取得
	m_attributeMap = m_map->Get();

	//プレイヤーの位置の属性を変更
	m_player;

	//敵の位置の属性を変更
	m_enemy;
}



//＋ーーーーーーーーーーーーーー＋
//｜機能  :保管してあるデータを消去
//｜引数  :なし(void)
//｜戻り値:なし(void)
//＋ーーーーーーーーーーーーーー＋
void GameManager::Reset()
{
	m_player.clear();
	m_player.shrink_to_fit();
	m_enemy.clear();
	m_enemy.shrink_to_fit();
	m_target.clear();
	m_target.shrink_to_fit();

}


/*--[以下隠蔽]--*/

GameManager::GameManager()
	:m_attributeMap(GameMain::MAP_Y,vector<int>(GameMain::MAP_X))
{

}

GameManager::~GameManager()
{

}
