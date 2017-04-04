//************************************************/
//* @file  :GameManager.h
//* @brief :ゲームを管理するクラスのヘッダーファイル
//* @date  :2017/04/04
//* @author:S.Katou
//************************************************/
#pragma once

#include <string>
#include <vector>

class Player;
class Enemy;
class DefenseTarget;
class Map;

class GameManager
{
private:
	// 属性マップ
	std::vector<std::vector<int>> m_attributeMap;

	// プレイヤー
	std::vector<Player*> m_player;
	
	// 敵
	std::vector<Enemy*> m_enemy;

	//防衛対象
	std::vector<DefenseTarget*>m_target;

	//マップ
	Map* m_map;

public:
	//＋ーーーーーーーーーーーーーー＋
	//｜機能  :インスタンスの生成　取得(シングルトン)
	//｜引数  :なし(void)
	//｜戻り値:インスタンス(GameManager*)	
	//＋ーーーーーーーーーーーーーー＋
	static GameManager* GetInstance()
	{
		static GameManager instance;
		return &instance;
	}

	// 登録
	void Register(Player* player)		 { m_player.push_back(player);}
	void Register(Enemy* enemy)			 { m_enemy.push_back(enemy);  }
	void Register(DefenseTarget* target) { m_target.push_back(target);}
	void Register(Map* map);

	//取得
	std::vector<Player*>& GetTarget()		 { return m_player; }
	std::vector<Enemy*>& GetEnemy()			 { return m_enemy;  }
	std::vector<DefenseTarget*>& GetPlayer() { return m_target; }

	// マップの更新
	void Update();


	//マップの取得
	const std::vector<std::vector<int>>& GetMap() { return m_attributeMap; }

	//初期化処理
	void Reset();



	/*--[以下隠蔽]--*/
private: 

	// コンストラクタ＆デストラクタ
	GameManager();
	~GameManager();
};

