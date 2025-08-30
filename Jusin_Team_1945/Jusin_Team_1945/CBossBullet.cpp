#include "pch.h"
#include "Define.h"
#include "CBossBullet.h"
#include "AbstractFactory.h"




CBossBullet::CBossBullet()
{
}

CBossBullet::~CBossBullet()
{
}

void CBossBullet::Initialize()
{

    m_tInfo.fCX = 30.f;
    m_tInfo.fCY = 30.f;
    
    m_fSpeed = 5.f;
    
    m_iAttack = 10;
    
    __super::Update_Rect();
}



int CBossBullet::Update()
{
    if (m_bDead == true)
        return OBJ_DEAD;



    return 0;
}

void CBossBullet::Late_Update()
{

    if (m_tRect.right >= WINCX - 50 || m_tRect.left <= 50
        || m_tRect.top <= 50 || m_tRect.bottom >= WINCY - 50)
    {
        m_bDead = true;
    }


    {
        m_tInfo.fX += (cos(m_fAngle * (PI / 180)) * m_fSpeed);
        m_tInfo.fY += (sin(m_fAngle * (PI / 180)) * m_fSpeed);
    }
}

void CBossBullet::Render(HDC hDC)
{
    Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBossBullet::Release()
{
}

//CObj* CBossBullet::Create_Bullet(DIRECTION eDir, float angle)
//{
//    CObj* pBullet = AbstractFactory<CBossBullet>::Create(m_tInfo.fX, m_tInfo.fY);
//
//    pBullet->Set_Owner(this);
//
//    if (eDir != DIRECTION::DIR_END)
//        pBullet->Set_Direction(eDir);
//
//    if (angle >= 0.f)
//        pBullet->Set_Angle(angle);
//
//    return pBullet;
//}