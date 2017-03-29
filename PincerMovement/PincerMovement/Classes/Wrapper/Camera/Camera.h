//************************************************/
//* @file  :Camera.h
//* @brief :�J�����̃��b�v�N���X
//* @date  :2017/02/22
//* @author:S.Katou
//************************************************/
#pragma once
#include "../Matrix/Matrix.h"
#include "../Vec3/Vec3.h"

class Camera
{

private:
	//�r���[�s��
	ShunLib::Matrix m_view;		

	//�J�����ʒu
	ShunLib::Vec3   m_eye;		
	
	//�����_
	ShunLib::Vec3   m_target;	
	
	//�����
	ShunLib::Vec3   m_up;		

public:
	//�f�t�H���g�R���X�g���N�^
	Camera();

	//�f�[�^�w��R���X�g���N�^
	Camera(ShunLib::Vec3 eye, ShunLib::Vec3 target, ShunLib::Vec3 up);
	
	//�f�X�g���N�^
	~Camera();

	//�r���[�s���Ԃ�
	const ShunLib::Matrix& GetView()const;

	//�X�V����
	void Update();

	//�J�����ʒu��ݒ肷��
	void SetEyePos(ShunLib::Vec3 eye);
	
	//�����_��ݒ肷��
	void SetTarget(ShunLib::Vec3 target);
};
