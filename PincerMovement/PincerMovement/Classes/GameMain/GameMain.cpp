//************************************************/
//* @file  :GameMain.cpp
//* @brief :�Q�[���{�̂̃\�[�X
//* @date  :2017/03/27
//* @author:S.Katou&K.Yamamoto
//************************************************/

// �w�b�_�t�@�C���̃C���N���[�h
#define _USE_MATH_DEFINES // for C++  
#include <cmath>  

#include "GameMain.h"
#include "../Wrapper/Vec3/Vec3.h"
#include "../../Game.h"

const int GameMain::MAP_X;
const int GameMain::MAP_Y;
const int GameMain::CHIP_SIZE;

// ���O��Ԏg�p
using namespace ShunLib;


// �ÓI�ϐ��錾
// �f�o�C�X���\�[�X
std::shared_ptr<DX::DeviceResources> GameMain::m_deviceResources;

// �R�����X�e�[�g
DirectX::CommonStates* GameMain::m_state;

// �X�v���C�g�o�b�`
DirectX::SpriteBatch* GameMain::m_spriteBatch;

// �X�v���C�g�t�H���g
DirectX::SpriteFont* GameMain::m_spriteFont;


GameMain::GameMain(std::shared_ptr<DX::DeviceResources> deviceResources)
{
	// ���\�[�X�o�^
	m_deviceResources = deviceResources;

	// �R�����X�e�[�g�쐬
	m_state = new DirectX::CommonStates(m_deviceResources->GetD3DDevice());

	// �X�v���C�g�o�b�`�쐬
	m_spriteBatch = new DirectX::SpriteBatch(m_deviceResources->GetD3DDeviceContext());

	// �X�v���C�g�t�H���g�쐬
	m_spriteFont = new DirectX::SpriteFont(m_deviceResources->GetD3DDevice(), L"Font//myfile.spritefont");

}

GameMain::~GameMain()
{
	// ���I�ϐ��j��
	delete m_state;

	delete m_spriteBatch;

	delete m_spriteFont;

	delete m_map;
}

// ������
void GameMain::Initialize()
{
	//�r���[���W�̐ݒ�(�ʒu,�����_,�����)
	float x = MAP_X*CHIP_SIZE / 2.0f;
	float z = MAP_Y*CHIP_SIZE * 2.0f;
	m_view = Matrix::CreateLookAt(Vec3(x,20.0f,z),Vec3(x,0.0f,5.0f),Vec3(0.0f,1.0f,0.0f));

	float windowHeight = static_cast<float>(m_deviceResources->GetOutputSize().bottom);	// ��ʂ̍���
	float windowWidth = static_cast<float>(m_deviceResources->GetOutputSize().right);	// ��ʂ̕�

	// �v���W�F�N�V�����s��ݒ� M_PI_4
	m_proj = Matrix::CreateProj(180.0f/4, windowWidth/windowHeight, 1.0f, 100.0f);

	// ���f���쐬
	m_model = new Model(m_deviceResources->GetD3DDevice(), L"CMedia\\robot.cmo");

	m_map = new Map(0);
}

void GameMain::Update()
{


}

void GameMain::Render()
{

	// ���[���h���W
	Matrix world;

	// �`��J�n
	m_spriteBatch->Begin();

	// ���f���̕`��
	m_model->Draw(world, m_view, m_proj);

	wchar_t str[128];
	swprintf(str, 128, L"test");
	m_spriteFont->DrawString(m_spriteBatch, str, DirectX::XMFLOAT2(10.0f, 10.0f));

	//�}�b�v�`��
	Matrix mapPos = Matrix::CreateTranslation(Vec3(0.0f, -1.5f, 0.0f));
	m_map->Draw(mapPos, m_view, m_proj);

	// �`��I���
	m_spriteBatch->End();
}
