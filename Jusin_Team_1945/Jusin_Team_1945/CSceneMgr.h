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

	int Get_Stage() { return m_StageNumber; }

public:
	void Initialize();
	void Update();
	void LateUpdate();
	void Render(HDC hdc);
	void Release();

public:
	int ChangeScene(ESceneType _eSceneType);

private:
	CScene*	   m_Scene;
	ESceneType m_SceneType;

	int		   m_StageNumber = 0;
};

