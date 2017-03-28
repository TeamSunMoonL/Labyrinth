//************************************************/
//* @file  :AttackAI.h
//* @brief :���_�U������AI�̃w�b�_�[�t�@�C��
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

	//�X�V����
	void Update()override;

private:
	//���G
	bool Search();

	//���G�i�ċA�p�j
	bool Search(int num);
};