//************************************************/
//* @file  :Map.cpp
//* @brief :�}�b�v�N���X�̃\�[�X�t�@�C��
//* @date  :2017/04/03
//* @author:S.Katou
//************************************************/
#include "Map.h"
#include <fstream>
#include <sstream>

#include "../AI/Astar/Astar.h"
#include "../GameMain/GameMain.h"
#include "../Wrapper/Vec3/Vec3.h"

using namespace std;
using namespace ShunLib;

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�R���X�g���N�^
//�b����  :�}�b�v�̔ԍ�(int)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Map::Map(int number)
	:m_map(GameMain::MAP_Y,vector<int>(GameMain::MAP_X))
	, m_wall(DirectX::GeometricPrimitive::CreateBox(GameMain::m_deviceResources->GetD3DDeviceContext(), Vec3(1, 1, 1).GetDirectVec3()))
	, m_road(DirectX::GeometricPrimitive::CreateBox(GameMain::m_deviceResources->GetD3DDeviceContext(), Vec3(1, 1, 1).GetDirectVec3()))
{
	//�}�b�v�̃p�X
	string mapPath;

	//�}�b�v�̃p�X��ݒ�
	switch (number)
	{
	case 0:	
		mapPath = "Map\\Map1.csv";
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
void Map::Draw(const Matrix& world,
			   const Matrix& view,
			   const Matrix& proj)const
{
	for (int i = 0; i < GameMain::MAP_Y; i++)
	{
		for (int j = 0; j < GameMain::MAP_X; j++)
		{
			//���W�ݒ�
			Matrix w = world;
			w = w * Matrix::CreateTranslation(Vec3(static_cast<float>(j)*GameMain::CHIP_SIZE, 0.0f, static_cast<float>(i)*GameMain::CHIP_SIZE));
			
			switch (m_map[i][j])
			{
			//�Ǖ`��
			case O:		
				m_wall->Draw(w.GetDirectMatrix(), view.GetDirectMatrix(), proj.GetDirectMatrix(), DirectX::Colors::Gray);
				break;

			//�ʘH�`��
			case P:		
				m_road->Draw(w.GetDirectMatrix(), view.GetDirectMatrix(), proj.GetDirectMatrix(), DirectX::Colors::Brown);
				break;

			default:
				break;
			}
		}
	}


}



//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�w��ʒu�̃}�b�v�̑������擾
//�b����  :���W(Tile)
//�b�߂�l:����(int)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
int Map::Get(const Tile& tile)
{
	return m_map[tile.row][tile.column]; 
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�w�肵���v���C���[or�G�̏����ʒu���擾
//�b����  :PLAYER or ENEMY (int)
//�b����  :�I�u�W�F�N�g�ԍ�(int)
//�b�߂�l:�����ʒu(Tile)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
const Tile& Map::Get(int charactor, int num)
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
	const int MAP_MAX = GameMain::MAP_X*GameMain::MAP_Y;
	int data[MAP_MAX];
	
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

		if (dataCnt >= MAP_MAX)
		{
			break;
		}
	}
	
	int num = 0;

	// �f�[�^����
	for (int i = 0; i < GameMain::MAP_Y; i++)
	{
		for (int j = 0; j < GameMain::MAP_X; j++)
		{
			// �f�[�^����
			m_map[i][j] = data[num];
			num++;

			//�v���C���[�̏����ʒu��ۑ�
			if (m_map[i][j] == PLAYER)
			{
				m_playerInitialPos.push_back(Tile{ i, j });
				m_map[i][j] = P;
			}

			//�G�̏����ʒu��ۑ�
			if (m_map[i][j] == ENEMY)
			{
				m_enemyInitialPos.push_back(Tile{ i, j });
				m_map[i][j] = P;
			}
		}
	}
}
