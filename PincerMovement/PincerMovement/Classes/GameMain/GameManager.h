//************************************************/
//* @file  :gameManager.h
//* @brief :ゲームを管理するクラスのヘッダーファイル
//* @date  :2017/03/29
//* @author:S.Katou
//************************************************/
#pragma once

#include <string>
#include <vector>

class Player;
class Enemy;

class GameManager
{
private:
	// マップ
	std::vector<std::vector<int>> m_map;

	// プレイヤー
	std::vector<Player*> m_player;
	
	// 敵
	std::vector<Enemy*> m_enemy;


public:
	//＋ーーーーーーーーーーーーーー＋
	//｜機能  :インスタンスの生成　取得(シングルトン)
	//｜引数  :なし(void)
	//｜戻り値:インスタンス(GameManager*)	
	//＋ーーーーーーーーーーーーーー＋
	static GameManager* GetInstance()
	{
		static GameManager inst;
		return &inst;
	}

	// マップの更新
	void Update();

	// プレイヤーの登録
	void RegisterPlayer(Player* pPlayer);

	// 敵の作成

private: // 隠蔽

	// コンストラクタ
	GameManager();

	~GameManager();
};

