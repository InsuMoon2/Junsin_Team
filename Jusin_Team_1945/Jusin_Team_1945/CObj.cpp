#include "pch.h"
#include "CObj.h"

#include "AbstractFactory.h"
#include "CBullet.h"
#include "CBossBullet.h"

CObj::CObj()
	: m_fSpeed(0.f), m_eDir(DIR_END), m_bDead(false),
	  m_iHp(0), m_iAttack(0), m_iDef(0), m_pBullet(nullptr), m_pOwner(nullptr), m_tTarget(nullptr)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
	ZeroMemory(&m_tBarrel_Pos, sizeof(POS));
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


CObj* CObj::Create_Bullet(float angle)
{
	CObj* bullet = AbstractFactory<CBullet>::Create();

	bullet->Set_Angle(angle);
	bullet->Set_Owner(this);

	bullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);

	return bullet;

}

CObj* CObj::Create_BossBullet(float angle)
{
	CObj* bullet = AbstractFactory<CBossBullet>::Create(m_tBarrel_Pos.X, m_tBarrel_Pos.Y);

	//bullet->Set_Pos();

	bullet->Set_Angle(angle);
	bullet->Set_Owner(this);


	return bullet;
}



void CObj::Update_Rect()
{
	m_tRect.left	= long(m_tInfo.fX - (m_tInfo.fCX / 2.f));
	m_tRect.top		= long(m_tInfo.fY - (m_tInfo.fCY / 2.f));
	m_tRect.right	= long(m_tInfo.fX + (m_tInfo.fCX / 2.f));
	m_tRect.bottom	= long(m_tInfo.fY + (m_tInfo.fCY / 2.f));

}
