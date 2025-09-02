#include "pch.h"
#include "CBullet_Monster01.h"

CBullet_Monster01::CBullet_Monster01()
{

}

CBullet_Monster01::~CBullet_Monster01()
{
	Release();
}

void CBullet_Monster01::Initialize()
{

	__super::Update_Rect();

	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;

	m_fSpeed = 5.f;

	m_iAttack = 10;

	__super::Update_Rect();
}

int CBullet_Monster01::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}


	if (m_eDir == DIR_DOWN)

	{
		m_tInfo.fY += m_fSpeed;
	}

	__super::Update_Rect();
	

	return OBJ_NOEVENT;
}

void CBullet_Monster01::Late_Update()
{
	if (0 >= m_tRect.left   || WINCX <= m_tRect.right ||
		0 >= m_tRect.top	|| WINCY <= m_tRect.bottom)
	{
		m_bDead = true;
	}
}

void CBullet_Monster01::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet_Monster01::Release()
{
}
