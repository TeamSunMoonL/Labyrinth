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
	// Device resources.
	std::unique_ptr<DX::DeviceResources>    m_deviceResources;

public:
	GameMain(DX::DeviceResources* deviceResources);
	~GameMain();

	//�X�V����
	void Update();

	//�`�揈��
	void Render();
};