#include "pch.h"
#include "CStage01.h"
#include "AbstractFactory.h"
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

	m_ObjList[MONSTER].push_back(AbstractFactory<CMonster>::Create(600,200));
}

void CStage01::Update()
{
	CScene::Update();
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

}
