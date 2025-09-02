#include "pch.h"
#include "CItem_Erase.h"

#include "AbstractFactory.h"
#include "CEraser.h"
#include "CSceneMgr.h"
#include "CShield.h"

CItem_Erase::CItem_Erase()
{

}

CItem_Erase::~CItem_Erase()
{

}

void CItem_Erase::Initialize()
{
	CItem::Initialize();

	//m_fSpeed = 10.f;
}

int CItem_Erase::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Update_Rect();

	m_tInfo.fY += m_fSpeed;


}

void CItem_Erase::Late_Update()
{
	CItem::Late_Update();

}

void CItem_Erase::Render(HDC hDC)
{
	CItem::Render(hDC);

	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	SelectObject(hDC, hOldBrush);
	DeleteObject(hBrush);
}

void CItem_Erase::Release()
{
	CItem::Release();

}

void CItem_Erase::Use_Item(CObj* _pObj)
{
	CItem::Use_Item(_pObj);

	float x = _pObj->Get_Info().fX;
	float y = _pObj->Get_Info().fY;

	CObj* obj = AbstractFactory<CEraser>::Create(_pObj, x, y);

	_pObj->Get_Eraser()->push_back(obj);
}
