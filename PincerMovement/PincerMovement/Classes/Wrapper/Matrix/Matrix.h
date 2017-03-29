//************************************************/
//* @file  :Matrix.h
//* @brief :�s��p�̃��b�v�N���X
//* @date  :2017/02/21
//* @author:S.Katou
//************************************************/
#pragma once
#include <d3d11.h>
#include <SimpleMath.h>
#include "../Vec3/Vec3.h"

namespace ShunLib
{
	class Matrix
	{
		/*--[�ÓI�Ȃ��]--*/
	public:
		//�P�ʍs��
		static Matrix Identity;

	public:
		//���s�ړ��s��
		static Matrix CreateTranslation(const Vec3& pos);

		//��]�s��
		static Matrix CreateRotationX(float angle);
		static Matrix CreateRotationY(float angle);
		static Matrix CreateRotationZ(float angle);

		//�g��k���s��
		static Matrix CreateScale(const Vec3& scale);
		static Matrix CreateScale(float scale);

		static Matrix CreateProj(float fov,
								 float aspectRatio,
							     float nearPlane,
							     float farPlane);

		/*--[�ÓI�ł͂Ȃ����]--*/
	private:
		float m_matrix[4][4];

	public:
		Matrix();
		Matrix(const Matrix& M);
		Matrix(const DirectX::SimpleMath::Matrix& M);
		~Matrix();

		//�s���DirectX�̌`���ŕԂ�
		DirectX::SimpleMath::Matrix GetDirectMatrix()const;


		/*--[���Z�q�̃I�[�o�[���[�h]--*/
		Matrix& operator=(const Matrix& M);
		Matrix& operator=(const DirectX::SimpleMath::Matrix& M);
		Matrix& operator+(const Matrix& M);
		Matrix& operator-(const Matrix& M);
		Matrix& operator*(const Matrix& M);
		Matrix& operator*(int num);
	};
}