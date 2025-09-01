#include "pch.h"
#include "CBullet_Monster02.h"

CBullet_Monster02::CBullet_Monster02()
{
}

CBullet_Monster02::~CBullet_Monster02()
{
	Release();
}

void CBullet_Monster02::Initialize()
{

	__super::Update_Rect();

		m_tInfo.fCX = 10.f;
		m_tInfo.fCY = 10.f;

		m_fSpeed = 5.f;

		m_iAttack = 10;

		m_iBarrel_Len = 200;
}

int CBullet_Monster02::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}
	__super::Update_Rect();

	if (m_eDir == DIR_DOWN)
	{
		m_tInfo.fY += m_fSpeed;
	}

	//m_tInfo.fX = m_pOwner->Get_Info().fX + m_iBarrel_Len * cosf(m_fAngle);
	//m_tInfo.fY = m_pOwner->Get_Info().fY - m_iBarrel_Len * sinf(m_fAngle);
	
	return 0;
}

void CBullet_Monster02::Late_Update()
{

	m_fAngle += m_fSpeed;

	if (m_tRect.left <= 0 || m_tRect.right >= WINCX || m_tRect.top <= 0 || m_tRect.bottom >= WINCY)
	{
		m_bDead = true;
	}
}

void CBullet_Monster02::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet_Monster02::Release()
{
}


