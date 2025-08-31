#include "pch.h"
#include "CBoss01.h"
#include "CObj.h"
#include "CTimerMgr.h"

CBoss01::CBoss01()
{
}

CBoss01::~CBoss01()
{
	Release();
}

void CBoss01::Initialize()
{
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 75.f;

	m_fSpeed = 3.f;

	m_iHp = 100;
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
		m_pBullet->push_back(Create_Bullet(DIR_DOWN));

	}

	if (SkillTime == 8)
	{
		m_pBullet->push_back(Create_Bullet(DIR_DOWN));

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
