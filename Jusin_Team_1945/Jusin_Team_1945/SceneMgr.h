#pragma once

#include "Define.h"

class Scene;

class SceneMgr
{
public:
	SceneMgr();
	~SceneMgr();

public:
	static SceneMgr* GetInstance()
	{
		static SceneMgr s_Instance;

		return &s_Instance;
	}

	int Get_Stage() { return m_StageNumber; }

public:
	void Initialize();
	void Update();
	void Render(HDC hdc);
	void Release();

public:
	int ChangeScene(ESceneType _eSceneType);

private:
	Scene*	   m_Scene;
	ESceneType m_SceneType;

	int		   m_StageNumber = 0;
};

