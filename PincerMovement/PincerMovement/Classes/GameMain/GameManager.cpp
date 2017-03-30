//************************************************/
//* @file  :gameManager.cpp
//* @brief :�Q�[�����Ǘ�����N���X�̃\�[�X�t�@�C��
//* @date  :2017/03/30
//* @author:S.Katou
//************************************************/

// �w�b�_�t�@�C���̃C���N���[�h
#include "GameManager.h"
#include <fstream>
#include <sstream>
#include "GameMain.h"
#include "../AI/Astar/Node.h"
#include "../Map/Map.h"

using namespace std;

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�X�V����
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void GameManager::Update()
{
	//Map�N���X�����b�}�b�v�����擾
	m_attributeMap = m_map->Get();

	//�v���C���[�̈ʒu�̑�����ύX
	m_player;

	//�G�̈ʒu�̑�����ύX
	m_enemy;
}



//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�ۊǂ��Ă���f�[�^������
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void GameManager::Reset()
{
	m_player.clear();
	m_enemy.clear();
	m_target.clear();
}


/*--[�ȉ��B��]--*/

GameManager::GameManager()
	:m_attributeMap(GameMain::MAP_Y,vector<int>(GameMain::MAP_X))
{

}

GameManager::~GameManager()
{

}
