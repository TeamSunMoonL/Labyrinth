//************************************************/
//* @file  :Map.h
//* @brief :�}�b�v�N���X�̃w�b�_�[�t�@�C��
//* @date  :2017/04/03
//* @author:S.Katou
//************************************************/
#pragma once
#include <vector>
#include <string>
#include <GeometricPrimitive.h>
#include "../Wrapper/Matrix/Matrix.h"

struct Tile;

class Map
{
private:
	//�ǃ��f��
	std::unique_ptr<DirectX::GeometricPrimitive> m_wall;

	//�ʘH���f��
	std::unique_ptr<DirectX::GeometricPrimitive> m_road;

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
	void Draw(const ShunLib::Matrix& world,
		      const ShunLib::Matrix& view,
			  const ShunLib::Matrix& proj)const;

	//�}�b�v���擾
	const std::vector<std::vector<int>>& Get()const { return m_map; }

	//�w��ʒu�̃}�b�v�̑������擾
	int Get(const Tile& tile);

	//�w�肵���Gor�v���C���[�̏����ʒu���擾
	const Tile& Get(int charactor, int num);


private:
	//�}�b�v��csv����ǂݍ���
	void LoadMap(std::string path);

};
