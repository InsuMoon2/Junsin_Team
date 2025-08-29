#include "pch.h"
#include "CScene.h"

#include "AbstractFactory.h"
#include "CPlayer.h"
#include "CCollisionMgr.h"
#include "CMonster.h"

CScene::CScene() : m_pPlayer(nullptr)
{

}

CScene::~CScene()
{

}

void CScene::Initialize()
{
	m_ObjList[PLAYER].push_back(AbstractFactory<CPlayer>::Create());
	dynamic_cast<CPlayer*>(m_ObjList[PLAYER].front())->Set_Bullet(&m_ObjList[BULLET]);


}

void CScene::Update()
{
	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end(); )
		{
			int iResult = (*iter)->Update();

			if (iResult == OBJ_DEAD)
			{
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}
}

void CScene::LateUpdate()
{
	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
		{
			iter->Late_Update();
		}
	}

}

void CScene::Render(HDC hdc)
{
	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
		{
			iter->Render(hdc);
		}
	}

	// Bullet Ãâ·Â
	{
		TCHAR szBuff[32] = L"";
		swprintf_s(szBuff, L"Bullets : %d", m_ObjList[BULLET].size());
		TextOut(hdc, 50, 80, szBuff, lstrlen(szBuff));
	}
}

void CScene::Release()
{
	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), DeleteObj());
		m_ObjList[i].clear();
	}
}

void CScene::Set_Player(CObj* obj)
{
	m_pPlayer = dynamic_cast<CPlayer*>(obj);

	if (m_pPlayer == nullptr)
		return;
}

