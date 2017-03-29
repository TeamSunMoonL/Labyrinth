//************************************************/
//* @file  :Model.h
//* @brief :���f���p�̃��b�v�N���X
//* @date  :2017/02/21
//* @author:S.Katou
//************************************************/
#pragma once
#include <d3d11.h>
#include <SimpleMath.h>
#include <Model.h>
#include <Effects.h>
#include "../Vec3/Vec3.h"
#include "../Matrix/Matrix.h"

namespace ShunLib
{
	class Model
	{
	private:
		//���f���f�[�^
		std::unique_ptr<DirectX::Model> m_model;

		//�G�t�F�N�g�f�[�^
		std::unique_ptr<DirectX::EffectFactory> m_effect;

	public:
		//�f�t�H���g�R���X�g���N�^�@���{�b�g
		Model();

		//�t�@�C���w��R���X�g���N�^
		Model(const wchar_t[]);

		//�f�X�g���N�^
		~Model();

		//�`��
		void Draw(const Matrix& world,
				  const Matrix& view,
				  const Matrix& proj);
	};
}