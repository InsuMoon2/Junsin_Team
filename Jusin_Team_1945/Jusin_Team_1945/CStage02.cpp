#include "pch.h"
#include "CStage02.h"
#include "AbstractFactory.h"
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
	m_ObjList[MONSTER01].push_back(AbstractFactory<CBoss01>::Create(300, 200));
}

void CStage02::Update()
{
	CScene::Update();
}

void CStage02::LateUpdate()
{
	CScene::LateUpdate();
}

void CStage02::Render(HDC hdc)
{
	CScene::Render(hdc);
}

void CStage02::Release()
{
	CScene::Release();
}


