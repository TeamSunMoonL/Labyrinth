//************************************************/
//* @file  :AttackAI.h
//* @brief :拠点攻撃するAIのヘッダーファイル
//* @date  :2017/03/29
//* @author:S.Katou
//************************************************/
#pragma once
#include "AI.h"


class AttackAI : public AI
{
public:
	AttackAI(int attribute, int range = 1);
	~AttackAI() {};

	//更新処理
	void Update(const Tile& start)override;

private:
	//索敵
	bool Search();

	//索敵（再帰用）
	bool Search(int num);
};