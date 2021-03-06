//************************************************/
//* @file  :Astar.cpp
//* @brief :A*法のソースファイル
//* @date  :2017/03/27
//* @author:S.Katou
//************************************************/

#include <windows.h>
#include "Astar.h"


using namespace std;

// AStar v7
// プログラムの起動後にファイルから属性マップを読み込む


// コンストラクタ
AStar::AStar()
	: m_mapRow(GameMain::MAP_Y)
	, m_mapColumn(GameMain::MAP_X)
	,m_tileMap(m_mapRow, vector<Node*>(m_mapColumn))
{

}

// デストラクタ
AStar::~AStar()
{
}

//＋ーーーーーーーーーーーーーー＋
//｜機能  :初期化処理
//｜引数  :マップ　(int[][])
//｜引数  :スタート(Tile)
//｜引数  :ゴール　(Tile)
//｜戻り値:なし(void)	
//＋ーーーーーーーーーーーーーー＋
void AStar::Initialize(const vector<vector<int>>& map, const Tile& start, const Tile& end)
{
	// スタートノードオブジェクトを生成する
	//delete Finalize
	m_startNode = new Node(start.row, start.column, S, nullptr);

	// エンドノードオブジェクトを生成する
	//delete Finalize
	m_endNode = new Node(end.row, end.column, E, nullptr);


	// Nodeオブジェクトを生成し、tile_map配列にそのポインタを格納する
	CreateTileMap(map);
}

//＋ーーーーーーーーーーーーーー＋
//｜機能  :初期化処理
//｜引数  :マップ　(int[][])
//｜引数  :スタート(Tile)
//｜引数  :ゴール　(Tile)
//｜戻り値:なし(void)	
//＋ーーーーーーーーーーーーーー＋
void AStar::Initialize(const vector<vector<int>>& map, const Tile& start, vector<Tile>& end)
{
	// スタートノードオブジェクトを生成する
	//delete Finalize
	m_startNode = new Node(start.row, start.column, S, nullptr);


	//最も近いターゲットをゴールに設定
	int target = FindNeedTile(start,end);

	// エンドノードオブジェクトを生成する
	//delete Finalize
	m_endNode = new Node(end[target].row, end[target].column, E, nullptr);


	// Nodeオブジェクトを生成し、tile_map配列にそのポインタを格納する
	CreateTileMap(map);
}



//＋ーーーーーーーーーーーーーー＋
//｜機能  :指定タイルのコストを加算する
//｜引数  :タイル座標(Tile)
//｜引数  :コスト(int)
//｜戻り値:なし(void)	
//＋ーーーーーーーーーーーーーー＋
void AStar::AddCost(const Tile & tile, int cost)
{
	m_tileMap[tile.row][tile.column]->AddCost(cost);
}




//＋ーーーーーーーーーーーーーー＋
//｜機能  :終了処理
//｜引数  :なし(void)
//｜戻り値:なし(void)	
//＋ーーーーーーーーーーーーーー＋
void AStar::Finalize() 
{
	//new Initialize
	delete m_startNode;

	//new Initialize
	delete m_endNode;

	// tile_map配列を破棄する
	RemoveTileMapArray();
}




//＋ーーーーーーーーーーーーーー＋
//｜機能  :tile_map配列を破棄する
//｜引数  :なし(void)
//｜戻り値:なし(void)	
//＋ーーーーーーーーーーーーーー＋
void AStar::RemoveTileMapArray() 
{
	// tile_map配列に格納されたすべてのNodeオブジェクトを破棄する
	for (int i = 0; i < m_mapRow; i++)
	{
		for (int j = 0; j < m_mapColumn; j++)
		{
			// 配列に格納されたNodeオブジェクトを破棄する
			delete m_tileMap[i][j];
		}
	}

	// tile_map配列を破棄する
	for (int i = 0; i < m_mapRow; i++)
	{
		m_tileMap[i].clear();
	}

	// tile_map配列を破棄する
	m_tileMap.clear();
}

//＋ーーーーーーーーーーーーーー＋
//｜機能  :Tilemapを生成する
//｜引数  :なし(void)
//｜戻り値:なし(void)	
//＋ーーーーーーーーーーーーーー＋
void AStar::CreateTileMap(const vector<vector<int>>& map)
{
	for (int i = 0; i < m_mapRow; i++)
	{
		for (int j = 0; j < m_mapColumn; j++)
		{
			// tile_map配列にNodeオブジェクトへのポインタを格納する
			m_tileMap[i][j] = new Node(i, j, map[i][j], nullptr);

			//コストを設定する
			m_tileMap[i][j]->AddCost(m_tileMap[i][j]->Attribute());
		}
	}

	//スタート位置を設定
	m_tileMap[m_startNode->Row()][m_startNode->Column()]->Attribute(S);

	//ゴール位置を設定
	m_tileMap[m_endNode->Row()][m_endNode->Column()]->Attribute(E);

}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :２タイル間の距離を返す
//｜引数  :タイル１の座標    (int,int)
//｜引数  :タイル２の座標    (int,int)
//｜戻り値:２タイル間の距離  (int)
//｜　　 （マンハッタン距離）
//＋ーーーーーーーーーーーーーー＋
int AStar::Distance(Node* node1, Node* node2)
{
	int deltaRow = node1->Row() - node2->Row();
	int deltaColumn = node1->Column() - node2->Column();

	// マンハッタン距離
	 return abs(deltaRow) + abs(deltaColumn);
}



//＋ーーーーーーーーーーーーーー＋
//｜機能  :近接ノードをオープンリストに追加する
//｜引数  :親ノード座標      (int,int)
//｜戻り値:追加出来たら　true(bool)
//＋ーーーーーーーーーーーーーー＋
bool AStar::AddNodetoOpenList(int y, int x) 
{
	// 隣接するノードの属性を調べて、経路をオープンリストに追加する
	//
	//(-1,-1)  (-1, 0)  (-1, 1)
	//( 0,-1)  ( 0, 0)  ( 0, 1) 
	//( 1,-1)  ( 1, 0)  ( 1. 1)

	for (int i = -1; i < 2; i++) 
	{
		for (int j = -1; j < 2; j++) 
		{
			//親ノード、斜め方向は調べない
			if (abs(i) == abs(j))
			{
				continue;
			}

			// ノード位置がtile_map配列の境界の上限と下限を超えているかどうかを調べる
			//マップ外なら判定しない
			if (y + i < 0
			 || y + i > m_mapRow - 1
			 || x + j < 0
			 || x + j > m_mapColumn - 1)
			{
				continue;
			}


			// ノードがエンドノード(目的地)に到達したかどうかを調べる
			//ゴールなら判定を抜ける
			if (m_tileMap[y + i][x + j]->Attribute() == E)
			{
				// エンドノードの親ノードに現在のノードを設定する
				m_endNode->Parent(m_tileMap[y][x]);
				// エンドノードに到達した
				return false;
			}


			// スコアが計算済みかどうかを調べる
			if (m_tileMap[y + i][x + j]->Score() != 0)
			{
				continue;
			}


			// 現在のノードが経路かどうかを調べる
			//壁なら判定を飛ばす
			if (m_tileMap[y + i][x + j]->Attribute() == P)
			{
				// 現在のノードに親を設定する
				m_tileMap[y + i][x + j]->Parent(m_tileMap[y][x]);

				// オープンリストに現在のノードを追加する
				m_openList.push_back(m_tileMap[y + i][x + j]);
			}
		}
	}

	// 近接ノードをopen listに追加することができた
	return true;
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :コスト,ヒューリスティック,スコアを計算する
//｜引数  :なし(void)
//｜戻り値:なし(void)	
//＋ーーーーーーーーーーーーーー＋
void AStar::CalculateScore() 
{
	for (m_openListItr = m_openList.begin(); m_openListItr != m_openList.end(); m_openListItr++)
	{
		// コストを計算する
		if ((*m_openListItr)->Cost() == 0)
		{
			(*m_openListItr)->Cost((*m_openListItr)->Parent()->Cost() + (*m_openListItr)->Cost() + 1);
		}
	
		// ヒューリスティックを計算する
		if ((*m_openListItr)->Heuristic() == 0)
		{
			(*m_openListItr)->Heuristic(Distance(m_endNode, *m_openListItr));
		}

		// スコアーを計算する
		if ((*m_openListItr)->Score() == 0)
		{
			(*m_openListItr)->Score((*m_openListItr)->Cost() + (*m_openListItr)->Heuristic());
		}
	}
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :最小スコアのノードを検索する
//｜引数  :なし(void)
//｜戻り値:なし(void)	
//＋ーーーーーーーーーーーーーー＋
void AStar::SearchMinScoreNode() 
{
	// 先頭ノードを最小スコアのノードに設定する
	list<Node*>::iterator minScoreItr = m_openList.begin();
	
	// オープンリストの中から最小スコアのノードを探す
	for (m_openListItr = m_openList.begin(); m_openListItr != m_openList.end(); m_openListItr++)
	{
		if ((*minScoreItr)->Score() > (*m_openListItr)->Score())
		{
			// openlistイテレータをminscoreイテレータに代入する
			minScoreItr = m_openListItr;
		}
	}

	// 最小スコアのノードイテレータを返す
	this->m_minScoreItr = minScoreItr;
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :探索する
//｜引数  :なし(void)
//｜戻り値:失敗したら false(bool)	
//＋ーーーーーーーーーーーーーー＋
bool AStar::Search() 
{	
	int y = m_startNode->Row();	//スタート地点の行を取得
	int x = m_startNode->Column();	//スタート地点の列を取得

	//永久にループ
	for (;;) 
	{
		// 隣接するノードをオープンリストに追加する
		if (AddNodetoOpenList(y, x) == false)
		{
			return false;
		}

		// コスト,ヒューリスティック,スコアを計算する
		CalculateScore();
		
		// オープンリストから最小スコアのノードを検索する
		SearchMinScoreNode();
		
		// 最小スコアのノードの行と列を設定する
		y = (*m_minScoreItr)->Row();
		x = (*m_minScoreItr)->Column();
		
		// オープンリストとクローズリストを処理する 
		if (ProcessOpenCloseList(m_minScoreItr) == false)
		{
			return false;
		}	
	}
	return true;
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :オープンリストとクローズリストを処理する 
//｜引数  :最小ノードのイテレータ     (list<Node*>::iterator )
//｜戻り値:オープンリストが空ならfalse(bool)
//＋ーーーーーーーーーーーーーー＋
bool AStar::ProcessOpenCloseList(list<Node*>::iterator minscore_itr) 
{
	// クローズドリストに最小スコアのノードを追加する
	m_closedList.push_back(*minscore_itr);
	
	// オープンリストから最小スコアのノードを削除する
	m_openList.erase(minscore_itr);

	// オープンリストが空の場合は探索を中断する
	if (m_openList.size() == 0)
	{
		return false;
	}

	return true;
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :次の座標を返す
//｜引数  :なし    (void)
//｜戻り値:次の座標(Tile)	
//＋ーーーーーーーーーーーーーー＋
Tile AStar::GetNext()
{
	//ルートが空なら確定させる
	if (m_route.empty())
	{
		SetRoute(m_endNode);
	}
	return m_route[0];
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :道筋を返す
//｜引数  :なし    (void)
//｜戻り値:道筋	   (vector<Tile>)	
//＋ーーーーーーーーーーーーーー＋
const vector<Tile>& AStar::GetRoute()
{
	//ルートが空なら確定させる
	if (m_route.empty())
	{
		SetRoute(m_endNode);
	}

	return m_route;
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :現在位置から最も近いターゲットを探す
//｜引数  :現在位置    (Tile)
//｜引数  :ターゲット  (vector<Tile>)
//｜戻り値:最も近いターゲット   (int)	
//＋ーーーーーーーーーーーーーー＋
int AStar::FindNeedTile(const Tile & start, std::vector<Tile>& target)
{
	//ターゲットのイテレータ
	vector<Tile>::iterator itr;

	//２点間の距離保管用
	int d = 9999;
	
	//最も近いターゲットの番号を保管
	int n = 0;

	//現在位置とターゲットの距離を比較
	for (itr = target.begin(); itr < target.end(); itr++)
	{
		//現在位置とターゲットの距離を比較
		int deltaRow = start.row - itr->row;
		int deltaColumn = start.column - itr->column;

		//最短距離を更新
		if (abs(deltaRow) + abs(deltaColumn) < d)
		{
			d = abs(deltaRow) + abs(deltaColumn);
			n = itr - target.begin();
		}
	}

	return n;
}

//＋ーーーーーーーーーーーーーー＋
//｜機能  :ルートを確定する
//｜引数  :親ノード(Node*)
//｜戻り値:なし	   (void)	
//＋ーーーーーーーーーーーーーー＋
void AStar::SetRoute(Node* parent)
{
	// スタート地点に戻っていない場合
	if (parent->Attribute() != S)
	{
		//親を辿る
		SetRoute(parent->Parent());

		//辿り終わったら座標を入れていく
		Tile tmp = { parent->Row(),parent->Column() };
		m_route.push_back(tmp);

	}
}