//************************************************/
//* @file  :AttackAI.h
//* @brief :_U·éAIÌwb_[t@C
//* @date  :2017/03/28
//* @author:S.Katou
//************************************************/
#pragma once
#include "AI.h"


class AttackAI : public AI
{
public:
	AttackAI(int attribute, int range = 1);
	~AttackAI() {};

	//XV
	void Update()override;

private:
	//õG
	bool Search();

	//õGiÄApj
	bool Search(int num);
};