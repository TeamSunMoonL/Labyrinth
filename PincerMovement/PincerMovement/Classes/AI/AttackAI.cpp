//************************************************/
//* @file  :AttackAI.h
//* @brief :1つのターゲットを追いかけるAIのソースファイル
//* @date  :2017/03/29
//* @author:S.Katou
//************************************************/
#include "../../pch.h"
#include "AttackAI.h"

//＋ーーーーーーーーーーーーーー＋
//｜機能  :コンストラクタ
//｜引数  :自分の属性(int)
//｜引数  :索敵範囲　(int)
//＋ーーーーーーーーーーーーーー＋
AttackAI::AttackAI(int attribute, int range)
	:AI(attribute,range)
{
	//ターゲット設定
	//(GameManagerから取得予定)
	

}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :更新処理
//｜引数  :なし(void)
//｜戻り値:なし(void)	
//＋ーーーーーーーーーーーーーー＋
void AttackAI::Update(const Tile& start)
{
	//現在位置更新
	m_start = start;

	//マップの更新
	m_map = m_manager->GetMap();

	//ルート上を索敵
	if (Search())
	{
		//ルート上に敵がいた場合
		//道筋の更新
		UpdateRoute();
	}
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :ルート上を索敵
//｜引数  :なし(void)
//｜戻り値:発見したらtrue(bool)	
//＋ーーーーーーーーーーーーーー＋
bool AttackAI::Search()
{
	//索敵するタイル
	Tile tile = m_route[m_next];

	//発見したかどうか
	bool isDiscovery = false;

	//ルート上に何かがいた場合trueを返す
	if (m_map[tile.row][tile.column] != P)
	{
		isDiscovery = true;
	}
	else
	{
		//いなかった場合　次のタイルを探す
		isDiscovery = Search(m_next + 1);
	}

	return isDiscovery;
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :索敵（再帰用）
//｜引数  :探すタイル番号(int)
//｜戻り値:発見したらtrue(bool)	
//＋ーーーーーーーーーーーーーー＋
bool AttackAI::Search(int num)
{
	//索敵範囲を超えていたら終了
	if (num >= m_next + m_searchRange)
	{
		return false;
	}

	//索敵するタイル
	Tile tile = m_route[num];

	//発見したかどうか
	bool isDiscovery = false;
	
	//ルート上に何かがいた場合trueを返す
	if (m_map[tile.row][tile.column] != P)
	{
		isDiscovery = true;
	}
	else
	{
		//いなかった場合　次のタイルを探す
		isDiscovery = Search(m_next + 1);
	}

	return isDiscovery;
}
