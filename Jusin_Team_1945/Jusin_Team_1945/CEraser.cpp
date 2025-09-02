#include "pch.h"
#include "CObj.h"
#include "CEraser.h"

CEraser::CEraser()
{

}

CEraser::~CEraser()
{

}

void CEraser::Initialize()
{
	m_tInfo.fCX = 200.f;
	m_tInfo.fCY = 200.f;

	m_fSpeed = 7.5f;

	m_iAttack = 10;

	m_iHp = 10000;

	m_fDistance = 100.f;

	__super::Update_Rect();
}

int CEraser::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Update_Rect();

	m_tInfo.fCX += 10.0f;
	m_tInfo.fCY += 10.0f;

	return OBJ_NOEVENT;
}

void CEraser::Late_Update()
{
	if (m_tInfo.fCX >= 1500.f)
	{
		m_bDead = true;
	}
}

void CEraser::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CEraser::Release()
{

}

CEraser2::CEraser2()
{
}

CEraser2::~CEraser2()
{
}

void CEraser2::Initialize()
{
	CEraser::Initialize();
}

int CEraser2::Update()
{
	return CEraser::Update();
}

void CEraser2::Late_Update()
{
	CEraser::Late_Update();
}

void CEraser2::Render(HDC hDC)
{
	CEraser::Render(hDC);
}

void CEraser2::Release()
{
	CEraser::Release();
}
