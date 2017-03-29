//************************************************/
//* @file  :Vec3.h
//* @brief :�R�����x�N�g���p�̃��b�v�N���X
//* @date  :2017/02/22
//* @author:S.Katou
//************************************************/
#pragma once
#include <d3d11.h>
#include <SimpleMath.h>

namespace ShunLib
{
	class Vec3
	{
	public:
		float m_x;
		float m_y;
		float m_z;

	public:
		Vec3();
		Vec3(float x, float y, float z);
		~Vec3();

		//�x�N�g����DirectX�̌`���ŕԂ�
		DirectX::SimpleMath::Vector3 GetDirectVec3();
	
		/*--[���Z�q�̃I�[�o�[���[�h]--*/
		Vec3& operator=(const Vec3& V);
		Vec3& operator=(const DirectX::SimpleMath::Vector3& V);
		Vec3& operator+(const Vec3& V);
		Vec3& operator-(const Vec3& V);
		Vec3& operator*(int num);

	};
}