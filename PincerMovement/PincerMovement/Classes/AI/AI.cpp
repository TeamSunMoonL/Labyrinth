//************************************************/
//* @file  :AI.cpp
//* @brief :AIのソースファイル
//* @date  :2017/03/27
//* @author:S.Katou
//************************************************/
#include "AI.h"
#include "Astar\Astar.h"
#include "../../Game.h"


//＋ーーーーーーーーーーーーーー＋
//｜機能  :コンストラクタ
//｜引数  :自分の属性(int)
//｜引数  :索敵範囲　(int)
//＋ーーーーーーーーーーーーーー＋
AI::AI(int attribute, int range)
	:m_attribute(attribute)
	,m_searchRange(range)
{

}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :次に移動する座標を取得
//｜引数  :なし(void)
//｜戻り値:座標(Tile)	
//＋ーーーーーーーーーーーーーー＋
Tile AI::GetNext()
{
	//次に進む座標を取得
	Tile nextTile = m_route[m_next];

	//次の座標が進行不可能ならば
	if (m_map[nextTile.row][nextTile.column] != P)
	{
		//元の位置を返す
		nextTile = m_route[m_next - 1];
	}
	else
	{
		//進行可能ならば
		//次へ進める
		m_next++;
	}

	//座標を返す
	return nextTile;
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :属性マップの更新処理
//｜引数  :なし(void)
//｜戻り値:なし(void)	
//＋ーーーーーーーーーーーーーー＋
void AI::UpdateAttributeMap()
{

}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :道筋の更新処理
//｜引数  :なし(void)
//｜戻り値:なし(void)	
//＋ーーーーーーーーーーーーーー＋
void AI::UpdateRoute()
{
	if (ShouldUpdateRoute())
	{
		//A*法
		AStar astar;

		//初期化
		astar.Initialize(m_map, m_start, m_target);

		//探索
		astar.Search();

		//道筋を取得
		m_route = astar.GetRoute();

		//終了処理
		astar.Finalize();
	
		//次に進む座標をリセット
		m_next = 0;
	}
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :道筋の更新をするべきかどうかを返す
//｜引数  :なし(void)
//｜戻り値:更新の必要があればtrue(bool)	
//＋ーーーーーーーーーーーーーー＋
bool AI::ShouldUpdateRoute()
{
	vector<Tile>::iterator itr;

	for (itr = m_target.begin(); itr < m_target.end(); itr++)
	{
		if (m_start.row == itr->row
		 || m_start.column == itr->column)
		{
			//現在位置とターゲットが１つでも一致していた場合
			return false;
		}
	}

	return true;
}


