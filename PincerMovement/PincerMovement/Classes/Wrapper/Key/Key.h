//************************************************/
//* @file  :Key.h
//* @brief :キー入力用のラップクラス
//* @date  :2017/02/20
//* @author:S.Katou
//************************************************/
#pragma once

namespace ShunLib
{
	class Key
	{
	public:
		//インスタンス生成　取得
		static Key* GetInstance();

	public:
		bool IsPressedUp();
		bool IsPressedDown();
		bool IsPressedRight();
		bool IsPressedLeft();
		bool IsPressedSpace();

		/*--[使わない者たち]--*/
	private:
		Key() {}
		~Key() {}
	};
}