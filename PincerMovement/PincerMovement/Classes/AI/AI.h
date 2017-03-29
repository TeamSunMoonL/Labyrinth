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
protected:
	//�}�b�v�f�[�^
	std::vector<std::vector<int>>m_map;

	//���ɐi�ލ��W�̔ԍ�
	int m_next;

	//�i�ޓ���
	std::vector<Tile>m_route;

	//���݈ʒu
	Tile m_start;

	//�^�[�Q�b�g
	std::vector<Tile> m_target;

	//�����̑���
	int m_attribute;

	//���G�͈�
	int m_searchRange;

public:

	AI(int attribute, int range = 1);
	~AI() {};

	void SetStart(const Tile& nowTile) { m_start = nowTile; }
	void SetTarget(const Tile& nowTile) { m_start = nowTile; }

	//���Ɉړ�������W��Ԃ�
	Tile GetNext();

	//�X�V����
	virtual void Update() = 0;


protected:
	//�����}�b�v�̍X�V����
	void UpdateAttributeMap();

	//���؂̍X�V
	void UpdateRoute();

	//���؂̍X�V������ׂ����ǂ�����Ԃ�
	bool ShouldUpdateRoute();

};