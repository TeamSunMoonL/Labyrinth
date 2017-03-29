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
public:
	//マップサイズ
	static const int MAP_X = 25;
	static const int MAP_Y = 16;
	 
	//マップチップサイズ
	static const int CHIP_SIZE = 32;

	// Device resources.
	static std::shared_ptr<DX::DeviceResources>    m_deviceResources;

public:
	GameMain(std::shared_ptr<DX::DeviceResources>  deviceResources);
	~GameMain();

	//更新処理
	void Update();

	//描画処理
	void Render();
};