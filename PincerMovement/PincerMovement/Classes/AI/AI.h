//************************************************/
//* @file  :AI.h
//* @brief :AIのヘッダーファイル
//* @date  :2017/03/27
//* @author:S.Katou
//************************************************/
#pragma once
#include<vector>
#include "Astar\Astar.h"

class AI
{
protected:
	//マップデータ
	std::vector<std::vector<int>>m_map;

	//次に進む座標の番号
	int m_next;

	//進む道筋
	std::vector<Tile>m_route;

	//現在位置
	Tile m_start;

	//ターゲット
	std::vector<Tile> m_target;

	//自分の属性
	int m_attribute;

	//索敵範囲
	int m_searchRange;

public:

	AI(int attribute, int range = 1);
	~AI() {};

	void SetStart(const Tile& nowTile) { m_start = nowTile; }
	void SetTarget(const Tile& nowTile) { m_start = nowTile; }

	//次に移動する座標を返す
	Tile GetNext();

	//更新処理
	virtual void Update() = 0;


protected:
	//属性マップの更新処理
	void UpdateAttributeMap();

	//道筋の更新
	void UpdateRoute();

	//道筋の更新をするべきかどうかを返す
	bool ShouldUpdateRoute();

};