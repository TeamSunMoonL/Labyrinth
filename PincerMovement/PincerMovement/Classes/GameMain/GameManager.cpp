//************************************************/
//* @file  :gameManager.cpp
//* @brief :�Q�[�����Ǘ�����N���X�̃\�[�X�t�@�C��
//* @date  :2017/03/14
//* @author:K.Yamamoro
//************************************************/

// �w�b�_�t�@�C���̃C���N���[�h
#include "GameManager.h"
#include <fstream>
#include <sstream>
#include "GameMain.h"
#include "../AI/Astar/Node.h"

using namespace std;

void GameManager::Update()
{
	//Map�N���X�����b�}�b�v�����擾
	
	vector<int>::iterator itrY;
	vector<vector<int>>::iterator itrX;

	for (itrX = m_map.begin(); itrX != m_map.end(); itrX++)
	{
		for (itrY = itrX->begin(); itrY < itrX->end(); itrY++)
		{
			//�}�b�v�f�[�^�R�s�[
			m_map;

			m_player;
		}
	}
	m_map;

	
}

void GameManager::RegisterPlayer(Player * pPlayer)
{

}






/*--[�ȉ��B��]--*/

GameManager::GameManager()
	:m_map(GameMain::MAP_Y,vector<int>(GameMain::MAP_X))
{

}

GameManager::~GameManager()
{

}
