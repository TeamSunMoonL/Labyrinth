//************************************************/
//* @file  :Map.cpp
//* @brief :�}�b�v�N���X�̃\�[�X�t�@�C��
//* @date  :2017/03/30
//* @author:S.Katou
//************************************************/
#include "Map.h"
#include <fstream>
#include <sstream>

#include "../GameMain/GameMain.h"

using namespace std;

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�R���X�g���N�^
//�b����  :�}�b�v�̔ԍ�(int)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Map::Map(int number)
	:m_map(GameMain::MAP_Y,vector<int>(GameMain::MAP_X))
{
	//�}�b�v�̃p�X
	string mapPath;

	//�}�b�v�̃p�X��ݒ�
	switch (number)
	{
	case 0:	
		break;
	default:
		break;
	}

	//csv����}�b�v��ǂݍ���
	LoadMap(mapPath);
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Map::~Map()
{

}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�`�揈��
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void Map::Draw() const
{
	for (int i = 0; i < GameMain::MAP_Y; i++)
	{
		for (int j = 0; j < GameMain::MAP_X; j++)
		{
			switch (m_map[i][j])
			{
			//�Ǖ`��
			case O:		
				break;

			//�ʘH�`��
			case P:		
				break;

			default:
				break;
			}
		}
	}
}



//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :csv����}�b�v��ǂݍ���
//�b����  :csv�̃p�X(string)
//�b�߂�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void Map::LoadMap(string path)
{
	//�f�[�^�ǂݍ��ݗp
	ifstream ifs(path);
	string str;
	int data[GameMain::MAP_X*GameMain::MAP_Y];
	
	int dataCnt = 0;

	//csv�̃f�[�^���J���}���΂��ēǂݍ���
	while (getline(ifs, str))
	{
		string token;
		istringstream stream(str);

		while (getline(stream, token, ','))
		{
			data[dataCnt] = atoi(token.c_str());
			dataCnt++;
		}
	}
	
	// �f�[�^����
	for (int i = 0; i < GameMain::MAP_Y; i++)
	{
		for (int j = 0; j < GameMain::MAP_X; j++)
		{
			int num = j + (i*j);

			// �f�[�^����
			m_map[i][j] = data[num];
			
			//�v���C���[�̏����ʒu��ۑ�
			if (data[num] == PLAYER)
			{
				m_playerInitialPos.push_back(Tile{ i, j });
				m_map[i][j] = P;
			}

			//�G�̏����ʒu��ۑ�
			if (data[num] == ENEMY)
			{
				m_enemyInitialPos.push_back(Tile{ i, j });
				m_map[i][j] = P;
			}
		}
	}
}
