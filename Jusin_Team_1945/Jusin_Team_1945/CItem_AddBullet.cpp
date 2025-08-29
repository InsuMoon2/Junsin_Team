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

	m_tInfo.fCX = 30;
	m_tInfo.fCY = 30;
}

int CItem_AddBullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Update_Rect();



}

void CItem_AddBullet::Late_Update()
{
	CItem::Late_Update();
}

void CItem_AddBullet::Render(HDC hDC)
{
	CItem::Render(hDC);

	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CItem_AddBullet::Release()
{
	CItem::Release();
}

void CItem_AddBullet::Use_Item(CObj* _pObj)
{
	CItem::Use_Item(_pObj);

	// �ӽ÷� ���ǵ� ����
	_pObj->Set_Speed(_pObj->Get_Speed() * 2);
}
