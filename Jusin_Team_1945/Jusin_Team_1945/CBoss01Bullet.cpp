#include "pch.h"
#include "Define.h"
#include "CBoss01Bullet.h"
#include "AbstractFactory.h"

CBoss01Bullet::CBoss01Bullet()
{
}

CBoss01Bullet::~CBoss01Bullet()
{

}

void CBoss01Bullet::Initialize()
{

    m_tInfo.fCX = 15.f;
    m_tInfo.fCY = 15.f;

    m_fSpeed = 2.f;

    m_iAttack = 10;

	m_iHp = 10;

    __super::Update_Rect();
}

int CBoss01Bullet::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

    __super::Update_Rect();

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

	case DIR_LD:
		m_tInfo.fX -= m_fSpeed;
		m_tInfo.fY += m_fSpeed;
		break;

	case DIR_RD:
		m_tInfo.fX += m_fSpeed;
		m_tInfo.fY += m_fSpeed;
		break;
	}

    return 0;
}

void CBoss01Bullet::Late_Update()
{
    if (m_tRect.right >= WINCX - 50 || m_tRect.left <= 50
        || m_tRect.top <= 50 || m_tRect.bottom >= WINCY - 50)
    {
        m_bDead = true;
    }

	m_tInfo.fX += m_fSpeed * cosf(m_fAngle * (PI / 180.f));
	m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * (PI / 180.f));

	if (m_iHp <= 0)
	{
		m_bDead = true;
	}
}

void CBoss01Bullet::Render(HDC hDC)
{
    Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBoss01Bullet::Release()
{
}