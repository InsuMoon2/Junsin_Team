#include "pch.h"
#include "CSceneMgr.h"

#include "AbstractFactory.h"
#include "CStage01.h"
#include "CStage02.h"
#include "CStage03.h"
#include "CTempStage.h"
#include "CPlayer.h"

CSceneMgr::CSceneMgr()
	: m_Scene(nullptr), m_SceneType(ESceneType::Stage_End), m_pPlayer(nullptr)
{

}

CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::Initialize()
{
	// 플레이어는 Scene과 별개로 한 번만 생성
	if (m_pPlayer == nullptr)
	{
		m_pPlayer = (AbstractFactory<CPlayer>::Create(WINCX >> 1, (WINCY >> 1) + 200));
	}
}

void CSceneMgr::Update()
{
	if (m_Scene)
		m_Scene->Update();

	if (m_pPlayer)
		m_pPlayer->Update();

}

void CSceneMgr::LateUpdate()
{
	if (m_Scene)
		m_Scene->LateUpdate();

	if (m_pPlayer)
		m_pPlayer->Late_Update();
}

void CSceneMgr::Render(HDC hdc)
{
	if (m_Scene)
		m_Scene->Render(hdc);

	if (m_pPlayer)
		m_pPlayer->Render(hdc);
}

void CSceneMgr::Release()
{
	Safe_Delete(m_Scene);
	Safe_Delete(m_pPlayer);
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
		m_StageNumber = 4;
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

void CSceneMgr::Render_StageClear()
{

}

void CSceneMgr::Render_GameOver(HDC hdc, int winCX, int winCY)
{
	HFONT hFont = CreateFont(
		80, 0,               
		0, 0, FW_BOLD,       
		FALSE, FALSE, FALSE,  
		HANGEUL_CHARSET,      
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS,
		L"Consolas"             
	);

	HFONT oldFont = (HFONT)SelectObject(hdc, hFont);

	LPCWSTR text = L"[ GAME OVER ]";

	SIZE size{};
	GetTextExtentPoint32(hdc, text, lstrlen(text), &size);

	int x = (winCX - size.cx) / 2;
	int y = (winCY - size.cy) / 2;

	SetBkMode(hdc, TRANSPARENT);

	TextOut(hdc, x, y, text, lstrlen(text));

	// 6. 리소스 원복/해제
	SelectObject(hdc, oldFont);
	DeleteObject(hFont);
}
