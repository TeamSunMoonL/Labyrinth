//************************************************/
//* @file  :gameManager.h
//* @brief :�Q�[�����Ǘ�����N���X�̃w�b�_�[�t�@�C��
//* @date  :2017/03/29
//* @author:S.Katou
//************************************************/
#pragma once

#include <string>
#include <vector>

class Player;
class Enemy;

class GameManager
{
private:
	// �}�b�v
	std::vector<std::vector<int>> m_map;

	// �v���C���[
	std::vector<Player*> m_player;
	
	// �G
	std::vector<Enemy*> m_enemy;


public:
	//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
	//�b�@�\  :�C���X�^���X�̐����@�擾(�V���O���g��)
	//�b����  :�Ȃ�(void)
	//�b�߂�l:�C���X�^���X(GameManager*)	
	//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
	static GameManager* GetInstance()
	{
		static GameManager inst;
		return &inst;
	}

	// �}�b�v�̍X�V
	void Update();

	// �v���C���[�̓o�^
	void RegisterPlayer(Player* pPlayer);

	// �G�̍쐬

private: // �B��

	// �R���X�g���N�^
	GameManager();

	~GameManager();
};

