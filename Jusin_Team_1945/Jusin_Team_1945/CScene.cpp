#include "pch.h"
#include "CScene.h"
#include "AbstractFactory.h"
#include "CPlayer.h"
#include "CCollisionMgr.h"
#include "CItem_AddBullet.h"
#include "CItem_Erase.h"
#include "CItem_Potion.h"
#include "CItem_Shield.h"
#include "CSceneMgr.h"

CScene::CScene() : m_lastSpawnMS(GetTickCount64())
{

}

CScene::~CScene()
{

}

void CScene::Initialize()
{
	// 총알(하늘색), 실드(갈색), 포션(빨간색), 지우개(검은색)

	// 초기 세팅
	if (auto* obj = CSceneMgr::GetInstance()->Get_Player())
	{
		obj->Set_Bullet(&m_ObjList[BULLET]);
		obj->Set_Shield(&m_ObjList[SHIELD], obj);
		obj->Set_Eraser(&m_ObjList[ERASER]);
	}
	
}

void CScene::Update()
{
	ULONGLONG current = GetTickCount64();

	// 2초 지났으면 실행
	if (current - m_lastSpawnMS >= m_spawnInterval)
	{
		Random_ItemSpawn();        
		m_lastSpawnMS = current;       
	}

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

	// 아이템 충돌 처리
	CCollisionMgr::Collision_Item(CSceneMgr::GetInstance()->Get_Player(), m_ObjList[ITEM]);
	CCollisionMgr::Collision_Item(CSceneMgr::GetInstance()->Get_Player(), m_ObjList[SHIELD]);
	CCollisionMgr::Collision_Item(CSceneMgr::GetInstance()->Get_Player(), m_ObjList[POTION]);
	//CCollisionMgr::Collision_Item(CSceneMgr::GetInstance()->Get_Player(), m_ObjList[PET]);

	CCollisionMgr::Collision_Item(CSceneMgr::GetInstance()->Get_Player(), m_ObjList[ERASER]);
	CCollisionMgr::Collision_Circle(m_ObjList[BULLET], m_ObjList[ERASER]);
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
}

void CScene::Release()
{
	for (UINT i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), DeleteObj());
		m_ObjList[i].clear();
	}
}

void CScene::Random_ItemSpawn()
{
	int random = rand() % 4;

	float randomX = 30 + static_cast<float>(rand()) / RAND_MAX * (WINCX - 30);
	
	switch (random)
	{
	case 0:
		m_ObjList[ITEM].push_back(AbstractFactory<CItem_AddBullet>::Create(randomX, 10));
		break;

	case 1:
		m_ObjList[SHIELD].push_back(AbstractFactory<CItem_Shield>::Create(randomX, 10));
		break;

	case 2:
		m_ObjList[POTION].push_back(AbstractFactory<CItem_Potion>::Create(randomX, 10));
		break;

	case 3:
		m_ObjList[ERASER].push_back(AbstractFactory<CItem_Erase>::Create(randomX, 0));
		break;
	}

}


