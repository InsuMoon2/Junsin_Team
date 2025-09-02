#include "pch.h"
#include "CBullet_Monster02.h"

CBullet_Monster02::CBullet_Monster02()
{
	ZeroMemory(&m_tCenter, sizeof(POINT));
}

CBullet_Monster02::~CBullet_Monster02()
{
	Release();
}

void CBullet_Monster02::Initialize()
{

	__super::Update_Rect();

	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 3.f;
	m_iAttack = 5;

	m_fRotAngle = 0.f;
	m_fRotSpeed = 10.f;
	m_fDistance = 50.f;

	m_bStart = true;


	m_iBarrel_Len = 100;
}

int CBullet_Monster02::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}
		
	__super::Update_Rect();

	

	

	return OBJ_NOEVENT;
}

void CBullet_Monster02::Late_Update()
{

	if (m_tRect.left <= 0 || m_tRect.right >= WINCX || m_tRect.top <= 0 || m_tRect.bottom >= WINCY)
	{
		m_bDead = true;
	}

	if (m_bStart == true)
	{
		m_tCenter.x = m_tInfo.fX;
		m_tCenter.y = m_tInfo.fY;
		m_bStart = false;
	}																							
	
	m_tCenter.x += long(m_fSpeed * cosf(m_fAngle * (PI / 180.f)));
	m_tCenter.y -= long(m_fSpeed * sinf(m_fAngle * (PI / 180.f)));
	
	m_fRotAngle += m_fRotSpeed;
	
	m_tInfo.fX = m_tCenter.x + m_fDistance * cosf(m_fRotAngle * (PI / 180.f));
	m_tInfo.fY = m_tCenter.y - m_fDistance * sinf(m_fRotAngle * (PI / 180.f));

	
}

void CBullet_Monster02::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);


	TCHAR szBuff[32] = L"";
	swprintf_s(szBuff, L" x : %f", m_tInfo.fX);
	TextOut(hDC, 50, 180, szBuff, lstrlen(szBuff));

	
}

void CBullet_Monster02::Release()
{
}

