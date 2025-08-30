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
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;
	//m_tInfo.fX = 300;
	//m_tInfo.fY = 300;
	m_fSpeed = 2.f;

	m_iHp = 100;
}

int CMonster02::Update()
{
	
	__super::Update_Rect();




	return OBJ_NOEVENT;
}

void CMonster02::Late_Update()
{
	


}

void CMonster02::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);


}

void CMonster02::Release()
{

}
