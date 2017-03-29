//************************************************/
//* @file  :Vec3.cpp
//* @brief :３次元ベクトル用のラップクラス
//* @date  :2017/02/17
//* @author:S.Katou
//************************************************/
#include "Vec3.h"
using namespace ShunLib;

//＋ーーーーーーーーーーーーーー＋
//｜機能  :デフォルトコンストラクタ
//＋ーーーーーーーーーーーーーー＋
Vec3::Vec3()
	:m_x(0)
	,m_y(0)
	,m_z(0)
{

}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :値指定コンストラクタ
//｜引数  :X,Y,Z(float,float,float)
//＋ーーーーーーーーーーーーーー＋
Vec3::Vec3(float x, float y, float z)
	:m_x(x)
	,m_y(y)
	,m_z(z)
{

}

//＋ーーーーーーーーーーーーーー＋
//｜機能  :デストラクタ
//＋ーーーーーーーーーーーーーー＋
Vec3::~Vec3()
{

}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :ベクトルをDirectXの形式で返す
//｜引数  :なし　　(void)
//｜戻り値:ベクトル(DirectX::SimpleMath::Vector3)	
//＋ーーーーーーーーーーーーーー＋
DirectX::SimpleMath::Vector3 ShunLib::Vec3::GetDirectVec3()
{
	DirectX::SimpleMath::Vector3 vec;
	vec.x = m_x;
	vec.y = m_y;
	vec.z = m_z;
	return vec;
}

/*--[以下　演算子のオーバーロード]--*/

Vec3& ShunLib::Vec3::operator=(const Vec3& V)
{
	this->m_x = V.m_x;
	this->m_y = V.m_y;
	this->m_z = V.m_z;

	return *this;
}

Vec3& ShunLib::Vec3::operator=(const DirectX::SimpleMath::Vector3& V)
{
	this->m_x = V.x;
	this->m_y = V.y;
	this->m_z = V.z;

	return *this;
}

Vec3& ShunLib::Vec3::operator+(const Vec3& V)
{
	this->m_x += V.m_x;
	this->m_y += V.m_y;
	this->m_z += V.m_z;
	return *this;
}

Vec3& ShunLib::Vec3::operator-(const Vec3& V)
{
	this->m_x -= V.m_x;
	this->m_y -= V.m_y;
	this->m_z -= V.m_z;
	return *this;
}

Vec3& ShunLib::Vec3::operator*(int num)
{
	this->m_x *= num;
	this->m_y *= num;
	this->m_z *= num;
	return *this;
}
