//************************************************/
//* @file  :Node.h
//* @brief :�m�[�h�N���X�̃w�b�_�[
//* @date  :2017/03/29
//* @author:S.Katou
//************************************************/
#ifndef NODE
#define NODE
#pragma once

#include <list>
#include <vector>
#include <iostream>
#include <iomanip>


enum attribute
{
	O = 0, 
	P,
	S,
	E 
};

using namespace std;


// Node�N���X
class Node 
{
	int row;		//�s (y)
	int column;		//�� (x)
	int attr;		//����
	int cost;		//�R�X�g
	int heuristic;	//�q���[�X�g���b�N
	int score;		//�X�R�A
	Node* pParent;	//�e�m�[�h

public:
	// �R���X�g���N�^���f�X�g���N�^
	Node() {}
	~Node() {}
	Node(int y, int x, int attr, Node* pParent) :
		row(y), column(x), attr(attr), pParent(pParent),
		cost(0), heuristic(0), score(0) 
	{
		if (attr == O)
			score = O;
	}
	
	// �s��ݒ肷��
	void Row(int y) { this->row = y; }

	// �s���擾����
	int Row() { return this->row; }

	// ���ݒ肷��
	void Column(int x) { this->column = x; }

	// ����擾����
	int Column() { return this->column; }


	// ������\������
	void Attribute(int attr) { this->attr = attr; }
	int  Attribute() { return this->attr; }

	// �R�X�g��ݒ肷��
	void Cost(int cost) { this->cost = cost; }

	//�R�X�g�����Z����
	void AddCost(int cost) { this->cost += cost; }

	// �R�X�g���擾����
	int  Cost() { return this->cost; }
	

	// �q���[���X�e�B�b�N��ݒ肷��
	void Heuristic(int heuristic) { this->heuristic = heuristic; }
	
	// �q���[���X�e�B�b�N���擾����
	int  Heuristic() { return this->heuristic; }


	// �X�R�A��ݒ肷��
	void Score(int score) { this->score = score; }

	// �X�R�A���擾����
	int  Score() { return this->score; }


	// �e��ݒ肷��
	void Parent(Node* pParent) 
	{
		this->pParent = pParent;
	}

	// �e���擾����
	Node* Parent() { return this->pParent; }
};

#endif // NODE