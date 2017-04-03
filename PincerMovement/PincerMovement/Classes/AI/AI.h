//************************************************/
//* @file  :AI.h
//* @brief :AI�̃w�b�_�[�t�@�C��
//* @date  :2017/03/29
//* @author:S.Katou
//************************************************/
#pragma once
#include<vector>
#include "Astar\Astar.h"
#include "../GameMain/GameManager.h"

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

	//���擾�p
	GameManager* m_manager;

public:

	AI(int attribute, int range = 1);
	~AI() {};

	//���Ɉړ�������W��Ԃ�
	Tile GetNext();

	//�X�V����
	virtual void Update(const Tile& start) = 0;


protected:
	//�����}�b�v�̍X�V����
	void UpdateAttributeMap();

	//���؂̍X�V
	virtual void UpdateRoute();

	//���؂̍X�V������ׂ����ǂ�����Ԃ�
	virtual bool ShouldUpdateRoute();

	//�^�[�Q�b�g��ύX����
	virtual void ChangeTarget() = 0;
};