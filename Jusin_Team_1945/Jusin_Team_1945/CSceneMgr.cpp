#include "pch.h"
#include "CSceneMgr.h"

#include "AbstractFactory.h"
#include "CStage01.h"
#include "CStage02.h"
#include "CStage03.h"
#include "CTempStage.h"

CSceneMgr::CSceneMgr() : m_Scene(nullptr), m_SceneType(ESceneType::None)
{

}

CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::Initialize()
{
	
}

void CSceneMgr::Update()
{
	if (m_Scene)
	{
		m_Scene->Update();
	}
}

void CSceneMgr::LateUpdate()
{
	if (m_Scene)
	{
		m_Scene->LateUpdate();
	}
}

void CSceneMgr::Render(HDC hdc)
{
	if (m_Scene)
	{
		m_Scene->Render(hdc);
	}
}

void CSceneMgr::Release()
{
	Safe_Delete(m_Scene);
}

int CSceneMgr::ChangeScene(ESceneType _eSceneType)
{
	if (m_SceneType == _eSceneType)
		return 0;

	CScene* newScene = nullptr;

	switch (_eSceneType)
	{
	case ESceneType::Stage01:
		newScene = new CStage01();
		m_StageNumber = 1;
		break;

	case ESceneType::Stage02:
		newScene = new CStage02();
		m_StageNumber = 2;
		break;

	case ESceneType::Stage03:
		newScene = new CStage03();
		m_StageNumber = 3;
		break;

	case ESceneType::TempStage:
		newScene = new CTempStage();
		m_StageNumber = 3;
		break;
	}

	// 기존 스테이지 할당 해제
	Safe_Delete(m_Scene);

	// 새로운 스타이지 할당
	m_Scene = newScene;
	m_SceneType = _eSceneType;

	newScene->Initialize();

	return m_StageNumber;
}