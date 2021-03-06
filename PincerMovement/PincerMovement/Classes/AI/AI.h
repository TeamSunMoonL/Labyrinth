//************************************************/
//* @file  :AI.h
//* @brief :AIのヘッダーファイル
//* @date  :2017/03/29
//* @author:S.Katou
//************************************************/
#pragma once
#include<vector>
#include "Astar\Astar.h"
#include "../GameMain/GameManager.h"
#include <GeometricPrimitive.h>

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

	//情報取得用
	GameManager* m_manager;

public:

	AI(int attribute, int range = 1);
	~AI() {};

	//次に移動する座標を返す
	Tile GetNext();

	//更新処理
	virtual void Update(const Tile& start) = 0;


protected:
	//属性マップの更新処理
	void UpdateAttributeMap();

	//道筋の更新
	virtual void UpdateRoute();

	//道筋の更新をするべきかどうかを返す
	virtual bool ShouldUpdateRoute();

	//ターゲットを変更する
	virtual void ChangeTarget() = 0;



	/*--[以下デバッグ＆発表用]--*/
private:
	//デバッグ用ターゲットモデル
	std::unique_ptr<DirectX::GeometricPrimitive> m_model;

public:
	//ターゲットをランダムに決定
	//（デバッグ用）
	void RandamTarget();

	void DrawDebug(const ShunLib::Matrix& view,
				   const ShunLib::Matrix& proj)const
	{
		for (int i = 0; i < static_cast<int>(m_target.size()); i++)
		{
			ShunLib::Matrix pos = ShunLib::Matrix::CreateTranslation(ShunLib::Vec3(m_target[i].column*GameMain::CHIP_SIZE, 0.0f, m_target[i].row*GameMain::CHIP_SIZE));
			m_model->Draw(pos.GetDirectMatrix(), view.GetDirectMatrix(), proj.GetDirectMatrix(), DirectX::Colors::Gold);
		}
	};

};