//************************************************/
//* @file  :Object.h
//* @brief :Object�̃w�b�_�[�t�@�C��
//* @date  :2017/03/29
//* @author:K.Yamamoto
//************************************************/

// ���d�C���N���[�h�h�~
#pragma once

// �w�b�_�t�@�C���̃C���N���[�h
#include "../Wrapper/Vec2/Vec2.h"
#include "../AI/AI.h"
// �񋓌^
enum Direction
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};

// ���
enum State
{

};

// Object�N���X
class Object
{
protected:
	// ���W
	YamagenLib::Vec2 m_pos;

	// 3D���f��

	// ����
	Direction m_direction;

	// ���x
	YamagenLib::Vec2 m_speed;

	// ���
	State m_state;

	// AI
	AI* m_AI;

public:
	// �f�t�H���g�R���X�g���N�^
	Object();

	// �f�X�g���N�^
	~Object();

};
