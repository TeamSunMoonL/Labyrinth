//************************************************/
//* @file  :Astar.h
//* @brief :A*�@�̃w�b�_�[�t�@�C��
//* @date  :2017/03/27
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
	list<Node*> openList;

	// �I�[�v�����X�g�C�e���[�^
	list<Node*>::iterator openListItr;

	// �N���[�Y�h���X�g
	list<Node*> closedList;

	// �N���[�Y�h���X�g�C�e���[�^
	list<Node*>::iterator closedListItr;

	// �ŏ��X�R�A�C�e���[�^
	list<Node*>::iterator minScoreItr;


	// �X�^�[�g�m�[�h
	Node* m_pStartNode;
	// �G���h�m�[�h
	Node* m_pEndNode;

public:
	// �R���X�g���N�^
	AStar();
	// �f�X�g���N�^
	~AStar();

	// ����������
	void Initialize(const std::vector<std::vector<int>>& map,const Tile& start,const Tile& end);

	// �I������������
	void Finalize();

	// Node�I�u�W�F�N�g�𐶐����Atile_map�z��ɂ��̃|�C���^���i�[����
	void CreateTileMap(const std::vector<std::vector<int>>& map);

	// tile_map�z���j������
	void RemoveTileMapArray();

	// �Q�^�C���Ԃ̋������v�Z����
	int Distance(Node* node1, Node* node2);

	// �T������
	bool Search();

	// �ߐڃm�[�h���I�[�v�����X�g�ɒǉ�����
	bool AddNodetoOpenList(int y, int x);

	// �R�X�g,�q���[���X�e�B�b�N,�X�R�A���v�Z����
	void CalculateScore();

	// �ŏ��X�R�A�̃m�[�h����������
	void SearchMinScoreNode();

	// �I�[�v�����X�g�ƃN���[�Y���X�g���������� 
	bool ProcessOpenCloseList(list<Node*>::iterator minscore_itr);


	//���̍��W��Ԃ�
	Tile GetNext();

	//���؂�Ԃ�
	const std::vector<Tile>& GetRoute();

private:
	void SetRoute(Node* parent);
};

#endif // ASTAR
