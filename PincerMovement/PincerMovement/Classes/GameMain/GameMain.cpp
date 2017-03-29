//************************************************/
//* @file  :GameMain.cpp
//* @brief :ゲーム本体のソース
//* @date  :2017/03/27
//* @author:S.Katou
//************************************************/
#include "GameMain.h"

const int GameMain::MAP_X;
const int GameMain::MAP_Y;
const int GameMain::CHIP_SIZE;
std::shared_ptr<DX::DeviceResources>    GameMain::m_deviceResources;

GameMain::GameMain(std::shared_ptr<DX::DeviceResources>  deviceResources)
{
	m_deviceResources = deviceResources;
}

GameMain::~GameMain()
{

}

void GameMain::Update()
{

}

void GameMain::Render()
{

}
