#include "pch.h"
#include "CStage01.h"
#include "AbstractFactory.h"
#include "CMonster01.h"
#include "CMonster02.h"
#include "CPlayer.h"
#include "CSceneMgr.h"
#include "CCollisionMgr.h"
#include "CTimerMgr.h"

// 몬스터, 잡몹 스테이지

CStage01::CStage01()
{

}

CStage01::~CStage01()
{
    Release();
}

void CStage01::Initialize()
{
    CScene::Initialize();

    m_ObjList[MONSTER01].push_back(AbstractFactory<CMonster01>::Create((float)360, (float)200, 2));
    m_ObjList[MONSTER01].push_back(AbstractFactory<CMonster01>::Create((float)100, (float)200, 1));
    m_ObjList[MONSTER01].push_back(AbstractFactory<CMonster01>::Create((float)620, (float)200, 1));

    //for (auto& monster : m_ObjList[MONSTER01])
    //{
    //    monster->Set_Bullet(&m_ObjList[BULLET]);
    //}

    for (auto iter = m_ObjList[MONSTER01].begin(); iter != m_ObjList[MONSTER01].end(); iter++)
    {
         dynamic_cast<CMonster01*>(*iter)->Set_Bullet(&m_ObjList[BULLET]);
    }
    
}

void CStage01::Update()
{
    CScene::Update();

    CCollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[PLAYER]);
}

void CStage01::LateUpdate()
{
    CScene::LateUpdate();
}

void CStage01::Render(HDC hdc)
{
    CScene::Render(hdc);

    //Rectangle(hdc, 100, 100, 250, 250);
}

void CStage01::Release()
{
    CScene::Release();
}