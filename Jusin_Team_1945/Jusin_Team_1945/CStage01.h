#pragma once

#include "CScene.h"
#include "Define.h"

class CPlayer;

class CStage01 : public CScene
{
public:
	CStage01();
	virtual ~CStage01();

public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;
	void Release() override;

public:


private:
	//list<CObj*>	m_ObjList[OBJ_END];
};

