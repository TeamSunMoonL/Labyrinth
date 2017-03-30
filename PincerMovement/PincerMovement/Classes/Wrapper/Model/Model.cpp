#include "Model.h"
#include <GeometricPrimitive.h>
#include <SimpleMath.h>
#include "../Matrix/Matrix.h"
#include "../../GameMain/GameMain.h"

#include "../../../Game.h"

using namespace ShunLib;

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�t�H���g�R���X�g���N�^	
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Model::Model()
{
	m_device = GameMain::m_deviceResources->GetD3DDevice();

	m_effect = std::make_unique<DirectX::EffectFactory>(m_device);

	m_model = DirectX::Model::CreateFromCMO(m_device,
		L"CMedia\\robot.cmo", *m_effect);
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�t�@�C���w��R���X�g���N�^	
//�b����  :cmo�t�@�C���̖��O(wchar_t[])
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Model::Model(const wchar_t cmo[])
{
	m_device = GameMain::m_deviceResources->GetD3DDevice();
	m_effect = std::make_unique<DirectX::EffectFactory>(m_device);
	m_model = DirectX::Model::CreateFromCMO(m_device,cmo, *m_effect);
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
	DirectX::SimpleMath::Matrix w = world.GetDirectMatrix();	// ���[���h
	DirectX::SimpleMath::Matrix v = view.GetDirectMatrix();		// �r���[
	DirectX::SimpleMath::Matrix p = proj.GetDirectMatrix();		// �v���W�F�N�V����

	// �R���e�L�X�g
	ID3D11DeviceContext* pImmediateContext = GameMain::m_deviceResources->GetD3DDeviceContext();

	// �`��
	m_model->Draw(pImmediateContext, *GameMain::m_state, w, v, p);
}
