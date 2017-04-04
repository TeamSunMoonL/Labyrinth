//************************************************/
//* @file  :AI.cpp
//* @brief :AI�̃\�[�X�t�@�C��
//* @date  :2017/04/03
//* @author:S.Katou
//************************************************/
#include "AI.h"
#include "Astar\Astar.h"
#include "../../Game.h"
#include "../GameMain/GameManager.h"

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�R���X�g���N�^
//�b����  :�����̑���(int)
//�b����  :���G�͈́@(int)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
AI::AI(int attribute, int range)
	:m_attribute(attribute)
	,m_searchRange(range)
	,m_next(0)
	, m_model(DirectX::GeometricPrimitive::CreateSphere(GameMain::m_deviceResources->GetD3DDeviceContext()))
{
	m_manager = GameManager::GetInstance();
	m_map = m_manager->GetMap();
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :���Ɉړ�������W���擾
//�b����  :�Ȃ�(void)
//�b�߂�l:���W(Tile)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Tile AI::GetNext()
{
	//���ɐi�ލ��W���擾
	//���[�g���������
	if (static_cast<int>(m_route.size()) <= m_next)
	{
		//�I������
		return m_route[m_next - 1];
	}

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
	if (ShouldUpdateRoute())
	{
		//A*�@
		AStar astar;

		//������
		astar.Initialize(m_manager->GetMap(), m_start, m_target);

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


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :���؂̍X�V������ׂ����ǂ�����Ԃ�
//�b����  :�Ȃ�(void)
//�b�߂�l:�X�V�̕K�v�������true(bool)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
bool AI::ShouldUpdateRoute()
{
	vector<Tile>::iterator itr;

	for (itr = m_target.begin(); itr < m_target.end(); itr++)
	{
		if (m_start.row == itr->row
		 || m_start.column == itr->column)
		{
			//���݈ʒu�ƃ^�[�Q�b�g���P�ł���v���Ă����ꍇ
			return false;
		}
	}

	return true;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�����_���Œʉ߉\�^�C�����擾
//�b����  :�Ȃ�(void)
//�b�߂�l:�^�C��(TIle)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void AI::RandamTarget()
{
	if (m_target.empty() != true)
	{
		m_target.clear();
		m_target.shrink_to_fit();
		m_target.push_back(Tile{ 0,0 });
	}
	else
	{
		m_target.push_back(Tile{ 0,0 });
	}


	m_target[0].column = rand() % GameMain::MAP_X;
	m_target[0].row = rand() % GameMain::MAP_Y;

	if (m_map[m_target[0].row][m_target[0].column] != P)
	{
		RandamTarget();
	}

}
