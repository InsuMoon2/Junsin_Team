#include "pch.h"
#include "CPlayer.h"
#include "CBullet.h"
#include "AbstractFactory.h"
#include <cmath>

#include "CPlayerBullet.h"
#include "CScene.h"
#include "CSceneMgr.h"
#include "CUIMgr.h"

CPlayer::CPlayer()
{

}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo = { (WINCX >> 1), (WINCY >> 1) + 230, 100.f, 100.f };
	m_fSpeed = 10.f;
	m_iHp = 100;

	m_bDead = false;

	m_iBarrel_Len = 70;
	m_Barrel_Position.clear();

	m_LastShotMS = GetTickCount64() - 150;
}

int CPlayer::Update()
{
	if (m_bDead && (GetAsyncKeyState(VK_RETURN) & 0x0001))
	{
		CSceneMgr::GetInstance()->ChangeScene(ESceneType::Stage01);
		Initialize();
	}

	if (m_bDead)
		return OBJ_DEAD;

	m_tBarrel_Pos.X = m_tInfo.fX;
	m_tBarrel_Pos.Y = m_tInfo.fY - m_iBarrel_Len;

	__super::Update_Rect();

	Key_Input();

	float RectSize = m_tRect.right - m_tRect.left;
	float movePosin = 0.f;

	if (m_iBarrel_Number == 1)
	{
		m_Barrel_Position.push_back({ m_tBarrel_Pos });
	}

	else if (m_iBarrel_Number == 2)
	{
		m_Barrel_Position.clear();

		movePosin = RectSize * 0.15f;
		m_Barrel_Position.push_back({ m_tInfo.fX - movePosin, m_tBarrel_Pos.Y });
		m_Barrel_Position.push_back({ m_tInfo.fX + movePosin, m_tBarrel_Pos.Y });
	}

	else if (m_iBarrel_Number == 3)
	{
		m_Barrel_Position.clear();

		movePosin = RectSize * 0.25f;
		m_Barrel_Position.push_back({ m_tInfo.fX - movePosin, m_tBarrel_Pos.Y });
		m_Barrel_Position.push_back({ m_tInfo.fX, m_tBarrel_Pos.Y - 20 });
		m_Barrel_Position.push_back({ m_tInfo.fX + movePosin, m_tBarrel_Pos.Y });
	}

	if (m_iHp <= 0)
		Player_Dead();


	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{

}

void CPlayer::Render(HDC hDC)
{
	float scale = 15.0f;
	DrawPlane(hDC, m_tInfo.fX, m_tInfo.fY, scale);

	//Rectangle(hDC, m_tRect.left + 40, m_tRect.top + 10, m_tRect.right - 40, m_tRect.bottom);

	if (m_bDead == true)
        CUIMgr::Get_Instance()->Render_GameOver(hDC, WINCX, WINCY, true);

    CUIMgr::Get_Instance()->Render_HP(hDC, this);

    if (m_iBarrel_Number == 1)
    {
        MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
        LineTo(hDC, m_tBarrel_Pos.X, m_tBarrel_Pos.Y);
    }

    else if (m_iBarrel_Number == 2)
    {
        movePosin = RectSize * 0.15f;

        MoveToEx(hDC, m_tInfo.fX - movePosin, m_tInfo.fY, nullptr);
        LineTo(hDC, m_tInfo.fX - movePosin, m_tBarrel_Pos.Y);

        MoveToEx(hDC, m_tInfo.fX + movePosin, m_tInfo.fY, nullptr);
        LineTo(hDC, m_tInfo.fX + movePosin, m_tBarrel_Pos.Y);
    }

    else if (m_iBarrel_Number == 3)
    {
        movePosin = RectSize * 0.15f;

        MoveToEx(hDC, m_tInfo.fX - movePosin, m_tInfo.fY, nullptr);
        LineTo(hDC, m_tInfo.fX - movePosin, m_tBarrel_Pos.Y);

        MoveToEx(hDC, m_tInfo.fX + movePosin, m_tInfo.fY, nullptr);
        LineTo(hDC, m_tInfo.fX + movePosin, m_tBarrel_Pos.Y);
    }

}

void CPlayer::Release()
{

}

void CPlayer::DrawPlane(HDC hdc, float cx, float cy, float s, COLORREF body, COLORREF wing, COLORREF stroke)
{
	auto I = [](float v) -> LONG { return static_cast<LONG>(std::lround(v)); };

	HPEN   pen = CreatePen(PS_SOLID, max(1, (int)std::lround(s * 0.15f)), stroke);
	HBRUSH bodyBrush = CreateSolidBrush(body);
	HBRUSH wingBrush = CreateSolidBrush(wing);
	HBRUSH cockpitBrush = CreateSolidBrush(RGB(180, 220, 255));

	HPEN   oldPen = (HPEN)SelectObject(hdc, pen);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, bodyBrush);

	POINT fus[6] = {
		{ I(cx + 0.0f * s),  I(cy - 3.0f * s) }, 
		{ I(cx + 0.6f * s),  I(cy - 1.5f * s) }, 
		{ I(cx + 0.6f * s),  I(cy + 1.8f * s) }, 
		{ I(cx + 0.0f * s),  I(cy + 3.0f * s) }, 
		{ I(cx - 0.6f * s),  I(cy + 1.8f * s) }, 
		{ I(cx - 0.6f * s),  I(cy - 1.5f * s) }, 
	};
	Polygon(hdc, fus, 6);

	SelectObject(hdc, wingBrush);
	POINT wL[3] = {
		{ I(cx - 0.6f * s), I(cy - 0.7f * s) },   
		{ I(cx - 2.0f * s), I(cy + 0.2f * s) },   
		{ I(cx - 0.6f * s), I(cy + 0.6f * s) },   
	};
	POINT wR[3] = {
		{ I(cx + 0.6f * s), I(cy - 0.7f * s) },
		{ I(cx + 2.0f * s), I(cy + 0.2f * s) },
		{ I(cx + 0.6f * s), I(cy + 0.6f * s) },
	};
	Polygon(hdc, wL, 3);
	Polygon(hdc, wR, 3);

	POINT tL[3] = {
		{ I(cx - 0.4f * s), I(cy + 2.0f * s) },
		{ I(cx - 1.2f * s), I(cy + 2.6f * s) },
		{ I(cx - 0.2f * s), I(cy + 2.6f * s) },
	};
	POINT tR[3] = {
		{ I(cx + 0.4f * s), I(cy + 2.0f * s) },
		{ I(cx + 1.2f * s), I(cy + 2.6f * s) },
		{ I(cx + 0.2f * s), I(cy + 2.6f * s) },
	};
	Polygon(hdc, tL, 3);
	Polygon(hdc, tR, 3);

	SelectObject(hdc, cockpitBrush);
	Ellipse(hdc,
		I(cx - 0.35f * s), I(cy - 2.2f * s),
		I(cx + 0.35f * s), I(cy - 1.2f * s));

	SelectObject(hdc, wingBrush);
	int r = max(1, (int)std::lround(s * 0.25f));
	Ellipse(hdc, I(cx - 0.9f * s) - r, I(cy - 0.3f * s) - r,
		I(cx - 0.9f * s) + r, I(cy - 0.3f * s) + r);
	Ellipse(hdc, I(cx + 0.9f * s) - r, I(cy - 0.3f * s) - r,
		I(cx + 0.9f * s) + r, I(cy - 0.3f * s) + r);

	SelectObject(hdc, oldPen);
	SelectObject(hdc, oldBrush);
	DeleteObject(pen);
	DeleteObject(bodyBrush);
	DeleteObject(wingBrush);
	DeleteObject(cockpitBrush);
}

void CPlayer::Player_Dead()
{
	m_iHp = 0;

	Set_Dead();
}

void CPlayer::Key_Input()
{
	if (GetAsyncKeyState(VK_RIGHT) && Right_BoxCheck())
	{
		if (GetAsyncKeyState(VK_UP) && Up_BoxCheck())
		{
			m_tInfo.fX += m_fSpeed / sqrtf(2.f);
			m_tInfo.fY -= m_fSpeed / sqrtf(2.f);
		}
		else if (GetAsyncKeyState(VK_DOWN) && Down_BoxCheck())
		{
			m_tInfo.fX += m_fSpeed / sqrtf(2.f);
			m_tInfo.fY += m_fSpeed / sqrtf(2.f);
		}
		else
		{
			m_tInfo.fX += m_fSpeed;
		}
	}

	else if (GetAsyncKeyState(VK_LEFT) && Left_BoxCheck())
	{
		if (GetAsyncKeyState(VK_UP) && Up_BoxCheck())
		{
			m_tInfo.fX -= m_fSpeed / sqrtf(2.f);
			m_tInfo.fY -= m_fSpeed / sqrtf(2.f);
		}
		else if (GetAsyncKeyState(VK_DOWN) && Down_BoxCheck())
		{
			m_tInfo.fX -= m_fSpeed / sqrtf(2.f);
			m_tInfo.fY += m_fSpeed / sqrtf(2.f);
		}
		else
		{
			m_tInfo.fX -= m_fSpeed;
		}
	}

	else if (GetAsyncKeyState(VK_UP) && Up_BoxCheck())
	{
		m_tInfo.fY -= m_fSpeed;
	}

	else if (GetAsyncKeyState(VK_DOWN) && Down_BoxCheck())
	{
		m_tInfo.fY += m_fSpeed;
	}

	m_intervalMS = 150;
	auto now = GetTickCount64();

	if ((GetAsyncKeyState(VK_SPACE) & 0x8000) &&
		(now - m_LastShotMS) >= m_intervalMS)
	{
		if (m_iBarrel_Number == 1)
		{
			m_pBullet->push_back(Create_PlayerBullet(DIR_UP));
		}

		else if (m_iBarrel_Number == 2)
		{
			Create_PlayerBullet(m_Barrel_Position);
		}

		else if (m_iBarrel_Number == 3)
		{
			Create_PlayerBullet(m_Barrel_Position);
		}

		m_LastShotMS = now;
	}

	if (GetAsyncKeyState('G') & 0x0001)
	{
		auto cur = CSceneMgr::GetInstance()->Get_SceneType();
		int next = (static_cast<int>(cur) + 1) % static_cast<int>(ESceneType::Stage_End);
		CSceneMgr::GetInstance()->ChangeScene(static_cast<ESceneType>(next));
	}
}

