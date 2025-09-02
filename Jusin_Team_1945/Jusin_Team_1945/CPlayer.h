#pragma once

#include "CObj.h"
#include <vector>

#include "CTimerMgr.h"

class CPlayer : public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
private:
	void		Key_Input();
	// 비행기 그리기
	LONG IRound(float v)
	{
		return (v >= 0.f) ? static_cast<LONG>(v + 0.5f)
			: static_cast<LONG>(v - 0.5f);
	}

	void DrawPlane(HDC hdc, float cx, float cy, float s, COLORREF body = RGB(60, 90, 200), COLORREF wing = RGB(50, 60, 80), COLORREF stroke = RGB(20, 20, 30));

	bool Left_BoxCheck() { return m_tInfo.fX >= 0 + (m_tInfo.fCX * 0.15f); };
	bool Right_BoxCheck() { return m_tInfo.fX <= WINCX - (m_tInfo.fCX * 0.15f); }
	bool Up_BoxCheck() { return m_tInfo.fY >= 0 + (m_tInfo.fCY * 0.5f); }
	bool Down_BoxCheck() { return m_tInfo.fY <= WINCY - (m_tInfo.fCY * 0.75f); }

	void Player_Dead();

private:
	vector<POS> m_Barrel_Position;

	ULONGLONG	m_LastShotMS = 0.f;
	ULONGLONG	m_intervalMS = 150;

};

