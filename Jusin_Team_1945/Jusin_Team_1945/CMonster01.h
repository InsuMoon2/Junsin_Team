#pragma once

#include "CObj.h"

class CMonster01:  public CObj
{
public:
	CMonster01();
	virtual ~CMonster01();

public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

private:
	DWORD	m_Time = 0;

};

