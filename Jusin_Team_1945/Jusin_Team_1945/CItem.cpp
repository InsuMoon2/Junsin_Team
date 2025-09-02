#include "pch.h"
#include "CItem.h"

CItem::CItem()
{

}

CItem::~CItem()
{

}

void CItem::Initialize()
{
	m_tInfo.fCX = 30;
	m_tInfo.fCY = 30;

	m_fSpeed = 1.0f + static_cast<float>(rand()) / RAND_MAX * 4.0f;
}

int CItem::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Update_Rect();

	m_tInfo.fY += m_fSpeed;
}

void CItem::Late_Update()
{
	if (m_tInfo.fY >= WINCY)
		m_bDead = true;
}

void CItem::Render(HDC hDC)
{

}

void CItem::Release()
{

}

void CItem::Use_Item(CObj* _pObj)
{

}
