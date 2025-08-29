#include "pch.h"
#include "Monster.h"

Monster::Monster()
{
}

Monster::~Monster()
{
	Release();
}

void Monster::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;
	
	m_fSpeed = 3.f;
}

int Monster::Update()
{
	if (m_bDead)
		return OBJ_DEAD;


	m_tInfo.fX += m_fSpeed;

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void Monster::Late_Update()
{
	if (100 >= m_tRect.left || WINCX - 100 <= m_tRect.right)
	{
		m_fSpeed *= -1.f;
	}
}

void Monster::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void Monster::Release()
{
}
