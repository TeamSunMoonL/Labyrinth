//************************************************/
//* @file  :GameMain.h
//* @brief :�Q�[���{�̂̃w�b�_�[
//* @date  :2017/03/27
//* @author:S.Katou
//************************************************/
#pragma once
#include <memory>
#include "../../pch.h"
#include "../../DeviceResources.h"

class GameMain
{
public:
	//�}�b�v�T�C�Y
	static const int MAP_X = 25;
	static const int MAP_Y = 16;
	 
	//�}�b�v�`�b�v�T�C�Y
	static const int CHIP_SIZE = 32;

	// Device resources.
	static std::shared_ptr<DX::DeviceResources>    m_deviceResources;

public:
	GameMain(std::shared_ptr<DX::DeviceResources>  deviceResources);
	~GameMain();

	//�X�V����
	void Update();

	//�`�揈��
	void Render();
};