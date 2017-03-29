//************************************************/
//* @file  :Vec3.cpp
//* @brief :�R�����x�N�g���p�̃��b�v�N���X
//* @date  :2017/02/17
//* @author:S.Katou
//************************************************/
#include "Vec3.h"
using namespace ShunLib;

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�t�H���g�R���X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Vec3::Vec3()
	:m_x(0)
	,m_y(0)
	,m_z(0)
{

}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�l�w��R���X�g���N�^
//�b����  :X,Y,Z(float,float,float)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Vec3::Vec3(float x, float y, float z)
	:m_x(x)
	,m_y(y)
	,m_z(z)
{

}

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Vec3::~Vec3()
{

}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�x�N�g����DirectX�̌`���ŕԂ�
//�b����  :�Ȃ��@�@(void)
//�b�߂�l:�x�N�g��(DirectX::SimpleMath::Vector3)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
DirectX::SimpleMath::Vector3 ShunLib::Vec3::GetDirectVec3()
{
	DirectX::SimpleMath::Vector3 vec;
	vec.x = m_x;
	vec.y = m_y;
	vec.z = m_z;
	return vec;
}

/*--[�ȉ��@���Z�q�̃I�[�o�[���[�h]--*/

Vec3& ShunLib::Vec3::operator=(const Vec3& V)
{
	this->m_x = V.m_x;
	this->m_y = V.m_y;
	this->m_z = V.m_z;

	return *this;
}

Vec3& ShunLib::Vec3::operator=(const DirectX::SimpleMath::Vector3& V)
{
	this->m_x = V.x;
	this->m_y = V.y;
	this->m_z = V.z;

	return *this;
}

Vec3& ShunLib::Vec3::operator+(const Vec3& V)
{
	this->m_x += V.m_x;
	this->m_y += V.m_y;
	this->m_z += V.m_z;
	return *this;
}

Vec3& ShunLib::Vec3::operator-(const Vec3& V)
{
	this->m_x -= V.m_x;
	this->m_y -= V.m_y;
	this->m_z -= V.m_z;
	return *this;
}

Vec3& ShunLib::Vec3::operator*(int num)
{
	this->m_x *= num;
	this->m_y *= num;
	this->m_z *= num;
	return *this;
}
