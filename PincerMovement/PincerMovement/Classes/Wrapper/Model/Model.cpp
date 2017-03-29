#include "Model.h"
#include <GeometricPrimitive.h>
#include <SimpleMath.h>
#include "../../../Direct3D.h"
#include "../Matrix/Matrix.h"
#include "../../../DirectXTK.h"

using namespace ShunLib;

//＋ーーーーーーーーーーーーーー＋
//｜機能  :デフォルトコンストラクタ	
//＋ーーーーーーーーーーーーーー＋
Model::Model()
{
	m_effect = std::make_unique<DirectX::EffectFactory>(g_pd3dDevice.Get());
	m_model = DirectX::Model::CreateFromCMO(g_pd3dDevice.Get(),
		L"CMedia\\robot.cmo", *m_effect);
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :ファイル指定コンストラクタ	
//｜引数  :cmoファイルの名前(wchar_t[])
//＋ーーーーーーーーーーーーーー＋
Model::Model(const wchar_t cmo[])
{
	m_effect = std::make_unique<DirectX::EffectFactory>(g_pd3dDevice.Get());
	m_model = DirectX::Model::CreateFromCMO(g_pd3dDevice.Get(),cmo, *m_effect);
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
	DirectX::SimpleMath::Matrix w = world.GetDirectMatrix();
	DirectX::SimpleMath::Matrix v = view.GetDirectMatrix();
	DirectX::SimpleMath::Matrix p = proj.GetDirectMatrix();
	m_model->Draw(g_pImmediateContext.Get(), *g_state, w, v, p);
}
