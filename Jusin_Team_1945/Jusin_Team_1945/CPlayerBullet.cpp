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

	m_iAttack = 100;

	__super::Update_Rect();
}

int CPlayerBullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	//m_tInfo.fX += (cos(m_fAngle * (PI / 180)) * m_fSpeed);// + m_tBarrel_Pos.X;
	//m_tInfo.fY += (sin(m_fAngle * (PI / 180)) * m_fSpeed);// + m_tBarrel_Pos.Y;

	m_tInfo.fY -= m_fSpeed;

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

	m_fAngle += m_fSpeed;
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
