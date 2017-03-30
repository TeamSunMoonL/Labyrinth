//************************************************/
//* @file  :Node.h
//* @brief :ノードクラスのヘッダー
//* @date  :2017/03/29
//* @author:S.Katou
//************************************************/
#ifndef NODE
#define NODE
#pragma once

#include <list>
#include <vector>
#include <iostream>
#include <iomanip>


enum attribute
{
	O = 0, 
	P,
	S,
	E 
};

using namespace std;


// Nodeクラス
class Node 
{
	int row;		//行 (y)
	int column;		//列 (x)
	int attr;		//属性
	int cost;		//コスト
	int heuristic;	//ヒューストリック
	int score;		//スコア
	Node* pParent;	//親ノード

public:
	// コンストラクタ＆デストラクタ
	Node() {}
	~Node() {}
	Node(int y, int x, int attr, Node* pParent) :
		row(y), column(x), attr(attr), pParent(pParent),
		cost(0), heuristic(0), score(0) 
	{
		if (attr == O)
			score = O;
	}
	
	// 行を設定する
	void Row(int y) { this->row = y; }

	// 行を取得する
	int Row() { return this->row; }

	// 列を設定する
	void Column(int x) { this->column = x; }

	// 列を取得する
	int Column() { return this->column; }


	// 属性を表示する
	void Attribute(int attr) { this->attr = attr; }
	int  Attribute() { return this->attr; }

	// コストを設定する
	void Cost(int cost) { this->cost = cost; }

	//コストを加算する
	void AddCost(int cost) { this->cost += cost; }

	// コストを取得する
	int  Cost() { return this->cost; }
	

	// ヒューリスティックを設定する
	void Heuristic(int heuristic) { this->heuristic = heuristic; }
	
	// ヒューリスティックを取得する
	int  Heuristic() { return this->heuristic; }


	// スコアを設定する
	void Score(int score) { this->score = score; }

	// スコアを取得する
	int  Score() { return this->score; }


	// 親を設定する
	void Parent(Node* pParent) 
	{
		this->pParent = pParent;
	}

	// 親を取得する
	Node* Parent() { return this->pParent; }
};

#endif // NODE