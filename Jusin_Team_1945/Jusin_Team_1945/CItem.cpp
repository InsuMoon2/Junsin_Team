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

}

int CItem::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	return OBJ_NOEVENT;

}

void CItem::Late_Update()
{

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
