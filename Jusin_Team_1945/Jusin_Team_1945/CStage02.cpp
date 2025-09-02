#include "pch.h"
#include "CStage02.h"
#include "AbstractFactory.h"
#include "CCollisionMgr.h"
#include "CBoss01.h"
#include "CSceneMgr.h"

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
	dynamic_cast<CBoss01*>(m_ObjList[BOSS].front())->Set_Shield(&m_ObjList[SHIELD]);
}

void CStage02::Update()
{
	CScene::Update();

	if (m_ObjList[BOSS].empty())
	{
		CSceneMgr::GetInstance()->ChangeScene(ESceneType::Stage03);

	}
}

void CStage02::LateUpdate()
{
	CScene::LateUpdate();

	CCollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[BOSS]);
	CCollisionMgr::Collision_Circle(m_ObjList[BULLET], CSceneMgr::GetInstance()->Get_Player());
	CCollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[SHIELD]);
	CCollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[BULLET]);
}

void CStage02::Render(HDC hdc)
{
	CScene::Render(hdc);
	
}

void CStage02::Release()
{
	CScene::Release();
}

