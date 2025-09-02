#include "pch.h"
#include "CBoss01.h"
#include "CObj.h"
#include "CTimerMgr.h"
#include "AbstractFactory.h"
#include "CSceneMgr.h"
#include "CShield.h"
#include "CUiMgr.h"

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

	m_iMaxHp = 100;
	m_iHp = m_iMaxHp;

	m_bHp = true;
}

int CBoss01::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}

	if (m_iHp <= 0)
	{
		m_bDead = true;
	}

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


} 

void CBoss01::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	if (m_bHp == true)
	{
		CUIMgr::Get_Instance()->Render_HP(hDC, this);
	}

}

void CBoss01::Release()
{
}