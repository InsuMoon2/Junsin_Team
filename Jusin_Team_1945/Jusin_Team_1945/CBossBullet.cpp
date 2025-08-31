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

    __super::Update_Rect();


   // {
   //     m_tInfo.fX += (cos(m_fAngle * (PI / 180)) * m_fSpeed)+ m_tBarrel_Pos.X;
   //     m_tInfo.fY += (sin(m_fAngle * (PI / 180)) * m_fSpeed)+ m_tBarrel_Pos.Y;
   // }
   //
    //Attack_Circular();
    Attack_Cos();
    switch (m_eDir)
    {
    case DIR_LEFT:
        m_tInfo.fX -= m_fSpeed;
        break;

    case DIR_RIGHT:
        m_tInfo.fX += m_fSpeed;

        break;

    case DIR_UP:
        m_tInfo.fY -= m_fSpeed;
        break;

    case DIR_DOWN:
        m_tInfo.fY += m_fSpeed;
        break;

    }
    return 0;
}

void CBossBullet::Late_Update()
{

    if (m_tRect.right >= WINCX - 50 || m_tRect.left <= 50
        || m_tRect.top <= 50 || m_tRect.bottom >= WINCY - 50)
    {
        m_bDead = true;
    }



}

void CBossBullet::Render(HDC hDC)
{
    Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBossBullet::Release()
{
}

void CBossBullet::Attack_Circular()
{
         m_tInfo.fX += (cos(m_fAngle * (PI / 180)) * m_fSpeed);
         m_tInfo.fY += (sin(m_fAngle * (PI / 180)) * m_fSpeed);
}

void CBossBullet::Attack_Cos()
{
    {
        // float tmpfX = (cos(m_fAngle * (PI / 180)));
        // float tmpfY = (sin(m_fAngle * (PI / 180)));
        // 
        // m_tInfo.fX += tmpfX * m_fSpeed - tmpfY;
        // m_tInfo.fY += tmpfY * m_fSpeed + tmpfX;
        // 
        
        //+ 10 * cos(10 * m_tInfo.fX);
        // m_tInfo.fX += (cos(m_fAngle * (PI / 180)) * m_fSpeed) + m_tBarrel_Pos.X;
     //   m_tInfo.fY += (sin(m_fAngle * (PI / 180)) * m_fSpeed);
     //   m_tInfo.fX = m_tInfo.fX+  sin( m_tInfo.fY)* 10;


        
    
        float rad = m_fAngle * (PI / 180.0f);

        // �⺻ ����
        float dx = cos(rad) * m_fSpeed;
        float dy = sin(rad) * m_fSpeed;

        // ���� ���� (��: �Ѿ��� �󸶳� �����ߴ���)
        m_fDistance += m_fSpeed;   // �� ������ �ӵ���ŭ ���� ����

        // ���� ���
        float frequency = 0.1f;           // �ĵ� �ֱ�
        float amplitude = 10.0f;          // �¿� ��鸲 ũ��
        float offset = sin(m_fDistance * frequency) * amplitude;

        // ���� �̵�
        m_tInfo.fX += dx + (-sin(rad)) * offset;
        m_tInfo.fY += dy + (cos(rad)) * offset; 
  
    }
}

