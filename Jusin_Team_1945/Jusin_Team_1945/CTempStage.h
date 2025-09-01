#pragma once

#include "CScene.h"
#include "CTimerMgr.h"


class CTempStage : public CScene
{
public:
	CTempStage();
	virtual ~CTempStage();

public:
	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;
	void Release() override;

private:
	CTimerMgr Mgr1;
	int attackTime1 = 0;

	CTimerMgr Mgr2;
	int attackTime2 = 0;
};

