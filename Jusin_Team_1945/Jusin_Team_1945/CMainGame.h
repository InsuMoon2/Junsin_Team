#pragma once

#include "Define.h"

#include "CBullet.h"
#include "CPlayer.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize();
	void		Update();
	void		Late_Update();
	void		Render();
	void		Release();

private:
	HDC			m_hDC;

	//list<Obj*>	m_ObjList[OBJ_END];
	DWORD		m_dwTime;
	int			m_iFPS;
	TCHAR		m_szFPS[16];

	TCHAR		m_szStage[32];

	// 더블 버퍼링 추가
	RECT	    m_rect		= {};
	HDC			m_hDC_back  = {};
	HBITMAP		m_bmpBack	= {};
};
