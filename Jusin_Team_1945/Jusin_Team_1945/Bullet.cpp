#include "pch.h"
#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
	Release();
}

void Bullet::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 5.f;
}

int Bullet::Update()
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

	case DIR_LU:
		m_tInfo.fX -= m_fSpeed;
		m_tInfo.fY -= m_fSpeed;
		break;

	case DIR_RU:
		m_tInfo.fX += m_fSpeed;
		m_tInfo.fY -= m_fSpeed;
		break;
	}

	return OBJ_NOEVENT;
}
void Bullet::Late_Update()
{
	if (0 >= m_tRect.left || WINCX <= m_tRect.right ||
		0 >= m_tRect.top || WINCY  <= m_tRect.bottom)
	{
		m_bDead = true;
	}
}


void Bullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void Bullet::Release()
{
}


