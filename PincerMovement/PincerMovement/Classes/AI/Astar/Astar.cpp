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
	m_pStartNode = new Node(start.row, start.column, S, nullptr);
	
	// エンドノードオブジェクトを生成する
	//delete Finalize
	m_pEndNode = new Node(end.row, end.column, E, nullptr);


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
	delete m_pStartNode;

	//new Initialize
	delete m_pEndNode;

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
		}
	}

	//スタート位置を設定
	m_tileMap[m_pStartNode->Row()][m_pStartNode->Column()]->Attribute(S);

	//ゴール位置を設定
	m_tileMap[m_pEndNode->Row()][m_pEndNode->Column()]->Attribute(E);

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
				m_pEndNode->Parent(m_tileMap[y][x]);
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
				openList.push_back(m_tileMap[y + i][x + j]);
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
	for (openListItr = openList.begin(); openListItr != openList.end(); openListItr++)
	{
		// コストを計算する
		if ((*openListItr)->Cost() == 0)
		{
			(*openListItr)->Cost((*openListItr)->Parent()->Cost() + (*openListItr)->Cost() + 1);
		}
	
		// ヒューリスティックを計算する
		if ((*openListItr)->Heuristic() == 0)
		{
			(*openListItr)->Heuristic(Distance(m_pEndNode, *openListItr));
		}

		// スコアーを計算する
		if ((*openListItr)->Score() == 0)
		{
			(*openListItr)->Score((*openListItr)->Cost() + (*openListItr)->Heuristic());
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
	list<Node*>::iterator minScoreItr = openList.begin();
	
	// オープンリストの中から最小スコアのノードを探す
	for (openListItr = openList.begin(); openListItr != openList.end(); openListItr++)
	{
		if ((*minScoreItr)->Score() > (*openListItr)->Score()) 
		{
			// openlistイテレータをminscoreイテレータに代入する
			minScoreItr = openListItr;
		}
	}

	// 最小スコアのノードイテレータを返す
	this->minScoreItr = minScoreItr;
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :探索する
//｜引数  :なし(void)
//｜戻り値:失敗したら false(bool)	
//＋ーーーーーーーーーーーーーー＋
bool AStar::Search() 
{	
	int y = m_pStartNode->Row();	//スタート地点の行を取得
	int x = m_pStartNode->Column();	//スタート地点の列を取得

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
		y = (*minScoreItr)->Row();
		x = (*minScoreItr)->Column();
		
		// オープンリストとクローズリストを処理する 
		if (ProcessOpenCloseList(minScoreItr) == false)
		{
			return false;
		}	
	}
	return true;
}


// オープンリストとクローズリストを処理する 
bool AStar::ProcessOpenCloseList(list<Node*>::iterator minscore_itr) 
{
	// クローズドリストに最小スコアのノードを追加する(Add minimum score node to open list)
	closedList.push_back(*minscore_itr);
	
	// オープンリストから最小スコアのノードを削除する(Delete minimum score node from open list)
	openList.erase(minscore_itr);

	// オープンリストが空の場合は探索を中断する(Abort search process in case of no element of open list)
	if (openList.size() == 0)
		false;
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
		SetRoute(m_pEndNode);
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
		SetRoute(m_pEndNode);
	}

	return m_route;
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