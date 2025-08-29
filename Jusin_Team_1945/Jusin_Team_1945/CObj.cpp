#include "pch.h"
#include "CObj.h"

#include "AbstractFactory.h"
#include "CBullet.h"

CObj::CObj()
	: m_fSpeed(0.f), m_eDir(DIR_END), m_bDead(false),
	  m_iHp(0), m_iAttack(0), m_iDef(0), m_pBullet(nullptr), m_pOwner(nullptr)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
}

CObj::~CObj()
{

}

CObj* CObj::Create_Bullet(DIRECTION eDir)
{
	CObj* pBullet = AbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY);

	pBullet->Set_Owner(this);
	pBullet->Set_Direction(eDir);

	return pBullet;
}

void CObj::Update_Rect()
{
	m_tRect.left	= long(m_tInfo.fX - (m_tInfo.fCX / 2.f));
	m_tRect.top		= long(m_tInfo.fY - (m_tInfo.fCY / 2.f));
	m_tRect.right	= long(m_tInfo.fX + (m_tInfo.fCX / 2.f));
	m_tRect.bottom	= long(m_tInfo.fY + (m_tInfo.fCY / 2.f));

}
