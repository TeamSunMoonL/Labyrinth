//************************************************/
//* @file  :Object.h
//* @brief :Objectのヘッダーファイル
//* @date  :2017/03/29
//* @author:K.Yamamoto
//************************************************/

// 多重インクルード防止
#pragma once

// ヘッダファイルのインクルード
#include "../Wrapper/Model/Model.h"
#include "../Wrapper/Vec2/Vec2.h"
#include "../AI/AI.h"

#include "../Wrapper/Model/Model.h"
#include "../Wrapper/Matrix/Matrix.h"

// 列挙型
enum Direction
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};

// 状態
enum State
{

};

// Objectクラス
class Object
{
protected:
	// 座標
	YamagenLib::Vec2 m_pos;

	// タイル座標
	YamagenLib::Vec2 m_tilePos;

	// 3Dモデル
	ShunLib::Model m_model;

	// 方向
	Direction m_direction;

	// 速度
	YamagenLib::Vec2 m_speed;

	// 状態
	State m_state;

	// AI
	AI* m_AI;

public:
	// デフォルトコンストラクタ
	Object();

	// デストラクタ
	~Object();

	// タイル座標取得
	YamagenLib::Vec2 GetTilePos() { return m_tilePos; }

	// はさまれ判定
	bool SandwichedDecision();
	
	// 純粋仮想関数
	virtual void Draw() = 0;	// 描画
	virtual void Move() = 0;	// 移動
	virtual void Update() = 0;	// 更新
};
