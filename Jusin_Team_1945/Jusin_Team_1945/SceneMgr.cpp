#include "pch.h"
#include "SceneMgr.h"
#include "Stage01.h"
#include "Stage02.h"

SceneMgr::SceneMgr()
	: m_Scene(nullptr), m_SceneType(ESceneType::None)
{

}

SceneMgr::~SceneMgr()
{
	Release();
}

void SceneMgr::Initialize()
{
	m_StageNumber = 1;
}

void SceneMgr::Update()
{

}

void SceneMgr::Render(HDC hdc)
{
	
}

void SceneMgr::Release()
{
	Safe_Delete(m_Scene);
}

int SceneMgr::ChangeScene(ESceneType _eSceneType)
{
	if (m_SceneType == _eSceneType)
		return 0;

	Scene* newScene = nullptr;

	switch (_eSceneType)
	{
	case ESceneType::Stage01:
		newScene = new Stage01();
		m_StageNumber = 1;
		break;

	case ESceneType::Stage02:
		newScene = new Stage02();
		m_StageNumber = 2;
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
