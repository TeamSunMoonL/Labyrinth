//************************************************/
//* @file  :GameMain.h
//* @brief :�Q�[���{�̂̃w�b�_�[
//* @date  :2017/03/27
//* @author:S.Katou&K.Yamamoto
//************************************************/
#pragma once
#include <memory>
#include "../../pch.h"
#include "../../DeviceResources.h"

#include <CommonStates.h>
#include <SpriteFont.h>
#include <SpriteFont.h>

// �e�X�g
#include "../Wrapper/Model/Model.h"
#include "../Wrapper/Matrix/Matrix.h"

class GameMain
{
private:

	// �r���[�s��
	ShunLib::Matrix m_view;

	// �v���W�F�N�V�����s��
	ShunLib::Matrix m_proj;

	// ���f��
	ShunLib::Model* m_model;

public:
	//�}�b�v�T�C�Y
	static const int MAP_X = 25;
	static const int MAP_Y = 16;
	 
	//�}�b�v�`�b�v�T�C�Y
	static const int CHIP_SIZE = 32;

	// �f�o�C�X���\�[�X
	static std::shared_ptr<DX::DeviceResources> m_deviceResources;

	// �R�����X�e�[�g
	static DirectX::CommonStates* m_state;

	// �X�v���C�g�o�b�`
	static DirectX::SpriteBatch* m_spriteBatch;

	// �X�v���C�g�t�H���g
	static DirectX::SpriteFont* m_spriteFont;

public:
	GameMain(std::shared_ptr<DX::DeviceResources> deviceResources);
	~GameMain();

	// ������
	void Initialize();

	//�X�V����
	void Update();

	//�`�揈��
	void Render();
};