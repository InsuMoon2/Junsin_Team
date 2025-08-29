#include "pch.h"
#include "CStage03.h"
#include "AbstractFactory.h"
#include "CBoss02.h"
// 보스 스테이지

CStage03::CStage03()
{

}

CStage03::~CStage03()
{
	Release();
}

void CStage03::Initialize()
{
	CScene::Initialize();

	m_ObjList[BOSS].push_back(AbstractFactory<CBoss02>::Create());
	dynamic_cast<CBoss02*>(m_ObjList[BOSS].front())->Set_Bullet(&m_ObjList[BULLET]);
}

void CStage03::Update()
{
	CScene::Update();
}


void CStage03::LateUpdate()
{
	CScene::LateUpdate();
}

void CStage03::Render(HDC hdc)
{
	CScene::Render(hdc);
}

void CStage03::Release()
{
	CScene::Release();
}



