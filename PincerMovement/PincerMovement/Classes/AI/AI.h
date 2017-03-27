//************************************************/
//* @file  :AI.h
//* @brief :AI�̃w�b�_�[�t�@�C��
//* @date  :2017/03/27
//* @author:S.Katou
//************************************************/
#pragma once
#include<vector>
#include "Astar\Astar.h"

class AI
{
private:
	//�}�b�v�f�[�^
	std::vector<std::vector<int>>m_map;

	//���ɐi�ލ��W�̔ԍ�
	Tile m_next;

	//���݈ʒu
	Tile m_start;

	//�^�[�Q�b�g
	Tile m_end;


public:
	AI(){};
	~AI() {};

	//���Ɉړ�������W��Ԃ�
	Tile GetNext();

	//�X�V����
	void Update();

private:
	//���؂̍X�V
	void UpdateRoute();

};