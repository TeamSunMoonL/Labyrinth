//************************************************/
//* @file  :AI.cpp
//* @brief :AI�̃\�[�X�t�@�C��
//* @date  :2017/03/27
//* @author:S.Katou
//************************************************/
#include "AI.h"
#include "Astar\Astar.h"
#include "../../Game.h"


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�R���X�g���N�^
//�b����  :�����̑���(int)
//�b����  :���G�͈́@(int)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
AI::AI(int attribute, int range)
	:m_attribute(attribute)
	,m_searchRange(range)
{

}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :���Ɉړ�������W���擾
//�b����  :�Ȃ�(void)
//�b�߂�l:���W(Tile)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Tile AI::GetNext()
{
	//���ɐi�ލ��W���擾
	Tile nextTile = m_route[m_next];

	//���̍��W���i�s�s�\�Ȃ��
	if (m_map[nextTile.row][nextTile.column] != P)
	{
		//���̈ʒu��Ԃ�
		nextTile = m_route[m_next - 1];
	}
	else
	{
		//�i�s�\�Ȃ��
		//���֐i�߂�
		m_next++;
	}

	//���W��Ԃ�
	return nextTile;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�����}�b�v�̍X�V����
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void AI::UpdateAttributeMap()
{

}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :���؂̍X�V����
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void AI::UpdateRoute()
{
	if (m_start.row    != m_target.row
	  ||m_start.column != m_target.column)
	{
		//A*�@
		AStar astar;

		//������
		astar.Initialize(m_map, m_start, m_target);

		//�T��
		astar.Search();

		//���؂��擾
		m_route = astar.GetRoute();

		//�I������
		astar.Finalize();
	
		//���ɐi�ލ��W�����Z�b�g
		m_next = 0;
	}
}

