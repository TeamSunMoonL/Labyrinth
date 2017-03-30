//************************************************/
//* @file  :GameMain.cpp
//* @brief :�Q�[���{�̂̃\�[�X
//* @date  :2017/03/27
//* @author:S.Katou&K.Yamamoto
//************************************************/
#include "GameMain.h"

const int GameMain::MAP_X;
const int GameMain::MAP_Y;
const int GameMain::CHIP_SIZE;

// �ÓI�ϐ��錾
// �f�o�C�X���\�[�X
std::shared_ptr<DX::DeviceResources>    GameMain::m_deviceResources;

// �R�����X�e�[�g
DirectX::CommonStates* GameMain::m_state;

// �X�v���C�g�o�b�`
DirectX::SpriteBatch* GameMain::m_spriteBatch;

// �X�v���C�g�t�H���g
DirectX::SpriteFont* GameMain::m_spriteFont;


GameMain::GameMain(std::shared_ptr<DX::DeviceResources>  deviceResources)
{
	// �f�o�C�X���\�[�X�쐬
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
}

void GameMain::Update()
{

}

void GameMain::Render()
{

}
