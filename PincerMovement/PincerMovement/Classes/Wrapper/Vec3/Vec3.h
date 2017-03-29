//************************************************/
//* @file  :Vec3.h
//* @brief :３次元ベクトル用のラップクラス
//* @date  :2017/02/22
//* @author:S.Katou
//************************************************/
#pragma once
#include <d3d11.h>
#include <SimpleMath.h>

namespace ShunLib
{
	class Vec3
	{
	public:
		float m_x;
		float m_y;
		float m_z;

	public:
		Vec3();
		Vec3(float x, float y, float z);
		~Vec3();

		//ベクトルをDirectXの形式で返す
		DirectX::SimpleMath::Vector3 GetDirectVec3();
	
		/*--[演算子のオーバーロード]--*/
		Vec3& operator=(const Vec3& V);
		Vec3& operator=(const DirectX::SimpleMath::Vector3& V);
		Vec3& operator+(const Vec3& V);
		Vec3& operator-(const Vec3& V);
		Vec3& operator*(int num);

	};
}