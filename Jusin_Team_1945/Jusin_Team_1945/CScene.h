#pragma once

#include "Define.h"

class CObj;

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
	void Set_Player(CObj* obj);

protected:
	CObj* m_pPlayer;

	list<CObj*>	m_ObjList[OBJ_END];
};
