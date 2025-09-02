#pragma once

#include "Define.h"

class CScene;
class CObj;

class CSceneMgr
{
public:
	CSceneMgr();
	~CSceneMgr();

public:
	static CSceneMgr* GetInstance()
	{
		static CSceneMgr s_Instance;

		return &s_Instance;
	}

	int			 Get_Stage()		{ return m_StageNumber; }
	CObj*		 Get_Player()		{ return m_pPlayer; }
	ESceneType	 Get_SceneType()	{ return m_SceneType; }
	CScene*		 Get_Scene()	    { return m_Scene; }

public:
	void Initialize();
	void Update();
	void LateUpdate();
	void Render(HDC hdc);
	void Release();

public:
	int  ChangeScene(ESceneType _eSceneType);

	void Render_StageClear();
	void Render_GameOver(HDC hdc, int winCX, int winCY);

private:
	CScene*	   m_Scene;
	ESceneType m_SceneType;
	int		   m_StageNumber = 0;

	CObj*      m_pPlayer;
};

