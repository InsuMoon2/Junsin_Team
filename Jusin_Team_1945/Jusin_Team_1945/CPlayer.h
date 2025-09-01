#pragma once

#include "CObj.h"
#include <vector>

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

public:

	// 비행기 그리기
	LONG IRound(float v)
	{
		return (v >= 0.f) ? static_cast<LONG>(v + 0.5f)
			: static_cast<LONG>(v - 0.5f);
	}

	void DrawPlane(HDC hdc, float cx, float cy, float s, COLORREF body = RGB(60, 90, 200),COLORREF wing = RGB(50, 60, 80), COLORREF stroke = RGB(20, 20, 30));


private:
	void		Key_Input();

	vector<POS> m_Barrel_Position;
};

