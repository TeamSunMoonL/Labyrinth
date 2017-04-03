//************************************************/
//* @file  :Map.h
//* @brief :マップクラスのヘッダーファイル
//* @date  :2017/04/03
//* @author:S.Katou
//************************************************/
#pragma once
#include <vector>
#include <string>
#include <GeometricPrimitive.h>
#include "../Wrapper/Matrix/Matrix.h"

struct Tile;

class Map
{
private:
	//壁モデル
	std::unique_ptr<DirectX::GeometricPrimitive> m_wall;

	//通路モデル
	std::unique_ptr<DirectX::GeometricPrimitive> m_road;

	//マップデータ
	std::vector<std::vector<int>>m_map;

	//プレイヤーと敵の初期位置
	std::vector<Tile>m_playerInitialPos;
	std::vector<Tile>m_enemyInitialPos;

public:
	//コンストラクタ＆デストラクタ
	Map(int number);
	~Map();

	//描画
	void Draw(const ShunLib::Matrix& world,
		      const ShunLib::Matrix& view,
			  const ShunLib::Matrix& proj)const;

	//マップを取得
	const std::vector<std::vector<int>>& Get()const { return m_map; }

	//指定位置のマップの属性を取得
	int Get(const Tile& tile);

	//指定した敵orプレイヤーの初期位置を取得
	const Tile& Get(int charactor, int num);


private:
	//マップをcsvから読み込む
	void LoadMap(std::string path);

};
