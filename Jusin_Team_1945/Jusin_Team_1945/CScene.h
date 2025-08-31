#pragma once

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

protected:
	list<CObj*>	m_ObjList[OBJ_END];
};
