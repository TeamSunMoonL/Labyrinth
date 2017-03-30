//************************************************/
//* @file  :Map.h
//* @brief :�}�b�v�N���X�̃w�b�_�[�t�@�C��
//* @date  :2017/03/30
//* @author:S.Katou
//************************************************/
#pragma once
#include <vector>
#include <string>
#include "../AI/Astar/Astar.h"

class Model;

class Map
{
private:
	//�ǃ��f��
	Model* m_wall;

	//�ʘH���f��
	Model* m_road;

	//�}�b�v�f�[�^
	std::vector<std::vector<int>>m_map;

	//�v���C���[�ƓG�̏����ʒu
	std::vector<Tile>m_playerInitialPos;
	std::vector<Tile>m_enemyInitialPos;

public:
	//�R���X�g���N�^���f�X�g���N�^
	Map(int number);
	~Map();

	//�`��
	void Draw()const;

	//�}�b�v���擾
	const std::vector<std::vector<int>>& Get()const { return m_map; }

	//�w��ʒu�̃}�b�v�̑������擾
	int Get(const Tile& tile) { return m_map[tile.row][tile.column]; }

	//�w�肵���Gor�v���C���[�̏����ʒu���擾
	const Tile& Get(int charactor,int num)
	{
		Tile pos = { 0,0 };
	
		//�Gor�v���C���[�̏����ʒu���擾
		switch (charactor)
		{
		case PLAYER:
			pos = m_playerInitialPos[num];
			break;

		case ENEMY:
			pos = m_enemyInitialPos[num];
			break;
		default:
			break;
		}

		return pos;
	}


private:
	//�}�b�v��csv����ǂݍ���
	void LoadMap(std::string path);

};
