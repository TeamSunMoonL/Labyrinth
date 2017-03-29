//************************************************/
//* @file  :Matrix.cpp
//* @brief :�s��p�̃��b�v�N���X
//* @date  :2017/02/22
//* @author:S.Katou
//************************************************/
#include "Matrix.h"

#include "../../ShunLib/Conversion.h"

using namespace ShunLib;

Matrix Matrix::Identity;

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :���s�ړ��s��̍쐬
//�b����  :�ړ���̈ʒu(Vec3)
//�b�߂�l:�s��(Matrix)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix Matrix::CreateTranslation(const Vec3& pos)
{
	Matrix matrix;
	matrix.m_matrix[3][0] += pos.m_x;
	matrix.m_matrix[3][1] += pos.m_y;
	matrix.m_matrix[3][2] += pos.m_z;

	return matrix;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�w����]�s��̍쐬
//�b����  :�p�x(float)
//�b�߂�l:�s��(Matrix)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix Matrix::CreateRotationX(float angle)
{
	Matrix matrix;
	matrix.m_matrix[1][1] =  cos(ToRadian(angle));
	matrix.m_matrix[1][2] = -sin(ToRadian(angle));
	matrix.m_matrix[2][1] =  sin(ToRadian(angle));
	matrix.m_matrix[2][2] =  cos(ToRadian(angle));

	return matrix;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�x����]�s��̍쐬
//�b����  :�p�x(float)
//�b�߂�l:�s��(Matrix)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix Matrix::CreateRotationY(float angle)
{
	Matrix matrix;
	matrix.m_matrix[0][0] =  cos(ToRadian(angle));
	matrix.m_matrix[0][2] =  sin(ToRadian(angle));
	matrix.m_matrix[2][0] = -sin(ToRadian(angle));
	matrix.m_matrix[2][2] =  cos(ToRadian(angle));

	return matrix;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�y����]�s��̍쐬
//�b����  :�p�x(float)
//�b�߂�l:�s��(Matrix)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix Matrix::CreateRotationZ(float angle)
{
	Matrix matrix;
	matrix.m_matrix[0][0] =  cos(ToRadian(angle));
	matrix.m_matrix[0][1] = -sin(ToRadian(angle));
	matrix.m_matrix[1][0] =  sin(ToRadian(angle));
	matrix.m_matrix[1][1] =  cos(ToRadian(angle));

	return matrix;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�g��k���s��̍쐬
//�b����  :�g�嗦(Vec3)
//�b�߂�l:�s��(Matrix)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix Matrix::CreateScale(const Vec3& scale)
{

	Matrix matrix;
	matrix.m_matrix[0][0] *= scale.m_x;
	matrix.m_matrix[1][1] *= scale.m_y;
	matrix.m_matrix[2][2] *= scale.m_z;

	return matrix;
}



//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�g��k���s��̍쐬
//�b����  :�g�嗦(float)
//�b�߂�l:�s��(Matrix)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix Matrix::CreateScale(float scale)
{
	Matrix matrix;
	matrix.m_matrix[0][0] *= scale;
	matrix.m_matrix[1][1] *= scale;
	matrix.m_matrix[2][2] *= scale;

	return matrix;
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�ˉe�s��̍쐬
//�b����  :����p�@�@�@�@�@�@(float)
//�b����  :�A�X�y�N�g��@�@�@(float)
//�b����  :�߃N���b�v�ʂ̋���(float)
//�b����  :���N���b�v�ʂ̋���(float)
//�b�߂�l:�ˉe�s��(Matrix)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix Matrix::CreateProj(float fov, float aspectRatio, float nearPlane, float farPlane)
{
	Matrix proj = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(ToRadian(fov),aspectRatio,nearPlane, farPlane);
	return proj;
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�t�H���g�R���X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix::Matrix()
{
	
	float matrix[4][4] =
	{
		{ 1.0f, 0.0f, 0.0f, 0.0f },
		{ 0.0f, 1.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f, 1.0f },
	};

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_matrix[i][j] = matrix[i][j];
		}
	}

}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�R�s�[�R���X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix::Matrix(const Matrix& M)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->m_matrix[i][j] = M.m_matrix[i][j];
		}
	}
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :DirectX�s��ϊ��R���X�g���N�^
//�b����  :DirectX�̍s��(DirectX::SimpleMath::Matrix)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix::Matrix(const DirectX::SimpleMath::Matrix& M)
{
	float m[4][4] =
	{
		{ M._11,M._12,M._13,M._14 },
		{ M._21,M._22,M._23,M._24 },
		{ M._31,M._32,M._33,M._34 },
		{ M._41,M._42,M._43,M._44 },
	};

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->m_matrix[i][j] = m[i][j];
		}
	}

}

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�X�g���N�^	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix::~Matrix()
{
	
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�s���DirectX�̌`���ŕԂ�
//�b����  :�Ȃ�(void)
//�b�߂�l:�s��(Matrix)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
DirectX::SimpleMath::Matrix Matrix::GetDirectMatrix()const
{
	DirectX::SimpleMath::Matrix matrix =
		DirectX::SimpleMath::Matrix(m_matrix[0][0], m_matrix[0][1], m_matrix[0][2], m_matrix[0][3],
									m_matrix[1][0], m_matrix[1][1], m_matrix[1][2], m_matrix[1][3], 
									m_matrix[2][0], m_matrix[2][1], m_matrix[2][2], m_matrix[2][3], 
									m_matrix[3][0], m_matrix[3][1], m_matrix[3][2], m_matrix[3][3]);
	return matrix;
}



/*--[�ȉ����Z�q�̃I�[�o�[���[�h]--*/

Matrix& Matrix::operator=(const Matrix& M)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->m_matrix[i][j] = M.m_matrix[i][j];
		}
	}

	return *this;
}

Matrix& Matrix::operator=(const DirectX::SimpleMath::Matrix& M)
{
	float m[4][4]=
	{
		{ M._11,M._12,M._13,M._14 },
		{ M._21,M._22,M._23,M._24 },
		{ M._31,M._32,M._33,M._34 },
		{ M._41,M._42,M._43,M._44 },
	};

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->m_matrix[i][j] = m[i][j];
		}
	}

	return *this;
}

Matrix& Matrix::operator+(const Matrix& M)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->m_matrix[i][j] += M.m_matrix[i][j];
		}
	}

	return *this;

	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
}

Matrix& Matrix::operator-(const Matrix& M)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->m_matrix[i][j] -= M.m_matrix[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator*(const Matrix& M)
{
	// �P�s�ڂ̌v�Z
	float x = this->m_matrix[0][0];
	float y = this->m_matrix[0][1];
	float z = this->m_matrix[0][2];
	float w = this->m_matrix[0][3];
	this->m_matrix[0][0] = (M.m_matrix[0][0] * x) + (M.m_matrix[1][0] * y) + (M.m_matrix[2][0] * z) + (M.m_matrix[3][0] * w);
	this->m_matrix[0][1] = (M.m_matrix[0][1] * x) + (M.m_matrix[1][1] * y) + (M.m_matrix[2][1] * z) + (M.m_matrix[3][1] * w);
	this->m_matrix[0][2] = (M.m_matrix[0][2] * x) + (M.m_matrix[1][2] * y) + (M.m_matrix[2][2] * z) + (M.m_matrix[3][2] * w);
	this->m_matrix[0][3] = (M.m_matrix[0][3] * x) + (M.m_matrix[1][3] * y) + (M.m_matrix[2][3] * z) + (M.m_matrix[3][3] * w);
	
	// �Q�s�ڂ̌v�Z
	x = this->m_matrix[1][0];
	y = this->m_matrix[1][1];
	z = this->m_matrix[1][2];
	w = this->m_matrix[1][3];
	this->m_matrix[1][0] = (M.m_matrix[0][0] * x) + (M.m_matrix[1][0] * y) + (M.m_matrix[2][0] * z) + (M.m_matrix[3][0] * w);
	this->m_matrix[1][1] = (M.m_matrix[0][1] * x) + (M.m_matrix[1][1] * y) + (M.m_matrix[2][1] * z) + (M.m_matrix[3][1] * w);
	this->m_matrix[1][2] = (M.m_matrix[0][2] * x) + (M.m_matrix[1][2] * y) + (M.m_matrix[2][2] * z) + (M.m_matrix[3][2] * w);
	this->m_matrix[1][3] = (M.m_matrix[0][3] * x) + (M.m_matrix[1][3] * y) + (M.m_matrix[2][3] * z) + (M.m_matrix[3][3] * w);

	// �R�s�ڂ̌v�Z
	x = this->m_matrix[2][0];
	y = this->m_matrix[2][1];
	z = this->m_matrix[2][2];
	w = this->m_matrix[2][3];
	this->m_matrix[2][0] = (M.m_matrix[0][0] * x) + (M.m_matrix[1][0] * y) + (M.m_matrix[2][0] * z) + (M.m_matrix[3][0] * w);
	this->m_matrix[2][1] = (M.m_matrix[0][1] * x) + (M.m_matrix[1][1] * y) + (M.m_matrix[2][1] * z) + (M.m_matrix[3][1] * w);
	this->m_matrix[2][2] = (M.m_matrix[0][2] * x) + (M.m_matrix[1][2] * y) + (M.m_matrix[2][2] * z) + (M.m_matrix[3][2] * w);
	this->m_matrix[2][3] = (M.m_matrix[0][3] * x) + (M.m_matrix[1][3] * y) + (M.m_matrix[2][3] * z) + (M.m_matrix[3][3] * w);

	// �S�s�ڂ̌v�Z
	x = this->m_matrix[3][0];
	y = this->m_matrix[3][1];
	z = this->m_matrix[3][2];
	w = this->m_matrix[3][3];
	this->m_matrix[3][0] = (M.m_matrix[0][0] * x) + (M.m_matrix[1][0] * y) + (M.m_matrix[2][0] * z) + (M.m_matrix[3][0] * w);
	this->m_matrix[3][1] = (M.m_matrix[0][1] * x) + (M.m_matrix[1][1] * y) + (M.m_matrix[2][1] * z) + (M.m_matrix[3][1] * w);
	this->m_matrix[3][2] = (M.m_matrix[0][2] * x) + (M.m_matrix[1][2] * y) + (M.m_matrix[2][2] * z) + (M.m_matrix[3][2] * w);
	this->m_matrix[3][3] = (M.m_matrix[0][3] * x) + (M.m_matrix[1][3] * y) + (M.m_matrix[2][3] * z) + (M.m_matrix[3][3] * w);
	
	return *this;
}

Matrix& Matrix::operator*(int num)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j  < 4; j ++)
		{
			this->m_matrix[i][j] *= num;
		}
	}
	
	return *this;
}