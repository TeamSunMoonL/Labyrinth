//************************************************/
//* @file  :AttackAI.h
//* @brief :1�̃^�[�Q�b�g��ǂ�������AI�̃\�[�X�t�@�C��
//* @date  :2017/03/29
//* @author:S.Katou
//************************************************/
#include "../../pch.h"
#include "AttackAI.h"

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�R���X�g���N�^
//�b����  :�����̑���(int)
//�b����  :���G�͈́@(int)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
AttackAI::AttackAI(int attribute, int range)
	:AI(attribute,range)
{
	//�^�[�Q�b�g�ݒ�
	//(GameManager����擾�\��)
	

}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�X�V����
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void AttackAI::Update(const Tile& start)
{
	//���݈ʒu�X�V
	m_start = start;

	//�}�b�v�̍X�V
	m_map = m_manager->GetMap();

	//���[�g������G
	if (Search())
	{
		//���[�g��ɓG�������ꍇ
		//���؂̍X�V
		UpdateRoute();
	}
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :���[�g������G
//�b����  :�Ȃ�(void)
//�b�߂�l:����������true(bool)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
bool AttackAI::Search()
{
	//���G����^�C��
	Tile tile = m_route[m_next];

	//�����������ǂ���
	bool isDiscovery = false;

	//���[�g��ɉ����������ꍇtrue��Ԃ�
	if (m_map[tile.row][tile.column] != P)
	{
		isDiscovery = true;
	}
	else
	{
		//���Ȃ������ꍇ�@���̃^�C����T��
		isDiscovery = Search(m_next + 1);
	}

	return isDiscovery;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :���G�i�ċA�p�j
//�b����  :�T���^�C���ԍ�(int)
//�b�߂�l:����������true(bool)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
bool AttackAI::Search(int num)
{
	//���G�͈͂𒴂��Ă�����I��
	if (num >= m_next + m_searchRange)
	{
		return false;
	}

	//���G����^�C��
	Tile tile = m_route[num];

	//�����������ǂ���
	bool isDiscovery = false;
	
	//���[�g��ɉ����������ꍇtrue��Ԃ�
	if (m_map[tile.row][tile.column] != P)
	{
		isDiscovery = true;
	}
	else
	{
		//���Ȃ������ꍇ�@���̃^�C����T��
		isDiscovery = Search(m_next + 1);
	}

	return isDiscovery;
}
