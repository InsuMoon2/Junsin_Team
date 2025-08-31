#include "pch.h"
#include "CPlayerBullet.h"

CPlayerBullet::CPlayerBullet()
{

}

CPlayerBullet::~CPlayerBullet()
{
	Release();
}

void CPlayerBullet::Initialize()
{
	CBullet::Initialize();

	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;

	m_fSpeed = 7.5f;

	m_iAttack = 10;

	__super::Update_Rect();
}

int CPlayerBullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	switch (m_eDir)
	{
	case DIR_LEFT:
		m_tInfo.fX -= m_fSpeed;
		break;

	case DIR_RIGHT:
		m_tInfo.fX += m_fSpeed;

		break;

	case DIR_UP:
		m_tInfo.fY -= m_fSpeed;
		break;

	case DIR_DOWN:
		m_tInfo.fY += m_fSpeed;
		break;

	case DIR_LU:
		m_tInfo.fX -= m_fSpeed;
		m_tInfo.fY -= m_fSpeed;
		break;

	case DIR_RU:
		m_tInfo.fX += m_fSpeed;
		m_tInfo.fY -= m_fSpeed;
		break;
	}

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayerBullet::Late_Update()
{
	CBullet::Late_Update();

	if (0 >= m_tRect.left || WINCX <= m_tRect.right ||
		0 >= m_tRect.top || WINCY <= m_tRect.bottom)
	{
		m_bDead = true;
	}
}

void CPlayerBullet::Render(HDC hDC)
{
	CBullet::Render(hDC);

	Ellipse(hDC, m_tRect.left + 5, m_tRect.top, m_tRect.right - 5, m_tRect.bottom + 20);
}

void CPlayerBullet::Release()
{
	CBullet::Release();


}
