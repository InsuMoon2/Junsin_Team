#include "pch.h"
#include "CBoss01.h"
#include "CObj.h"
#include "CTimerMgr.h"
#include "AbstractFactory.h"
#include "CShield.h"

CBoss01::CBoss01()
{
	ZeroMemory(&m_tHpUi, sizeof(m_tHpUi));
	ZeroMemory(&m_tBarrel_Pos, sizeof(POS));
}

CBoss01::~CBoss01()
{
	Release();
}

void CBoss01::Initialize()
{
	m_tInfo.fCX = 60.f;
	m_tInfo.fCY = 60.f;

	m_tHpUi = { 50,50,WINCX - 50,70 };

	m_fSpeed = 10.f;

	m_iBarrel_Len = 100.f;
	m_fAngle = 90.f;
	m_fBarrel_Speed = 10.f;

	m_iHp = 300;

	m_bHp = true;
}

int CBoss01::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	m_tInfo.fX += m_fSpeed;

	m_tBarrel_Pos.X = LONG(m_tInfo.fX + (m_iBarrel_Len * cosf(m_fAngle * (PI / 180.f))));
	m_tBarrel_Pos.Y = LONG(m_tInfo.fY + (m_iBarrel_Len * sinf(m_fAngle * (PI / 180.f))));

	__super::Update_Rect();

	AttackTime = Mgr1.GetCurrentTimeCount(1);
	ShieldTime = Mgr2.GetCurrentTimeCount(4);
	SkillTime = Mgr3.GetCurrentTimeCount(4);

	if (AttackTime == 1)
	{
		m_pBullet->push_back(Create_Boss01Bullet(DIR_DOWN));
	
	}

	if (ShieldTime == 2)
	{
		m_pShield->push_back(AbstractFactory<CShield>::Create(this));

		for (auto iter = m_pShield->begin(); iter != m_pShield->end(); iter++)
		{
			(*iter)->Set_Owner(this);
		}
	}

	if (SkillTime <= 3 && SkillTime >= 0)
	{
		m_fAngle += 3.f;
		m_pBullet->push_back(Create_Boss01Bullet(m_fAngle));
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

		Rectangle(hDC, m_tHpUi.left, m_tHpUi.top, m_tHpUi.right * m_iHp / 300, m_tHpUi.bottom);

		SelectObject(hDC, OldBrush);
		SelectObject(hDC, OldPen);
		DeleteObject(myBrush);
		DeleteObject(myPen);

	}

	TCHAR szBuff[32] = L"";
	swprintf_s(szBuff, L"AttackTime : %d", AttackTime);
	TextOut(hDC, 50, 400, szBuff, lstrlen(szBuff));

	TCHAR szBuff2[32] = L"";
	swprintf_s(szBuff2, L"ShieldTime : %d", ShieldTime);
	TextOut(hDC, 50, 450, szBuff2, lstrlen(szBuff2));

	TCHAR szBuff3[32] = L"";
	swprintf_s(szBuff3, L"SkillTime : %d", SkillTime);
	TextOut(hDC, 50, 500, szBuff3, lstrlen(szBuff3));
}

void CBoss01::Release()
{
}