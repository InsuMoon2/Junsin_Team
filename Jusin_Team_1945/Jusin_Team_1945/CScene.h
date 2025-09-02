#pragma once

#include "CTimerMgr.h"
#include "Define.h"

class CObj;
class CPlayer;

class CScene
{
public:
	CScene();
	virtual ~CScene();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release();

public:
	void Random_ItemSpawn();

protected:
	list<CObj*>	m_ObjList[OBJ_END];

private:
	ULONGLONG m_lastSpawnMS = 0;   
	ULONGLONG m_spawnInterval = 1500; 

};
