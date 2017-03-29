//************************************************/
//* @file  :Key.h
//* @brief :キー入力用のラップクラス
//* @date  :2017/02/20
//* @author:S.Katou
//************************************************/
#include "Key.h"
#include "../../../DirectXTK.h"

using namespace ShunLib;

//＋ーーーーーーーーーーーーーー＋
//｜機能  :インスタンスの生成　取得
//｜引数  :なし(void)
//｜戻り値:インスタンス(Key*)	
//＋ーーーーーーーーーーーーーー＋
Key* Key::GetInstance()
{
	static Key key;

	return &key;
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :上キーが押されたかどうかの判定
//｜引数  :なし(void)
//｜戻り値:押されたらtrue(bool)	
//＋ーーーーーーーーーーーーーー＋
bool Key::IsPressedUp()
{
	return g_key.Up;
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :下キーが押されたかどうかの判定
//｜引数  :なし(void)
//｜戻り値:押されたらtrue(bool)	
//＋ーーーーーーーーーーーーーー＋
bool Key::IsPressedDown()
{
	return g_key.Down;
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :右キーが押されたかどうかの判定
//｜引数  :なし(void)
//｜戻り値:押されたらtrue(bool)	
//＋ーーーーーーーーーーーーーー＋
bool Key::IsPressedRight()
{
	return g_key.Right;
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :左キーが押されたかどうかの判定
//｜引数  :なし(void)
//｜戻り値:押されたらtrue(bool)	
//＋ーーーーーーーーーーーーーー＋
bool Key::IsPressedLeft()
{
	return g_key.Left;
}

//＋ーーーーーーーーーーーーーー＋
//｜機能  :スペースキーが押されたかどうかの判定
//｜引数  :なし(void)
//｜戻り値:押されたらtrue(bool)	
//＋ーーーーーーーーーーーーーー＋
bool Key::IsPressedSpace()
{
	return g_key.Space;
}
