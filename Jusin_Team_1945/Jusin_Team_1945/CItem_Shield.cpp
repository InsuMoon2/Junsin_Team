#include "pch.h"
#include "CItem_Shield.h"

#include "AbstractFactory.h"
#include "CSceneMgr.h"
#include "CShield.h"

CItem_Shield::CItem_Shield()
{

}

CItem_Shield::~CItem_Shield()
{

}

void CItem_Shield::Initialize()
{
	CItem::Initialize();

	
}

int CItem_Shield::Update()
{
	return CItem::Update();
	
	
}

void CItem_Shield::Late_Update()
{
	CItem::Late_Update();

	
}

void CItem_Shield::Render(HDC hDC)
{
	CItem::Render(hDC);

	HBRUSH hBrush = CreateSolidBrush(RGB(100, 0, 0));
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	SelectObject(hDC, hOldBrush);
	DeleteObject(hBrush);
}

void CItem_Shield::Release()
{
	CItem::Release();
}

void CItem_Shield::Use_Item(CObj* _pObj)
{
	CItem::Use_Item(_pObj);

	_pObj->Get_Shield()->push_back(AbstractFactory<CShield_Player>::Create(_pObj));
}
