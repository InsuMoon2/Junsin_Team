#include "pch.h"
#include "CStage02.h"
#include "AbstractFactory.h"
#include "CCollisionMgr.h"
#include "CBoss01.h"

// 보스 스테이지

CStage02::CStage02()
{

}	

CStage02::~CStage02()
{

}

void CStage02::Initialize()
{
	CScene::Initialize();

	m_ObjList[BOSS].push_back(AbstractFactory<CBoss01>::Create(300, 200));
	dynamic_cast<CBoss01*>(m_ObjList[BOSS].front())->Set_Bullet(&m_ObjList[BULLET]);
}

void CStage02::Update()
{
	CScene::Update();

}

void CStage02::LateUpdate()
{
	CScene::LateUpdate();

	CCollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[BOSS]);
	CCollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[PLAYER]);
}

void CStage02::Render(HDC hdc)
{
	CScene::Render(hdc);
	
	if (!m_ObjList[BOSS].empty())
	{
		TCHAR szBuff[32] = L"";
		swprintf_s(szBuff, L"BOSS HP : %d", m_ObjList[BOSS].front()->Get_Hp());
		TextOut(hdc, 50, 120, szBuff, lstrlen(szBuff));
	}
}

void CStage02::Release()
{
	CScene::Release();
}