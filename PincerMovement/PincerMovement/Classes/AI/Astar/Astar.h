//************************************************/
//* @file  :Astar.h
//* @brief :A*�@�̃w�b�_�[�t�@�C��
//* @date  :2017/04/03
//* @author:S.Katou
//************************************************/

#ifndef ASTAR
#define ASTAR

// AStar v7
#pragma once

#include <list>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

#include "Node.h"

#include "../../GameMain/GameMain.h"

struct Tile 
{
	int row;	//�s
	int column;	//��
};


//A*�@�N���X
class AStar 
{
private:

	// �}�b�v�s(map y)
	int m_mapRow;
	// �}�b�v��(map x)
	int m_mapColumn;

	//����
	std::vector<Tile>m_route;

	
	// �^�C���}�b�v
	vector<vector<Node*>> m_tileMap;


	// �I�[�v�����X�g
	list<Node*> m_openList;

	// �I�[�v�����X�g�C�e���[�^
	list<Node*>::iterator m_openListItr;

	// �N���[�Y�h���X�g
	list<Node*> m_closedList;

	// �ŏ��X�R�A�C�e���[�^
	list<Node*>::iterator m_minScoreItr;


	// �X�^�[�g�m�[�h
	Node* m_startNode;
	// �G���h�m�[�h
	Node* m_endNode;

public:
	// �R���X�g���N�^
	AStar();
	// �f�X�g���N�^
	~AStar();

	// ����������
	void Initialize(const std::vector<std::vector<int>>& map, const Tile& start, const Tile& end);
	void Initialize(const std::vector<std::vector<int>>& map, const Tile& start, std::vector<Tile>& end);

	//�^�C���̃R�X�g��ݒ肷��
	void AddCost(const Tile& tile, int cost);

	// �T������
	bool Search();

	// �I������������
	void Finalize();

	//���̍��W��Ԃ�
	Tile GetNext();

	//���؂�Ԃ�
	const std::vector<Tile>& GetRoute();

private:
	//���݈ʒu����ł��߂��^�[�Q�b�g��T��
	int FindNeedTile(const Tile& start,std::vector<Tile>& target);

	//���؂�ݒ�
	void SetRoute(Node* parent);

	// Node�I�u�W�F�N�g�𐶐����Atile_map�z��ɂ��̃|�C���^���i�[����
	void CreateTileMap(const std::vector<std::vector<int>>& map);

	// tile_map�z���j������
	void RemoveTileMapArray();

	// �Q�^�C���Ԃ̋������v�Z����
	int Distance(Node* node1, Node* node2);


	// �ߐڃm�[�h���I�[�v�����X�g�ɒǉ�����
	bool AddNodetoOpenList(int y, int x);

	// �R�X�g,�q���[���X�e�B�b�N,�X�R�A���v�Z����
	void CalculateScore();

	// �ŏ��X�R�A�̃m�[�h����������
	void SearchMinScoreNode();

	// �I�[�v�����X�g�ƃN���[�Y���X�g���������� 
	bool ProcessOpenCloseList(list<Node*>::iterator minscore_itr);

};

#endif // ASTAR
