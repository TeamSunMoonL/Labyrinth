//************************************************/
//* @file  :Object.h
//* @brief :Object�̃w�b�_�[�t�@�C��
//* @date  :2017/03/29
//* @author:K.Yamamoto
//************************************************/

// ���d�C���N���[�h�h�~
#pragma once

// �w�b�_�t�@�C���̃C���N���[�h
#include "../Wrapper/Model/Model.h"
#include "../Wrapper/Vec2/Vec2.h"
#include "../AI/AI.h"

#include "../Wrapper/Model/Model.h"
#include "../Wrapper/Matrix/Matrix.h"

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

	// �^�C�����W
	YamagenLib::Vec2 m_tilePos;

	// 3D���f��
	ShunLib::Model m_model;

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

	// �^�C�����W�擾
	YamagenLib::Vec2 GetTilePos() { return m_tilePos; }

	// �͂��܂ꔻ��
	bool SandwichedDecision();
	
	// �������z�֐�
	virtual void Draw() = 0;	// �`��
	virtual void Move() = 0;	// �ړ�
	virtual void Update() = 0;	// �X�V
};
