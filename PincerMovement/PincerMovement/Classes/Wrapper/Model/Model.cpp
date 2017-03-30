#include "Model.h"
#include <GeometricPrimitive.h>
#include <SimpleMath.h>
#include "../Matrix/Matrix.h"
#include "../../GameMain/GameMain.h"

#include "../../../Game.h"

using namespace ShunLib;

//＋ーーーーーーーーーーーーーー＋
//｜機能  :デフォルトコンストラクタ	
//＋ーーーーーーーーーーーーーー＋
Model::Model()
{
	m_device = GameMain::m_deviceResources->GetD3DDevice();

	m_effect = std::make_unique<DirectX::EffectFactory>(m_device);

	m_model = DirectX::Model::CreateFromCMO(m_device,
		L"CMedia\\robot.cmo", *m_effect);
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :ファイル指定コンストラクタ	
//｜引数  :cmoファイルの名前(wchar_t[])
//＋ーーーーーーーーーーーーーー＋
Model::Model(const wchar_t cmo[])
{
	m_device = GameMain::m_deviceResources->GetD3DDevice();
	m_effect = std::make_unique<DirectX::EffectFactory>(m_device);
	m_model = DirectX::Model::CreateFromCMO(m_device,cmo, *m_effect);
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :デストラクタ
//＋ーーーーーーーーーーーーーー＋
Model::~Model()
{
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :モデルの描画
//｜引数  :ワールド行列	(Matrix)
//｜引数  :ビュー行列	(Matrix)
//｜引数  :射影行列		(Matrix)
//｜戻り値:なし(void)	
//＋ーーーーーーーーーーーーーー＋
void Model::Draw(const Matrix& world,
						const Matrix& view,
						const Matrix& proj)
{
	DirectX::SimpleMath::Matrix w = world.GetDirectMatrix();	// ワールド
	DirectX::SimpleMath::Matrix v = view.GetDirectMatrix();		// ビュー
	DirectX::SimpleMath::Matrix p = proj.GetDirectMatrix();		// プロジェクション

	// コンテキスト
	ID3D11DeviceContext* pImmediateContext = GameMain::m_deviceResources->GetD3DDeviceContext();

	// 描画
	m_model->Draw(pImmediateContext, *GameMain::m_state, w, v, p);
}
