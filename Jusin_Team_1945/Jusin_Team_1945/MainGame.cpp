#include "pch.h"
#include "MainGame.h"
#include "AbstractFactory.h"
#include "Monster.h"
#include "Mouse.h"
#include "CollisionMgr.h"
#include "SceneMgr.h"

MainGame::MainGame() : m_dwTime(GetTickCount()), m_iFPS(0)
{
	ZeroMemory(m_szFPS, sizeof(m_szFPS));
	ZeroMemory(m_szStage, sizeof(m_szStage));
}

MainGame::~MainGame()
{
	Release();
}

void MainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	m_ObjList[PLAYER].push_back(AbstractFactory<Player>::Create());
	dynamic_cast<Player*>(m_ObjList[PLAYER].front())->Set_Bullet(&m_ObjList[BULLET]);

	// 초기 스테이지 설정
	SceneMgr::GetInstance()->Initialize();
	SceneMgr::GetInstance()->ChangeScene(ESceneType::Stage01);

	//ffffffff
}

void MainGame::Update()
{
	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end(); )
		{
			int iResult = (*iter)->Update();

			if (iResult == OBJ_DEAD)
			{
				Safe_Delete<Obj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}

	SceneMgr::GetInstance()->Update();
}

void MainGame::Late_Update()
{
	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
		{
			iter->Late_Update();
		}
	}

	//CollisionMgr::Collision_Rect(m_ObjList[MOUSE], m_ObjList[MONSTER]);
	CollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[MONSTER]);
}

void MainGame::Render()
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
	//Rectangle(m_hDC, 100, 100, WINCX - 100, WINCY - 100);

	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
		{
			iter->Render(m_hDC);
		}
	}

	SceneMgr::GetInstance()->Render(m_hDC);

	int stage = SceneMgr::GetInstance()->Get_Stage();

	swprintf_s(m_szStage, L"Stage : %d", stage);
	TextOut(m_hDC, 50, 50, m_szStage, lstrlen(m_szStage));
}

void MainGame::Release()
{

	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), DeleteObj());
		m_ObjList[i].clear();
	}

	ReleaseDC(g_hWnd, m_hDC);
}
