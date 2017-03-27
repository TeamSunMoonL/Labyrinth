//************************************************/
//* @file  :Astar.h
//* @brief :A*法のヘッダーファイル
//* @date  :2017/03/27
//* @author:S.Katou
//************************************************/

#ifndef ASTAR
#define ASTAR

// AStar v7
#pragma once

#include <list>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

#include "Node.h"

#include "../../GameMain/GameMain.h"

struct Tile 
{
	int row;	//行
	int column;	//列
};


//A*法クラス
class AStar 
{
private:

	// マップ行(map y)
	int m_mapRow;
	// マップ列(map x)
	int m_mapColumn;

	//道筋
	std::vector<Tile>m_route;

	
	// タイルマップ
	vector<vector<Node*>> m_tileMap;


	// オープンリスト
	list<Node*> openList;

	// オープンリストイテレータ
	list<Node*>::iterator openListItr;

	// クローズドリスト
	list<Node*> closedList;

	// クローズドリストイテレータ
	list<Node*>::iterator closedListItr;

	// 最小スコアイテレータ
	list<Node*>::iterator minScoreItr;


	// スタートノード
	Node* m_pStartNode;
	// エンドノード
	Node* m_pEndNode;

public:
	// コンストラクタ
	AStar();
	// デストラクタ
	~AStar();

	// 初期化する
	void Initialize(const std::vector<std::vector<int>>& map,const Tile& start,const Tile& end);

	// 終了処理をする
	void Finalize();

	// Nodeオブジェクトを生成し、tile_map配列にそのポインタを格納する
	void CreateTileMap(const std::vector<std::vector<int>>& map);

	// tile_map配列を破棄する
	void RemoveTileMapArray();

	// ２タイル間の距離を計算する
	int Distance(Node* node1, Node* node2);

	// 探索する
	bool Search();

	// 近接ノードをオープンリストに追加する
	bool AddNodetoOpenList(int y, int x);

	// コスト,ヒューリスティック,スコアを計算する
	void CalculateScore();

	// 最小スコアのノードを検索する
	void SearchMinScoreNode();

	// オープンリストとクローズリストを処理する 
	bool ProcessOpenCloseList(list<Node*>::iterator minscore_itr);


	//次の座標を返す
	Tile GetNext();

	//道筋を返す
	const std::vector<Tile>& GetRoute();

private:
	void SetRoute(Node* parent);
};

#endif // ASTAR
