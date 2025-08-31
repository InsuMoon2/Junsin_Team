#include "pch.h"
#include "CMonster02.h"
#include "AbstractFactory.h"
#include "CBullet.h"

CMonster02::CMonster02()
{
}

CMonster02::~CMonster02()
{
	Release();
}

void CMonster02::Initialize()
{
	m_tInfo.fCX = 60.f;
	m_tInfo.fCY = 60.f;
	//m_tInfo.fX = 300;
	//m_tInfo.fY = 300;
	m_fSpeed = 0.7f;

	m_iHp = 100;
}

int CMonster02::Update()
{

	if (m_bDead)
	{
		return OBJ_DEAD;
	}


		m_tInfo.fY += m_fSpeed;
	

	__super::Update_Rect();


	return OBJ_NOEVENT;
}

void CMonster02::Late_Update()
{

	if (m_iHp <= 0)
	{
		m_bDead = true;
	}


}

void CMonster02::Render(HDC hDC)
{

	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	TCHAR szBuff[32] = L"";
	swprintf_s(szBuff, L" HP : %d", m_iHp);
	TextOut(hDC, 50, 200, szBuff, lstrlen(szBuff));


}

void CMonster02::Release()
{

}
