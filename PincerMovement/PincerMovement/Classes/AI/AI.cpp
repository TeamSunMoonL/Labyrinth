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
//｜機能  :次に移動する座標を取得
//｜引数  :なし(void)
//｜戻り値:座標(Tile)	
//＋ーーーーーーーーーーーーーー＋
Tile AI::GetNext()
{
	//座標を返す
	return m_next;
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :更新処理
//｜引数  :なし(void)
//｜戻り値:なし(void)	
//＋ーーーーーーーーーーーーーー＋
void AI::Update()
{
	//情報の取得


	//道筋の更新
	UpdateRoute();
}



//＋ーーーーーーーーーーーーーー＋
//｜機能  :道筋の更新処理
//｜引数  :なし(void)
//｜戻り値:なし(void)	
//＋ーーーーーーーーーーーーーー＋
void AI::UpdateRoute()
{
	if (m_start.row    != m_end.row
	  ||m_start.column != m_end.column)
	{

		//A*法
		AStar astar;

		//初期化
		astar.Initialize(m_map, m_start, m_end);

		//探索
		astar.Search();

		//道筋を取得
		m_next = astar.GetNext();

		//終了処理
		astar.Finalize();
	}
}


