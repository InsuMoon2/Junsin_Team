#include "pch.h"
#include "CMonster02.h"
#include "AbstractFactory.h"
#include "CBullet.h"
#include "CSceneMgr.h"


CMonster02::CMonster02()
{
}

CMonster02::~CMonster02()
{
	Release();
}

void CMonster02::Initialize()
{
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_fSpeed = 0.7f;

	m_iHp = 100;

	m_iBarrel_Len = 100;
}

int CMonster02::Update()
{
	if (m_bDead)
	{
		return OBJ_DEAD;
	}

	m_tInfo.fY += m_fSpeed;

	m_tBarrel_Pos.X = m_tInfo.fX;
	m_tBarrel_Pos.Y = m_tInfo.fY + m_iBarrel_Len;;

	__super::Update_Rect();

   	attackTime1 = Mgr1.GetCurrentTimeCount(2);

	if(attackTime1==2)
	{
		m_pBullet->push_back(Create_MonsterBullet02(-90.f));
	}

	return OBJ_NOEVENT;
 }

void CMonster02::Late_Update()
{
	if (m_iHp <= 0 )
	{
		m_bDead = true;
	}

	if (m_tInfo.fY >= WINCY - (m_tInfo.fCY) * 0.5f)
	{
		CSceneMgr::GetInstance()->Get_Player()->Set_Dead();
	}



}

void CMonster02::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	//MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, NULL);
	//LineTo(hDC, m_tBarrel_Pos.X, m_tBarrel_Pos.Y);

	//TCHAR szBuff[32] = L"";
	//swprintf_s(szBuff, L" HP : %d", m_iHp);
	//TextOut(hDC, 50, 200, szBuff, lstrlen(szBuff));
}



void CMonster02::Release()
{

}
