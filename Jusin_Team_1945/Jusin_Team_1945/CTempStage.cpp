#include "pch.h"
#include "CTempStage.h"
#include "AbstractFactory.h"
#include "CItem_AddBullet.h"
#include "CObj.h"
#include "CMonster01.h"

#include "CCollisionMgr.h"
#include "CItem_Shield.h"
#include "CSceneMgr.h"
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

	m_ObjList[MONSTER01].push_back(AbstractFactory<CMonster01>::Create(400, 200, 2));
	dynamic_cast<CMonster01*>(m_ObjList[MONSTER01].front())->Set_Bullet(&m_ObjList[BULLET]);


}

void CTempStage::Update()
{
	CScene::Update();

}

void CTempStage::LateUpdate()
{
	CScene::LateUpdate();

	// 공격 충돌 처리
	CCollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[MONSTER01]);
	CCollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[SHIELD]);

	// 플레이어 충돌 처리
	CCollisionMgr::Collision_Circle(m_ObjList[BULLET], CSceneMgr::GetInstance()->Get_Player());
}

void CTempStage::Render(HDC hdc)
{
	CScene::Render(hdc);


}

void CTempStage::Release()
{
	CScene::Release();
}

