#pragma once

#include "Define.h"

#include "Bullet.h"
#include "Player.h"

//ggg

class MainGame
{
public:
	MainGame();
	~MainGame();
//gdgd
public:
	void		Initialize();
	void		Update();
	void		Late_Update();
	void		Render();
	void		Release();

private:
	HDC			m_hDC;

	list<Obj*>	m_ObjList[OBJ_END];
	DWORD		m_dwTime;
	int			m_iFPS;
	TCHAR		m_szFPS[16];

	TCHAR		m_szStage[32];
};
