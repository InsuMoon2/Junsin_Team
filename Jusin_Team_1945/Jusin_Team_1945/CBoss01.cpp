#include "pch.h"
#include "CBoss01.h"
#include "CObj.h"

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

	if (m_tInfo.fX == 300.f)
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

	
}

void CBoss01::Release()
{
}
