#include "pch.h"
#include "CUiMgr.h"
#include "CPlayer.h"
#include "CScene.h"
#include "CSceneMgr.h"
#include "CBoss01.h"
#include "CBoss02.h"
#include <windows.h>

void CUIMgr::Render_HP(HDC hdc, CObj* my)
{
	if (dynamic_cast<CPlayer*>(my))
	{
		RECT 	m_tHpUi = { 50,WINCY-70,WINCX - 50,WINCY-50 };

		Rectangle(hdc, m_tHpUi.left, m_tHpUi.top, m_tHpUi.right, m_tHpUi.bottom);

		HBRUSH myBrush = CreateSolidBrush(RGB(0, 255, 0));
		HPEN myPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));

		HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, myBrush);
		HPEN OldPen = (HPEN)SelectObject(hdc, myPen);

		Rectangle(hdc, m_tHpUi.left, m_tHpUi.top, m_tHpUi.right * my->Get_Hp() / 100, m_tHpUi.bottom);

		SelectObject(hdc, OldBrush);
		SelectObject(hdc, OldPen);
		DeleteObject(myBrush);
		DeleteObject(myPen);

		TCHAR szBuff2[32] = L"";
		swprintf_s(szBuff2, L"플레이어 HP : %d", my->Get_Hp());
		TextOut(hdc, WINCX-200, WINCY-40, szBuff2, lstrlen(szBuff2));

	}
	else if (dynamic_cast<CBoss02*>(my) || dynamic_cast<CBoss01*>(my))
	{
		RECT 	m_tHpUi = { 50,50,WINCX - 50,70 };

		Rectangle(hdc, m_tHpUi.left, m_tHpUi.top, m_tHpUi.right, m_tHpUi.bottom);

		HBRUSH myBrush = CreateSolidBrush(RGB(255, 0, 0));
		HPEN myPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));

		HBRUSH OldBrush = (HBRUSH)SelectObject(hdc, myBrush);
		HPEN OldPen = (HPEN)SelectObject(hdc, myPen);

		Rectangle(hdc, m_tHpUi.left, m_tHpUi.top, m_tHpUi.right * my->Get_Hp() / my->Get_MaxHp(), m_tHpUi.bottom);

		SelectObject(hdc, OldBrush);
		SelectObject(hdc, OldPen);
		DeleteObject(myBrush);
		DeleteObject(myPen);

		TCHAR szBuff2[32] = L"";
		swprintf_s(szBuff2, L" 보스 HP : % d", my->Get_Hp());
		TextOut(hdc, 50, 30, szBuff2, lstrlen(szBuff2));
	}
}

void CUIMgr::Render_Stage(HDC hdc)
{
	// Stage 출력
	{


		HFONT hFont = CreateFont(
			30,                // 글자 높이 (픽셀)
			0,                 // 글자 폭 (0 = 자동)
			0,                 // 회전 각도
			0,                 // 문자 기울기
			FW_BOLD,           // 글자 굵기
			FALSE,             // 이탤릭
			FALSE,             // 밑줄
			FALSE,             // 취소선
			ANSI_CHARSET,      // 문자셋
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_SWISS,
			L"맑은 고딕"       // 폰트 이름
		);

		HFONT hOldFont = (HFONT)SelectObject(hdc, hFont); // 기존 폰트 백업

		TCHAR		m_szStage[32];
		int stage = CSceneMgr::GetInstance()->Get_Stage();
		swprintf_s(m_szStage, L"Stage : %d", stage);
		TextOut(hdc, WINCX *0.5f-50, 10, m_szStage, lstrlen(m_szStage));

		SelectObject(hdc, hOldFont); // 원래 폰트 복원
		DeleteObject(hFont);
	}
}

void CUIMgr::Render_Barrel(HDC hdc, int barrelNum)
{
	float r = 25;

	float X = 50 + r;
	float Y = WINCY - 70 -r - 5;
	RECT rec = { X - r, Y - r, X + r, Y + r };
	Rectangle(hdc, rec.left, rec.top, rec.right, rec.bottom);

	if (barrelNum == 2)
	{
		Rectangle(hdc, rec.left + r - 3 - 5 - 4, rec.top + 3 + 3, rec.right - r - 3 - 5, rec.bottom - r + 6);
		Rectangle(hdc, rec.left + r + 3+5+4, rec.top + 3 +3, rec.right - r + 3+5, rec.bottom - r + 6);

	}
	else if (barrelNum == 3)
	{
		Rectangle(hdc, rec.left + r - 3, rec.top + 3, rec.right - r + 3, rec.bottom - r + 6);

		Rectangle(hdc, rec.left + r - 3 - 5 - 4, rec.top + 3 + 7, rec.right - r - 3 - 5, rec.bottom - r + 6);
		Rectangle(hdc, rec.left + r + 3 + 5 + 4, rec.top + 3 + 7, rec.right - r + 3 + 5, rec.bottom - r + 6);
	}
	else
	{
		Rectangle(hdc, rec.left + r - 3, rec.top + 3, rec.right - r + 3, rec.bottom - r + 6);

	}
	Rectangle(hdc, rec.left+5, rec.top+r +5, rec.right-5, rec.bottom-5);
}

void CUIMgr::Render_GameOver(HDC hdc, int winCX, int winCY, bool over)
{
	
	HFONT hFont = CreateFont(
		80, 0,
		0, 0, FW_BOLD,
		FALSE, FALSE, FALSE,
		HANGEUL_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS,
		L"Consolas"
	);

	HFONT oldFont = (HFONT)SelectObject(hdc, hFont);

	LPCWSTR text = L"";

	if (over == true)
	{
	text = L"[ GAME OVER ]";

	}
	else
	{
	text = L"[ YOU WIN ]";

	}

	SIZE size{};
	GetTextExtentPoint32(hdc, text, lstrlen(text), &size);

	int x = (winCX - size.cx) / 2;
	int y = (winCY - size.cy) / 2;

	SetBkMode(hdc, TRANSPARENT);

	TextOut(hdc, x, y, text, lstrlen(text));

	// 6. 리소스 원복/해제
	SelectObject(hdc, oldFont);
	DeleteObject(hFont);
}


CUIMgr::CUIMgr()
{
}

CUIMgr::~CUIMgr()
{
}

void CUIMgr::Initialize()
{
}

int CUIMgr::Update()
{
	return 0;
}

void CUIMgr::LateUpdate()
{
}

void CUIMgr::Render(HDC hDC)
{
	Render_Stage(hDC);
}

void CUIMgr::Release()
{
}
