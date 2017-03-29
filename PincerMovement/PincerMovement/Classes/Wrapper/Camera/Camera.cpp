//************************************************/
//* @file  :Camera.cpp
//* @brief :�J�����̃��b�v�N���X
//* @date  :2017/02/22
//* @author:S.Katou
//************************************************/
#include "Camera.h"
#include <d3d11.h>
#include <SimpleMath.h>

using namespace ShunLib;

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�t�H���g�R���X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Camera::Camera()
	: m_eye(0.0f,0.0f,1.0f)
	, m_target(0.0f,0.0f,0.0f)
	, m_up(0.0f,1.0f,0.0f)
{
	m_view = DirectX::SimpleMath::Matrix::CreateLookAt(m_eye.GetDirectVec3(), m_target.GetDirectVec3(), m_up.GetDirectVec3());
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�[�^�w��R���X�g���N�^
//�b����  :�J�����ʒu(Vec3)
//�b����  :�����_	 (Vec3)
//�b����  :�����	 (Vec3)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Camera::Camera(ShunLib::Vec3 eye, ShunLib::Vec3 target, ShunLib::Vec3 up)
	: m_eye(eye)
	, m_target(target)
	, m_up(up)
{
	m_view = DirectX::SimpleMath::Matrix::CreateLookAt(m_eye.GetDirectVec3(), m_target.GetDirectVec3(), m_up.GetDirectVec3());
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Camera::~Camera()
{

}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�r���[�s���Ԃ�
//�b����  :�Ȃ�		 (void)
//�b�߂�l:�r���[�s��(Matrix)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
const Matrix& Camera::GetView() const
{
	return m_view;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�X�V����
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void Camera::Update()
{
	m_view = DirectX::SimpleMath::Matrix::CreateLookAt(m_eye.GetDirectVec3(), m_target.GetDirectVec3(), m_up.GetDirectVec3());
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�J�����ʒu��ݒ肷��
//�b����  :�J�����ʒu(Vec3)
//�b�߂�l:�Ȃ�		 (void)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void Camera::SetEyePos(ShunLib::Vec3 eye)
{
	m_eye = eye;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�����_��ݒ肷��
//�b����  :�����_(Vec3)
//�b�߂�l:�Ȃ�(void)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void Camera::SetTarget(ShunLib::Vec3 target)
{
	m_target = target;
}
