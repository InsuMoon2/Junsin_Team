#pragma once

#include "CObj.h"
#include "CTimerMgr.h"

class CMonster02 : public CObj
{
public:
	CMonster02();
	virtual ~CMonster02();

public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

	BOOL Get_DeadState() { return m_bDead; }

private:

	CTimerMgr Mgr1;
	int attackTime1 = 0;

	CTimerMgr Mgr2;
	int attackTime2 = 0;

};

