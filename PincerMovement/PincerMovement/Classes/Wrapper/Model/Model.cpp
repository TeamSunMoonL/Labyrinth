#include "Model.h"
#include <GeometricPrimitive.h>
#include <SimpleMath.h>
#include "../../../Direct3D.h"
#include "../Matrix/Matrix.h"
#include "../../../DirectXTK.h"

using namespace ShunLib;

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�t�H���g�R���X�g���N�^	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Model::Model()
{
	m_effect = std::make_unique<DirectX::EffectFactory>(g_pd3dDevice.Get());
	m_model = DirectX::Model::CreateFromCMO(g_pd3dDevice.Get(),
		L"CMedia\\robot.cmo", *m_effect);
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�t�@�C���w��R���X�g���N�^	
//�b����  :cmo�t�@�C���̖��O(wchar_t[])
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Model::Model(const wchar_t cmo[])
{
	m_effect = std::make_unique<DirectX::EffectFactory>(g_pd3dDevice.Get());
	m_model = DirectX::Model::CreateFromCMO(g_pd3dDevice.Get(),cmo, *m_effect);
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Model::~Model()
{
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :���f���̕`��
//�b����  :���[���h�s��	(Matrix)
//�b����  :�r���[�s��	(Matrix)
//�b����  :�ˉe�s��		(Matrix)
//�b�߂�l:�Ȃ�(void)	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void Model::Draw(const Matrix& world,
						const Matrix& view,
						const Matrix& proj)
{
	DirectX::SimpleMath::Matrix w = world.GetDirectMatrix();
	DirectX::SimpleMath::Matrix v = view.GetDirectMatrix();
	DirectX::SimpleMath::Matrix p = proj.GetDirectMatrix();
	m_model->Draw(g_pImmediateContext.Get(), *g_state, w, v, p);
}
