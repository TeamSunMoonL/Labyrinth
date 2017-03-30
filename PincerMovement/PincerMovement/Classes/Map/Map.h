//************************************************/
//* @file  :Map.h
//* @brief :マップクラスのヘッダーファイル
//* @date  :2017/03/30
//* @author:S.Katou
//************************************************/
#pragma once
#include <vector>
#include <string>
#include "../AI/Astar/Astar.h"

class Model;

class Map
{
private:
	//壁モデル
	Model* m_wall;

	//通路モデル
	Model* m_road;

	//マップデータ
	std::vector<std::vector<int>>m_map;

public:
	//コンストラクタ＆デストラクタ
	Map(int number);
	~Map();

	//描画
	void Draw()const;

	
	//マップを取得
	const std::vector<std::vector<int>>& Get()const { return m_map; }

	//指定位置のマップの属性を取得
	int Get(const Tile& tile) { return m_map[tile.row][tile.column]; }

private:
	void LoadMap(std::string path);

};
