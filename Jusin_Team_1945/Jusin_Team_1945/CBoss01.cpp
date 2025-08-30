#include "pch.h"
#include "CBoss01.h"
#include "CObj.h"

CBoss01::CBoss01()
{
}

CBoss01::~CBoss01()
{
	Release();
}

void CBoss01::Initialize()
{
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 75.f;

	m_fSpeed = 3.f;
}

int CBoss01::Update()
{
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CBoss01::Late_Update()
{

}

void CBoss01::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

}

void CBoss01::Release()
{
}
