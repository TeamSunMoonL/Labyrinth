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
//�b�@�\  :���Ɉړ�������W���擾
//�b����  :�Ȃ�(void)
//�b�߂�l:���W(Tile)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Tile AI::GetNext()
{
	//���W��Ԃ�
	return m_next;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�X�V����
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void AI::Update()
{
	//���̎擾


	//���؂̍X�V
	UpdateRoute();
}



//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :���؂̍X�V����
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void AI::UpdateRoute()
{
	if (m_start.row    != m_end.row
	  ||m_start.column != m_end.column)
	{

		//A*�@
		AStar astar;

		//������
		astar.Initialize(m_map, m_start, m_end);

		//�T��
		astar.Search();

		//���؂��擾
		m_next = astar.GetNext();

		//�I������
		astar.Finalize();
	}
}


