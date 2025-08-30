#include "pch.h"
#include "CTempStage.h"

#include "AbstractFactory.h"
#include "CCollisionMgr.h"
#include "CItem_AddBullet.h"
#include "CMonster01.h"
#include "CTimerMgr.h"

CTempStage::CTempStage()
{

}

CTempStage::~CTempStage()
{

}

void CTempStage::Initialize()
{
	CScene::Initialize();

	m_ObjList[MONSTER01].push_back(AbstractFactory<CMonster01>::Create(600, 200));
	dynamic_cast<CMonster01*>(m_ObjList[MONSTER01].front())->Set_Bullet(&m_ObjList[BULLET]);

	// TODO :: �׽�Ʈ�� Shield -> Item���� ���� ����
	m_ObjList[SHIELD].push_back(AbstractFactory<CItem_AddBullet>::Create(200, 500));

}

void CTempStage::Update()
{
	CScene::Update();

	
}

void CTempStage::LateUpdate()
{
	CScene::LateUpdate();

	// ���� �浹ó��
	CCollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[MONSTER01]);
	CCollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[PLAYER]);

	// ������ �浹 ó��
	CCollisionMgr::Collision_Item(m_ObjList[PLAYER], m_ObjList[SHIELD]);

}

void CTempStage::Render(HDC hdc)
{
	CScene::Render(hdc);

	int time = CTimerMgr::GetCurrentTimeCount(10);

	TCHAR szBuff[32] = L"";
	swprintf_s(szBuff, L"�ð� �� : %d", time);
	TextOut(hdc, 50, 150, szBuff, lstrlen(szBuff));
}

void CTempStage::Release()
{
	CScene::Release();
}
