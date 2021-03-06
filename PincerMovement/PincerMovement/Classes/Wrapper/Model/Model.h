//************************************************/
//* @file  :Model.h
//* @brief :モデル用のラップクラス
//* @date  :2017/02/21
//* @author:S.Katou
//************************************************/
#pragma once
#include <d3d11.h>
#include <SimpleMath.h>
#include <Model.h>
#include <Effects.h>
#include "../Vec3/Vec3.h"
#include "../Matrix/Matrix.h"

namespace ShunLib
{
	class Model
	{
	private:

		// デバイス
		ID3D11Device* m_device;

		//モデルデータ
		std::unique_ptr<DirectX::Model> m_model;

		//エフェクトデータ
		std::unique_ptr<DirectX::EffectFactory> m_effect;

	public:
		//デフォルトコンストラクタ　箱
		Model();

		//ファイル指定コンストラクタ
		Model(ID3D11Device* device,const wchar_t cmo[]);

		//デストラクタ
		~Model();


		//描画
		void Draw(const Matrix& world,
				  const Matrix& view,
				  const Matrix& proj);
	};
}