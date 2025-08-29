#include "pch.h"
#include "CStage01.h"
#include "AbstractFactory.h"
#include "CCollisionMgr.h"
#include "CMonster.h"
#include "CPlayer.h"
#include "CSceneMgr.h"

// 몬스터, 잡몹 스테이지

CStage01::CStage01()
{

}

CStage01::~CStage01()
{

}

void CStage01::Initialize()
{
	CScene::Initialize();


}

void CStage01::Update()
{
	CScene::Update();

	
}

void CStage01::LateUpdate()
{
	CScene::LateUpdate();

	CCollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[MONSTER]);
	//CCollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[PLAYER]);
}

void CStage01::Render(HDC hdc)
{
	CScene::Render(hdc);

}

void CStage01::Release()
{

}
