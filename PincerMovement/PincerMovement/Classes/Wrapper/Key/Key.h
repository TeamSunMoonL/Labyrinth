//************************************************/
//* @file  :Key.h
//* @brief :�L�[���͗p�̃��b�v�N���X
//* @date  :2017/02/20
//* @author:S.Katou
//************************************************/
#pragma once

namespace ShunLib
{
	class Key
	{
	public:
		//�C���X�^���X�����@�擾
		static Key* GetInstance();

	public:
		bool IsPressedUp();
		bool IsPressedDown();
		bool IsPressedRight();
		bool IsPressedLeft();
		bool IsPressedSpace();

		/*--[�g��Ȃ��҂���]--*/
	private:
		Key() {}
		~Key() {}
	};
}