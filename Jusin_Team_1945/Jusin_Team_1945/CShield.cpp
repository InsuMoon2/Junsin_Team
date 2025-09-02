#include "pch.h"
#include "CObj.h"
#include "CShield.h"
#include "AbstractFactory.h"

// **Shield** //

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

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CShield::Late_Update()
{
	m_tInfo.fX = m_tTarget->Get_Info().fX + m_fDistance * (cosf(m_fShieldAngle * (PI / 180.f)));
	m_tInfo.fY = m_tTarget->Get_Info().fY - m_fDistance * (sinf(m_fShieldAngle * (PI / 180.f)));

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

// **Shield_Player** //

CShield_Player::CShield_Player()
{
	
}

CShield_Player::~CShield_Player()
{

}

void CShield_Player::Initialize()
{
	CShield::Initialize();

	m_iHp = 30;

	m_fSpeed = 5.f;
	m_fDistance = 150.f;

	__super::Update_Rect();
}

int CShield_Player::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Update_Rect();

	return CShield::Update();
}

void CShield_Player::Late_Update()
{
	CShield::Late_Update();

}

void CShield_Player::Render(HDC hDC)
{
	CShield::Render(hDC);

}

void CShield_Player::Release()
{
	CShield::Release();

}

// **Shield_Erase** //

CShield_Erase::CShield_Erase()
{

}

CShield_Erase::~CShield_Erase()
{

}

void CShield_Erase::Initialize()
{
	CShield::Initialize();

	m_fSpeed = 0.0f;
	m_fDistance = 100.1f;

	__super::Update_Rect();
}

int CShield_Erase::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Update_Rect();

	return CShield::Update();
}

void CShield_Erase::Late_Update()
{
	CShield::Late_Update();
}

void CShield_Erase::Render(HDC hDC)
{
	CShield::Render(hDC);
}

void CShield_Erase::Release()
{
	CShield::Release();
}

// ** Shield Pet ** 

CShield_Pet::CShield_Pet()
{

}

CShield_Pet::~CShield_Pet()
{

}

void CShield_Pet::Initialize()
{
	CShield::Initialize();

	m_fSpeed = 0.0f;
	m_fDistance = -60.1f;
}

int CShield_Pet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Update_Rect();

	m_Pet_Attack = m_Pet_Handle.GetCurrentTimeCount(2);

	if (m_Pet_Attack == 2)
	{
		m_pBullet->push_back(Create_PetBullet(DIRECTION::DIR_UP));
	}


	return CShield::Update();
}

void CShield_Pet::Late_Update()
{
	CShield::Late_Update();
}

void CShield_Pet::Render(HDC hDC)
{
	CShield::Render(hDC);
}

void CShield_Pet::Release()
{
	CShield::Release();
}
