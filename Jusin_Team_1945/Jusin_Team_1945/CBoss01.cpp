#include "pch.h"
#include "CBoss01.h"
#include "CObj.h"
#include "CTimerMgr.h"
#include "AbstractFactory.h"

CBoss01::CBoss01()
{
	ZeroMemory(&m_tHpUi, sizeof(m_tHpUi));
}

CBoss01::~CBoss01()
{
	Release();
}

void CBoss01::Initialize()
{
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 75.f;

	m_tHpUi = { 50,50,WINCX - 50,70 };

	m_fSpeed = 3.f;

	m_iHp = 4000;

	m_bHp = true;
}

int CBoss01::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	m_tInfo.fX += m_fSpeed;

	__super::Update_Rect();

	AttackTime = Mgr1.GetCurrentTimeCount(5);
	SkillTime = Mgr2.GetCurrentTimeCount(8);

	if (AttackTime == 5)
	{
		m_pBullet->push_back(Create_MonsterBullet01(DIR_DOWN));

	}

	if (SkillTime == 8)
	{
		m_pBullet->push_back(Create_MonsterBullet01(DIR_DOWN));

	}

	return OBJ_NOEVENT;
}

void CBoss01::Late_Update()
{
	if ( m_tRect.left <= 0 || m_tRect.right >= WINCX )
	{
			m_fSpeed *= -1.f;
	}

	if (m_iHp <= 0)
	{
		m_bDead = true;
	}
} 

void CBoss01::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	if (m_bHp == true)
	{
		Rectangle(hDC, m_tHpUi.left, m_tHpUi.top, m_tHpUi.right, m_tHpUi.bottom);

		HBRUSH myBrush = CreateSolidBrush(RGB(255, 0, 0));
		HPEN myPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));

		HBRUSH OldBrush = (HBRUSH)SelectObject(hDC, myBrush);
		HPEN OldPen = (HPEN)SelectObject(hDC, myPen);

		Rectangle(hDC, m_tHpUi.left, m_tHpUi.top, m_tHpUi.right * m_iHp / 4000, m_tHpUi.bottom);

		SelectObject(hDC, OldBrush);
		SelectObject(hDC, OldPen);
		DeleteObject(myBrush);
		DeleteObject(myPen);

	}

	TCHAR szBuff[32] = L"";
	swprintf_s(szBuff, L"AttackTime : %d", AttackTime);
	TextOut(hDC, 50, 160, szBuff, lstrlen(szBuff));

	TCHAR szBuff2[32] = L"";
	swprintf_s(szBuff2, L"SkillTime : %d", SkillTime);
	TextOut(hDC, 50, 200, szBuff2, lstrlen(szBuff2));
}

void CBoss01::Release()
{
}
