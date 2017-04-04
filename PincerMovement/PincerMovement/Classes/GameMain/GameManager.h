//************************************************/
//* @file  :GameManager.h
//* @brief :�Q�[�����Ǘ�����N���X�̃w�b�_�[�t�@�C��
//* @date  :2017/04/04
//* @author:S.Katou
//************************************************/
#pragma once

#include <string>
#include <vector>

class Player;
class Enemy;
class DefenseTarget;
class Map;

class GameManager
{
private:
	// �����}�b�v
	std::vector<std::vector<int>> m_attributeMap;

	// �v���C���[
	std::vector<Player*> m_player;
	
	// �G
	std::vector<Enemy*> m_enemy;

	//�h�q�Ώ�
	std::vector<DefenseTarget*>m_target;

	//�}�b�v
	Map* m_map;

public:
	//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
	//�b�@�\  :�C���X�^���X�̐����@�擾(�V���O���g��)
	//�b����  :�Ȃ�(void)
	//�b�߂�l:�C���X�^���X(GameManager*)	
	//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
	static GameManager* GetInstance()
	{
		static GameManager instance;
		return &instance;
	}

	// �o�^
	void Register(Player* player)		 { m_player.push_back(player);}
	void Register(Enemy* enemy)			 { m_enemy.push_back(enemy);  }
	void Register(DefenseTarget* target) { m_target.push_back(target);}
	void Register(Map* map);

	//�擾
	std::vector<Player*>& GetTarget()		 { return m_player; }
	std::vector<Enemy*>& GetEnemy()			 { return m_enemy;  }
	std::vector<DefenseTarget*>& GetPlayer() { return m_target; }

	// �}�b�v�̍X�V
	void Update();


	//�}�b�v�̎擾
	const std::vector<std::vector<int>>& GetMap() { return m_attributeMap; }

	//����������
	void Reset();



	/*--[�ȉ��B��]--*/
private: 

	// �R���X�g���N�^���f�X�g���N�^
	GameManager();
	~GameManager();
};

