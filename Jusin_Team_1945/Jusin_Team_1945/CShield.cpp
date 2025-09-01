#include "pch.h"
#include "CObj.h"
#include "CShield.h"
#include "AbstractFactory.h"

CShield::CShield()
{
}

CShield::~CShield()
{
	Release();
}

void CShield::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 2.f;
	m_fDistance = 200.f;

	m_iHp = 10;

	__super::Update_Rect();
}

int CShield::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	m_tInfo.fX = m_tTarget->Get_Info().fX + m_fDistance * cosf(m_fShieldAngle * (PI / 180.f));
	m_tInfo.fY = m_tTarget->Get_Info().fY - m_fDistance * sinf(m_fShieldAngle * (PI / 180.f));

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CShield::Late_Update()
{
	m_fShieldAngle += m_fSpeed;

	if (m_iHp <= 0)
	{
		m_bDead = true;
	}
}

void CShield::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

}

void CShield::Release()
{
}
