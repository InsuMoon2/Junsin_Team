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

	GetClientRect(g_hWnd, &m_rect);

	// 더블 버퍼링
	{
		m_hDC_back = CreateCompatibleDC(m_hDC);	
		m_bmpBack = CreateCompatibleBitmap(m_hDC, m_rect.right, m_rect.bottom); 
		HBITMAP prev = (HBITMAP)::SelectObject(m_hDC_back, m_bmpBack);
		DeleteObject(prev);
	}
	
	CSceneMgr::GetInstance()->Initialize();
	CSceneMgr::GetInstance()->ChangeScene(ESceneType::TempStage);

}

void CMainGame::Update()
{
	CSceneMgr::GetInstance()->Update();
}

void CMainGame::Late_Update()
{
	CSceneMgr::GetInstance()->LateUpdate();
}

void CMainGame::Render()
{
	// FPS 추가
	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
		m_iFPS = 0;

		SetWindowText(g_hWnd, m_szFPS);
		m_dwTime = GetTickCount();
	}


	// Scene Render
	CSceneMgr::GetInstance()->Render(m_hDC_back);

	// 기존 Rectangle을 그려서 깜빡임 최소화 한걸 더블 버퍼링으로 바꿈
	{
		//Rectangle(m_hDC, 0, 0, WINCX, WINCY);
		BitBlt(m_hDC, 0, 0, m_rect.right, m_rect.bottom, m_hDC_back, 0, 0, SRCCOPY);
		PatBlt(m_hDC_back, 0, 0, m_rect.right, m_rect.bottom, WHITENESS);
	}
	
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
	ReleaseDC(g_hWnd, m_hDC_back);
}
