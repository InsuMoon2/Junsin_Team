#include "pch.h"
#include "CItem_AddBullet.h"

CItem_AddBullet::CItem_AddBullet()
{

}

CItem_AddBullet::~CItem_AddBullet()
{

}

void CItem_AddBullet::Initialize()
{
	CItem::Initialize();

	
}

int CItem_AddBullet::Update()
{
	return CItem::Update();

}

void CItem_AddBullet::Late_Update()
{
	CItem::Late_Update();

	
}

void CItem_AddBullet::Render(HDC hDC)
{
	CItem::Render(hDC);

	HBRUSH hBrush = CreateSolidBrush(RGB(135, 206, 250));
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	SelectObject(hDC, hOldBrush);
	DeleteObject(hBrush);
}

void CItem_AddBullet::Release()
{
	CItem::Release();
}

void CItem_AddBullet::Use_Item(CObj* _pObj)
{
	CItem::Use_Item(_pObj);

	if (_pObj->Get_PosinNumber() < 3)
	{
		_pObj->Set_PosinNumber(_pObj->Get_PosinNumber() + 1);
	}
}
