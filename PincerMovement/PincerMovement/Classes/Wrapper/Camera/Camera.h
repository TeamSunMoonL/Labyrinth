//************************************************/
//* @file  :Camera.h
//* @brief :カメラのラップクラス
//* @date  :2017/02/22
//* @author:S.Katou
//************************************************/
#pragma once
#include "../Matrix/Matrix.h"
#include "../Vec3/Vec3.h"

class Camera
{

private:
	//ビュー行列
	ShunLib::Matrix m_view;		

	//カメラ位置
	ShunLib::Vec3   m_eye;		
	
	//注視点
	ShunLib::Vec3   m_target;	
	
	//上方向
	ShunLib::Vec3   m_up;		

public:
	//デフォルトコンストラクタ
	Camera();

	//データ指定コンストラクタ
	Camera(ShunLib::Vec3 eye, ShunLib::Vec3 target, ShunLib::Vec3 up);
	
	//デストラクタ
	~Camera();

	//ビュー行列を返す
	const ShunLib::Matrix& GetView()const;

	//更新処理
	void Update();

	//カメラ位置を設定する
	void SetEyePos(ShunLib::Vec3 eye);
	
	//注視点を設定する
	void SetTarget(ShunLib::Vec3 target);
};
