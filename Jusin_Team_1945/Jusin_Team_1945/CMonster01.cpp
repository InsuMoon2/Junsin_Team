#include "pch.h"
#include "CMonster01.h"
#include "AbstractFactory.h"
#include "CBullet.h"
#include "CTimerMgr.h"

CMonster01::CMonster01()
{
}

CMonster01::~CMonster01()
{
    Release();
}

void CMonster01::Initialize()
{
    m_tInfo.fCX = 50.f;
    m_tInfo.fCY = 50.f;
    //m_tInfo.fX = 300;
    //m_tInfo.fY = 300;
    m_fSpeed = 2.f;

    m_iHp = 100;
}

int CMonster01::Update()
{
    if (m_bDead)
        return OBJ_DEAD;

    if (m_iID == 1)
    {
        m_tInfo.fY += m_fSpeed;
    }
    else
    {
        m_tInfo.fX += m_fSpeed;
    }

    __super::Update_Rect();

<<<<<<< HEAD
    attackTime1 = Mgr1.GetCurrentTimeCount(1);
    
    if (attackTime1 == 1)
=======

    if (attackTime1 == 2)
>>>>>>> Insu
    {
        m_pBullet->push_back(Create_MonsterBullet01(DIR_DOWN));
        
    }


    return OBJ_NOEVENT;
}

void CMonster01::Late_Update()
{
    if (m_iID == 1)
    {
        if (170 >= m_tRect.top || 550 <= m_tRect.bottom)
        {
            m_fSpeed *= -1.f;
        }
    }
    if (m_iID == 2)
    {
        if (170 >= m_tRect.left || 550 <= m_tRect.right)
        {
            m_fSpeed *= -1.f;
        }
    }

    if (m_iHp <= 0)
    {
        m_bDead = true;

    }


}

void CMonster01::Render(HDC hDC)
{
    Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

    TCHAR szBuff[32] = L"";
    swprintf_s(szBuff, L"Time : %d", attackTime1);
    TextOut(hDC, 50, 120, szBuff, lstrlen(szBuff));

    //TCHAR szBuff2[32] = L"";
    //swprintf_s(szBuff2, L"Time : %d", attackTime2);
    //TextOut(hDC, 50, 140, szBuff2, ls trlen(szBuff2));
}

void CMonster01::Release()
{

}
