#include "pch.h"
#include "CItem_Pet.h"

#include "AbstractFactory.h"
#include "CShield.h"

CItem_Pet::CItem_Pet()
{
}

CItem_Pet::~CItem_Pet()
{
}

void CItem_Pet::Initialize()
{
	CItem::Initialize();

	m_fSpeed = 7.f;

	__super::Update_Rect();
}

int CItem_Pet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Update_Rect();

	m_tInfo.fY += m_fSpeed;
}

void CItem_Pet::Late_Update()
{
	CItem::Late_Update();

	__super::Update_Rect();
}

void CItem_Pet::Render(HDC hDC)
{
	CItem::Render(hDC);

	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	SelectObject(hDC, hOldBrush);
	DeleteObject(hBrush);
}

void CItem_Pet::Release()
{
	CItem::Release();
}

void CItem_Pet::Use_Item(CObj* _pObj)
{
	CItem::Use_Item(_pObj);

	if (auto petList = _pObj->Get_Pet())
	{
		auto pet = AbstractFactory<CShield_Pet>::Create(_pObj);
		petList->push_back(pet);
	}
}
