//************************************************/
//* @file  :Camera.cpp
//* @brief :カメラのラップクラス
//* @date  :2017/02/22
//* @author:S.Katou
//************************************************/
#include "Camera.h"
#include <d3d11.h>
#include <SimpleMath.h>

using namespace ShunLib;

//＋ーーーーーーーーーーーーーー＋
//｜機能  :デフォルトコンストラクタ
//＋ーーーーーーーーーーーーーー＋
Camera::Camera()
	: m_eye(0.0f,0.0f,1.0f)
	, m_target(0.0f,0.0f,0.0f)
	, m_up(0.0f,1.0f,0.0f)
{
	m_view = DirectX::SimpleMath::Matrix::CreateLookAt(m_eye.GetDirectVec3(), m_target.GetDirectVec3(), m_up.GetDirectVec3());
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :データ指定コンストラクタ
//｜引数  :カメラ位置(Vec3)
//｜引数  :注視点	 (Vec3)
//｜引数  :上方向	 (Vec3)
//＋ーーーーーーーーーーーーーー＋
Camera::Camera(ShunLib::Vec3 eye, ShunLib::Vec3 target, ShunLib::Vec3 up)
	: m_eye(eye)
	, m_target(target)
	, m_up(up)
{
	m_view = DirectX::SimpleMath::Matrix::CreateLookAt(m_eye.GetDirectVec3(), m_target.GetDirectVec3(), m_up.GetDirectVec3());
}

//＋ーーーーーーーーーーーーーー＋
//｜機能  :デストラクタ
//＋ーーーーーーーーーーーーーー＋
Camera::~Camera()
{

}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :ビュー行列を返す
//｜引数  :なし		 (void)
//｜戻り値:ビュー行列(Matrix)	
//＋ーーーーーーーーーーーーーー＋
const Matrix& Camera::GetView() const
{
	return m_view;
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :更新処理
//｜引数  :なし(void)
//｜戻り値:なし(void)	
//＋ーーーーーーーーーーーーーー＋
void Camera::Update()
{
	m_view = DirectX::SimpleMath::Matrix::CreateLookAt(m_eye.GetDirectVec3(), m_target.GetDirectVec3(), m_up.GetDirectVec3());
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :カメラ位置を設定する
//｜引数  :カメラ位置(Vec3)
//｜戻り値:なし		 (void)	
//＋ーーーーーーーーーーーーーー＋
void Camera::SetEyePos(ShunLib::Vec3 eye)
{
	m_eye = eye;
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :注視点を設定する
//｜引数  :注視点(Vec3)
//｜戻り値:なし(void)	
//＋ーーーーーーーーーーーーーー＋
void Camera::SetTarget(ShunLib::Vec3 target)
{
	m_target = target;
}
