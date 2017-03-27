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
private:
	//マップデータ
	std::vector<std::vector<int>>m_map;

	//次に進む座標の番号
	Tile m_next;

	//現在位置
	Tile m_start;

	//ターゲット
	Tile m_end;


public:
	AI(){};
	~AI() {};

	//次に移動する座標を返す
	Tile GetNext();

	//更新処理
	void Update();

private:
	//道筋の更新
	void UpdateRoute();

};