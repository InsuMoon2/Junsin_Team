#include "pch.h"
#include "CItem_Potion.h"

CItem_Potion::CItem_Potion() : m_heal(20)
{

}

CItem_Potion::~CItem_Potion()
{

}

void CItem_Potion::Initialize()
{
	CItem::Initialize();

	m_tInfo.fCX = 30;
	m_tInfo.fCY = 30;

	//m_fSpeed = 2.f;
}

int CItem_Potion::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Update_Rect();

	m_tInfo.fY += m_fSpeed;

}

void CItem_Potion::Late_Update()
{
	CItem::Late_Update();

	if (m_tInfo.fY >= WINCY)
		m_bDead = true;
}

void CItem_Potion::Render(HDC hDC)
{
	CItem::Render(hDC);

	HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	SelectObject(hDC, hOldBrush);
	DeleteObject(hBrush);
}

void CItem_Potion::Release()
{
	CItem::Release();

}

void CItem_Potion::Use_Item(CObj* _pObj)
{
	CItem::Use_Item(_pObj);

	_pObj->Set_Hp(_pObj->Get_Hp() + m_heal);

	if (_pObj->Get_Hp() + m_heal >= 100)
	{
		_pObj->Set_Hp(100);
	}
}
