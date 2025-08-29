#include "pch.h"
#include "Obj.h"

Obj::Obj() : m_fSpeed(0.f), m_eDir(DIR_END), m_bDead(false)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
}

Obj::~Obj()
{
}

void Obj::Update_Rect()
{
	m_tRect.left	= long(m_tInfo.fX - (m_tInfo.fCX / 2.f));
	m_tRect.top		= long(m_tInfo.fY - (m_tInfo.fCY / 2.f));
	m_tRect.right	= long(m_tInfo.fX + (m_tInfo.fCX / 2.f));
	m_tRect.bottom	= long(m_tInfo.fY + (m_tInfo.fCY / 2.f));

}
