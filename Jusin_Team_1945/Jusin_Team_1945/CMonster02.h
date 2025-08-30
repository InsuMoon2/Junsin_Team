#pragma once

#include "CObj.h"

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

private:
	DWORD	m_Time = 0;

};

