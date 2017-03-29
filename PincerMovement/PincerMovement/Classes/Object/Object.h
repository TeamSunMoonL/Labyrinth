//************************************************/
//* @file  :Object.h
//* @brief :Objectのヘッダーファイル
//* @date  :2017/03/29
//* @author:K.Yamamoto
//************************************************/

// 多重インクルード防止
#pragma once

// ヘッダファイルのインクルード
#include "../Wrapper/Vec2/Vec2.h"
#include "../AI/AI.h"
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

	// 3Dモデル

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

};
