//************************************************/
//* @file  :Astar.cpp
//* @brief :A*�@�̃\�[�X�t�@�C��
//* @date  :2017/03/27
//* @author:S.Katou
//************************************************/

#include <windows.h>
#include "Astar.h"


using namespace std;

// AStar v7
// �v���O�����̋N����Ƀt�@�C�����瑮���}�b�v��ǂݍ���


// �R���X�g���N�^
AStar::AStar()
	: m_mapRow(GameMain::MAP_Y)
	, m_mapColumn(GameMain::MAP_X)
	,m_tileMap(m_mapRow, vector<Node*>(m_mapColumn))
{

}

// �f�X�g���N�^
AStar::~AStar()
{
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :����������
//�b����  :�}�b�v�@(int[][])
//�b����  :�X�^�[�g(Tile)
//�b����  :�S�[���@(Tile)
//�b�߂�l:�Ȃ�(void)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void AStar::Initialize(const vector<vector<int>>& map, const Tile& start, const Tile& end)
{
	// �X�^�[�g�m�[�h�I�u�W�F�N�g�𐶐�����
	//delete Finalize
	m_pStartNode = new Node(start.row, start.column, S, nullptr);
	
	// �G���h�m�[�h�I�u�W�F�N�g�𐶐�����
	//delete Finalize
	m_pEndNode = new Node(end.row, end.column, E, nullptr);


	// Node�I�u�W�F�N�g�𐶐����Atile_map�z��ɂ��̃|�C���^���i�[����
	CreateTileMap(map);
}



//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�w��^�C���̃R�X�g�����Z����
//�b����  :�^�C�����W(Tile)
//�b����  :�R�X�g(int)
//�b�߂�l:�Ȃ�(void)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void AStar::AddCost(const Tile & tile, int cost)
{
	m_tileMap[tile.row][tile.column]->AddCost(cost);
}




//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�I������
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void AStar::Finalize() 
{
	//new Initialize
	delete m_pStartNode;

	//new Initialize
	delete m_pEndNode;

	// tile_map�z���j������
	RemoveTileMapArray();
}




//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :tile_map�z���j������
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void AStar::RemoveTileMapArray() 
{
	// tile_map�z��Ɋi�[���ꂽ���ׂĂ�Node�I�u�W�F�N�g��j������
	for (int i = 0; i < m_mapRow; i++)
	{
		for (int j = 0; j < m_mapColumn; j++)
		{
			// �z��Ɋi�[���ꂽNode�I�u�W�F�N�g��j������
			delete m_tileMap[i][j];
		}
	}

	// tile_map�z���j������
	for (int i = 0; i < m_mapRow; i++)
	{
		m_tileMap[i].clear();
	}

	// tile_map�z���j������
	m_tileMap.clear();
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :Tilemap�𐶐�����
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void AStar::CreateTileMap(const vector<vector<int>>& map)
{
	for (int i = 0; i < m_mapRow; i++)
	{
		for (int j = 0; j < m_mapColumn; j++)
		{
			// tile_map�z���Node�I�u�W�F�N�g�ւ̃|�C���^���i�[����
			m_tileMap[i][j] = new Node(i, j, map[i][j], nullptr);
		}
	}

	//�X�^�[�g�ʒu��ݒ�
	m_tileMap[m_pStartNode->Row()][m_pStartNode->Column()]->Attribute(S);

	//�S�[���ʒu��ݒ�
	m_tileMap[m_pEndNode->Row()][m_pEndNode->Column()]->Attribute(E);

}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�Q�^�C���Ԃ̋�����Ԃ�
//�b����  :�^�C���P�̍��W    (int,int)
//�b����  :�^�C���Q�̍��W    (int,int)
//�b�߂�l:�Q�^�C���Ԃ̋���  (int)
//�b�@�@ �i�}���n�b�^�������j
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
int AStar::Distance(Node* node1, Node* node2)
{
	int deltaRow = node1->Row() - node2->Row();
	int deltaColumn = node1->Column() - node2->Column();

	// �}���n�b�^������
	 return abs(deltaRow) + abs(deltaColumn);
}



//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�ߐڃm�[�h���I�[�v�����X�g�ɒǉ�����
//�b����  :�e�m�[�h���W      (int,int)
//�b�߂�l:�ǉ��o������@true(bool)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
bool AStar::AddNodetoOpenList(int y, int x) 
{
	// �אڂ���m�[�h�̑����𒲂ׂāA�o�H���I�[�v�����X�g�ɒǉ�����
	//
	//(-1,-1)  (-1, 0)  (-1, 1)
	//( 0,-1)  ( 0, 0)  ( 0, 1) 
	//( 1,-1)  ( 1, 0)  ( 1. 1)

	for (int i = -1; i < 2; i++) 
	{
		for (int j = -1; j < 2; j++) 
		{
			//�e�m�[�h�A�΂ߕ����͒��ׂȂ�
			if (abs(i) == abs(j))
			{
				continue;
			}

			// �m�[�h�ʒu��tile_map�z��̋��E�̏���Ɖ����𒴂��Ă��邩�ǂ����𒲂ׂ�
			//�}�b�v�O�Ȃ画�肵�Ȃ�
			if (y + i < 0
			 || y + i > m_mapRow - 1
			 || x + j < 0
			 || x + j > m_mapColumn - 1)
			{
				continue;
			}


			// �m�[�h���G���h�m�[�h(�ړI�n)�ɓ��B�������ǂ����𒲂ׂ�
			//�S�[���Ȃ画��𔲂���
			if (m_tileMap[y + i][x + j]->Attribute() == E)
			{
				// �G���h�m�[�h�̐e�m�[�h�Ɍ��݂̃m�[�h��ݒ肷��
				m_pEndNode->Parent(m_tileMap[y][x]);
				// �G���h�m�[�h�ɓ��B����
				return false;
			}


			// �X�R�A���v�Z�ς݂��ǂ����𒲂ׂ�
			if (m_tileMap[y + i][x + j]->Score() != 0)
			{
				continue;
			}


			// ���݂̃m�[�h���o�H���ǂ����𒲂ׂ�
			//�ǂȂ画����΂�
			if (m_tileMap[y + i][x + j]->Attribute() == P)
			{
				// ���݂̃m�[�h�ɐe��ݒ肷��
				m_tileMap[y + i][x + j]->Parent(m_tileMap[y][x]);

				// �I�[�v�����X�g�Ɍ��݂̃m�[�h��ǉ�����
				openList.push_back(m_tileMap[y + i][x + j]);
			}
		}
	}

	// �ߐڃm�[�h��open list�ɒǉ����邱�Ƃ��ł���
	return true;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�R�X�g,�q���[���X�e�B�b�N,�X�R�A���v�Z����
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void AStar::CalculateScore() 
{
	for (openListItr = openList.begin(); openListItr != openList.end(); openListItr++)
	{
		// �R�X�g���v�Z����
		if ((*openListItr)->Cost() == 0)
		{
			(*openListItr)->Cost((*openListItr)->Parent()->Cost() + (*openListItr)->Cost() + 1);
		}
	
		// �q���[���X�e�B�b�N���v�Z����
		if ((*openListItr)->Heuristic() == 0)
		{
			(*openListItr)->Heuristic(Distance(m_pEndNode, *openListItr));
		}

		// �X�R�A�[���v�Z����
		if ((*openListItr)->Score() == 0)
		{
			(*openListItr)->Score((*openListItr)->Cost() + (*openListItr)->Heuristic());
		}
	}
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�ŏ��X�R�A�̃m�[�h����������
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void AStar::SearchMinScoreNode() 
{
	// �擪�m�[�h���ŏ��X�R�A�̃m�[�h�ɐݒ肷��
	list<Node*>::iterator minScoreItr = openList.begin();
	
	// �I�[�v�����X�g�̒�����ŏ��X�R�A�̃m�[�h��T��
	for (openListItr = openList.begin(); openListItr != openList.end(); openListItr++)
	{
		if ((*minScoreItr)->Score() > (*openListItr)->Score()) 
		{
			// openlist�C�e���[�^��minscore�C�e���[�^�ɑ������
			minScoreItr = openListItr;
		}
	}

	// �ŏ��X�R�A�̃m�[�h�C�e���[�^��Ԃ�
	this->minScoreItr = minScoreItr;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�T������
//�b����  :�Ȃ�(void)
//�b�߂�l:���s������ false(bool)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
bool AStar::Search() 
{	
	int y = m_pStartNode->Row();	//�X�^�[�g�n�_�̍s���擾
	int x = m_pStartNode->Column();	//�X�^�[�g�n�_�̗���擾

	//�i�v�Ƀ��[�v
	for (;;) 
	{
		// �אڂ���m�[�h���I�[�v�����X�g�ɒǉ�����
		if (AddNodetoOpenList(y, x) == false)
		{
			return false;
		}

		// �R�X�g,�q���[���X�e�B�b�N,�X�R�A���v�Z����
		CalculateScore();
		
		// �I�[�v�����X�g����ŏ��X�R�A�̃m�[�h����������
		SearchMinScoreNode();
		
		// �ŏ��X�R�A�̃m�[�h�̍s�Ɨ��ݒ肷��
		y = (*minScoreItr)->Row();
		x = (*minScoreItr)->Column();
		
		// �I�[�v�����X�g�ƃN���[�Y���X�g���������� 
		if (ProcessOpenCloseList(minScoreItr) == false)
		{
			return false;
		}	
	}
	return true;
}


// �I�[�v�����X�g�ƃN���[�Y���X�g���������� 
bool AStar::ProcessOpenCloseList(list<Node*>::iterator minscore_itr) 
{
	// �N���[�Y�h���X�g�ɍŏ��X�R�A�̃m�[�h��ǉ�����(Add minimum score node to open list)
	closedList.push_back(*minscore_itr);
	
	// �I�[�v�����X�g����ŏ��X�R�A�̃m�[�h���폜����(Delete minimum score node from open list)
	openList.erase(minscore_itr);

	// �I�[�v�����X�g����̏ꍇ�͒T���𒆒f����(Abort search process in case of no element of open list)
	if (openList.size() == 0)
		false;
	return true;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :���̍��W��Ԃ�
//�b����  :�Ȃ�    (void)
//�b�߂�l:���̍��W(Tile)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Tile AStar::GetNext()
{
	//���[�g����Ȃ�m�肳����
	if (m_route.empty())
	{
		SetRoute(m_pEndNode);
	}
	return m_route[0];
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :���؂�Ԃ�
//�b����  :�Ȃ�    (void)
//�b�߂�l:����	   (vector<Tile>)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
const vector<Tile>& AStar::GetRoute()
{
	//���[�g����Ȃ�m�肳����
	if (m_route.empty())
	{
		SetRoute(m_pEndNode);
	}

	return m_route;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :���[�g���m�肷��
//�b����  :�e�m�[�h(Node*)
//�b�߂�l:�Ȃ�	   (void)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void AStar::SetRoute(Node* parent)
{
	// �X�^�[�g�n�_�ɖ߂��Ă��Ȃ��ꍇ
	if (parent->Attribute() != S)
	{
		//�e��H��
		SetRoute(parent->Parent());

		//�H��I���������W�����Ă���
		Tile tmp = { parent->Row(),parent->Column() };
		m_route.push_back(tmp);

	}
}