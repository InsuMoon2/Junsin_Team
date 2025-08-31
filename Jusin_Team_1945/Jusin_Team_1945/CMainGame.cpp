#include "pch.h"
#include "CMainGame.h"
#include "AbstractFactory.h"
#include "CMonster01.h"
#include "Mouse.h"
#include "CCollisionMgr.h"
#include "CSceneMgr.h"

CMainGame::CMainGame() : m_dwTime(GetTickCount()), m_iFPS(0)
{
	ZeroMemory(m_szFPS, sizeof(m_szFPS));
	ZeroMemory(m_szStage, sizeof(m_szStage));
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	// 시작 스테이지 설정
	CSceneMgr::GetInstance()->Initialize();
	CSceneMgr::GetInstance()->ChangeScene(ESceneType::Stage03);

}

void CMainGame::Update()
{
	// Scene Update
	CSceneMgr::GetInstance()->Update();
}

void CMainGame::Late_Update()
{
	// Scene Late Update
	CSceneMgr::GetInstance()->LateUpdate();
}

void CMainGame::Render()
{
	// FPS 출력
	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
		m_iFPS = 0;

		SetWindowText(g_hWnd, m_szFPS);
		m_dwTime = GetTickCount();
	}

	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	// Scene Render
	CSceneMgr::GetInstance()->Render(m_hDC);

	// Stage 출력
	{
		int stage = CSceneMgr::GetInstance()->Get_Stage();
		swprintf_s(m_szStage, L"Stage : %d", stage);
		TextOut(m_hDC, 50, 50, m_szStage, lstrlen(m_szStage));
	}
	
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);
}
