#include "pch.h"
#include "CObj.h"

#include "AbstractFactory.h"
#include "CBullet.h"
#include "CBossBullet.h"
#include "CPlayerBullet.h"
#include "CBoss01Bullet.h"
#include "CBullet_Monster01.h"
#include "CBullet_Monster02.h"

CObj::CObj()
	: m_fSpeed(0.f), m_eDir(DIR_END), m_bDead(false),
	  m_fShieldAngle(0.f), m_fDistance(0.f), m_iHp(0), m_iAttack(0), m_iDef(0), m_pBullet(nullptr), m_pOwner(nullptr), m_iBarrel_Number(1), m_tTarget(nullptr)
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


CObj* CObj::Create_Bullet(float angle)
{
	CObj* bullet = AbstractFactory<CBullet>::Create();

	bullet->Set_Angle(angle);
	bullet->Set_Owner(this);

	bullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);

	return bullet;

}

CObj* CObj::Create_PlayerBullet(DIRECTION eDir)
{
	CObj* pBullet = AbstractFactory<CPlayerBullet>::Create(m_tBarrel_Pos.X, m_tBarrel_Pos.Y);
	
	pBullet->Set_Direction(eDir);
	pBullet->Set_Owner(this);

	return pBullet;
}

void CObj::Create_PlayerBullet(vector<POS>& vPos)
{
	if (!m_pBullet) return;

	for (auto& pos : vPos)
	{
		CObj* pBullet = AbstractFactory<CPlayerBullet>::Create(pos.X, pos.Y);
		pBullet->Set_Direction(DIR_UP);
		pBullet->Set_Owner(this);

		m_pBullet->push_back(pBullet);
	}
}

CObj* CObj::Create_PetBullet(DIRECTION eDir)
{
	CObj* pBullet = AbstractFactory<CPlayerBullet>::Create(m_tInfo.fX, m_tInfo.fY);

	pBullet->Set_Direction(eDir);
	pBullet->Set_Owner(this);

	return pBullet;
}

CObj* CObj::Create_Boss01Bullet(DIRECTION eDir)
{
	CObj* pBullet = AbstractFactory<CBoss01Bullet>::Create(m_tInfo.fX, m_tInfo.fY);

	pBullet->Set_Owner(this);
	pBullet->Set_Direction(eDir);

	return pBullet;
}

CObj* CObj::Create_Boss01Bullet(float angle)
{
	CObj* bullet = AbstractFactory<CBoss01Bullet>::Create(m_tInfo.fX, m_tInfo.fY);

	bullet->Set_Angle(angle);
	bullet->Set_Owner(this);

	return bullet;

}

CObj* CObj::Create_BossBullet(float angle, BT type)
{
	CBossBullet* bullet = AbstractFactory<CBossBullet>::Create(m_tBarrel_Pos.X, m_tBarrel_Pos.Y);

	bullet->Set_Angle(angle);
	bullet->Set_Owner(this);

	bullet->Set_Type(type);
	//bullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);

	return bullet;

}

CObj* CObj::Create_MonsterBullet01(DIRECTION eDir)
{
	CObj* pBullet = AbstractFactory<CBullet_Monster01>::Create(m_tInfo.fX, m_tInfo.fY);

	pBullet->Set_Direction(eDir);
	pBullet->Set_Owner(this);

	return pBullet;
}

CObj* CObj::Create_MonsterBullet02(DIRECTION eDir, float angle)
{
	CObj* pBullet = AbstractFactory<CBullet_Monster02>::Create(m_tInfo.fX, m_tInfo.fY);

	pBullet->Set_Direction(eDir);
	pBullet->Set_Owner(this);
	pBullet->Set_Angle(angle);
	//pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);
	return pBullet;
}

void CObj::Update_Rect()
{

	m_tRect.left	= long(m_tInfo.fX - (m_tInfo.fCX / 2.f));
	m_tRect.top		= long(m_tInfo.fY - (m_tInfo.fCY / 2.f));
	m_tRect.right	= long(m_tInfo.fX + (m_tInfo.fCX / 2.f));
	m_tRect.bottom	= long(m_tInfo.fY + (m_tInfo.fCY / 2.f));

}
