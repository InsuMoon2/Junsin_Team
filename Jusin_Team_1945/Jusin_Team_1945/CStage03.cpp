#include "pch.h"
#include "CStage03.h"
#include "AbstractFactory.h"
#include "CBoss02.h"
#include "CCollisionMgr.h"
#include "CMonster01.h"



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
	dynamic_cast<CBoss02*>(m_ObjList[BOSS].front())->Set_Target(m_ObjList[PLAYER].front());

}

void CStage03::Update()
{
	CScene::Update();

	CCollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[BOSS]);
	CCollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[PLAYER]);
}


void CStage03::LateUpdate()
{
	CScene::LateUpdate();
}

void CStage03::Render(HDC hdc)
{
	CScene::Render(hdc);

	if (!m_ObjList[BOSS].empty())
	{
		TCHAR szBuff[32] = L"";
		swprintf_s(szBuff, L"HP : %d", m_ObjList[BOSS].front()->Get_Hp());
		TextOut(hdc, 50, 200, szBuff, lstrlen(szBuff));
	}

}

void CStage03::Release()
{
	CScene::Release();
}



