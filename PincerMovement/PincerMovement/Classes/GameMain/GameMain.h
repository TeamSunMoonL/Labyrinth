//************************************************/
//* @file  :GameMain.h
//* @brief :ゲーム本体のヘッダー
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

	//更新処理
	void Update();

	//描画処理
	void Render();
};