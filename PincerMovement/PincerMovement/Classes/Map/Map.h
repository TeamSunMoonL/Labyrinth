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

private:
	void LoadMap(std::string path);

};
