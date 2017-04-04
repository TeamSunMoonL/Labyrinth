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
#include "../AI/AttackAI.h"

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

	delete m_tmpAI;

	delete m_tile;
}

// ������
void GameMain::Initialize()
{
	//�r���[���W�̐ݒ�(�ʒu,�����_,�����)
	float x = MAP_X*CHIP_SIZE / 2.0f;
	float z = MAP_Y*CHIP_SIZE * 1.5f;
	m_view = Matrix::CreateLookAt(Vec3(x,20.0f,z),Vec3(x,0.0f,5.0f),Vec3(0.0f,1.0f,0.0f));

	float windowHeight = static_cast<float>(m_deviceResources->GetOutputSize().bottom);	// ��ʂ̍���
	float windowWidth = static_cast<float>(m_deviceResources->GetOutputSize().right);	// ��ʂ̕�

	// �v���W�F�N�V�����s��ݒ� M_PI_4
	m_proj = Matrix::CreateProj(180.0f/4, windowWidth/windowHeight, 1.0f, 100.0f);

	// ���f���쐬
	m_model = new Model(m_deviceResources->GetD3DDevice(), L"CMedia\\robot.cmo");

	m_map = new Map(0);
	GameManager* manager = GameManager::GetInstance();
	manager->Register(m_map);

	m_tmpAI = new AttackAI(ENEMY);
	m_tmpAI->RandamTarget();
	m_tile = new Tile{ 1,1 };
}

int g_interval = 0;
float g_modelAngle = 0.0f;
float g_modelPosX = 0.0f;
float g_modelPosZ = 0.0f;

void GameMain::Update()
{
	g_interval++;

	if (g_interval >= 5)
	{
		m_tmpAI->Update(*m_tile);

		Tile next= m_tmpAI->GetNext();
	
		//�^�[�Q�b�g�̈ʒu�܂ŗ�����
		//�^�[�Q�b�g�Č���
		if (m_tile->row == next.row
		  &&m_tile->column == next.column)
		{
			m_tmpAI->RandamTarget();
		}
		else
		{
			//�����]��
			if (m_tile->row != next.row)
			{
				g_modelAngle = 90.0f + 90.0f*(m_tile->row - next.row);
				g_modelPosX = 0.0f;
				g_modelPosZ = -(next.row - m_tile->row);
			}

			if(m_tile->column != next.column)
			{
				g_modelAngle = 90.0f*(m_tile->column - next.column);
				g_modelPosX = -(next.column - m_tile->column);
				g_modelPosZ = 0.0f;
			}
			*m_tile = next;
		}

		g_interval = 0;
	}
}

void GameMain::Render()
{

	// ���[���h���W
	Matrix world;

	// �`��J�n
	m_spriteBatch->Begin();


	float x = static_cast<float>(m_tile->column);
	float z = static_cast<float>(m_tile->row);

	Matrix modelAngle = Matrix::CreateRotationY(g_modelAngle);
	Matrix modelPos = modelAngle*Matrix::CreateTranslation(Vec3(x, 0.0f, z));
	
	// ���f���̕`��
	m_model->Draw(modelPos, m_view, m_proj);

	m_tmpAI->DrawDebug(m_view, m_proj);


	wchar_t str[128];
	swprintf(str, 128, L"test");
	m_spriteFont->DrawString(m_spriteBatch, str, DirectX::XMFLOAT2(10.0f, 10.0f));

	//�}�b�v�`��
	Matrix mapPos = Matrix::CreateTranslation(Vec3(0.0f, -1.5f, 0.0f));
	m_map->Draw(mapPos, m_view, m_proj);

	// �`��I���
	m_spriteBatch->End();
}
