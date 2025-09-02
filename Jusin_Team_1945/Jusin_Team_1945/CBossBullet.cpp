#include "pch.h"
#include "Define.h"
#include "CBossBullet.h"
#include "AbstractFactory.h"

CBossBullet::CBossBullet() : m_bulletType(BT_END)
{
	
}

CBossBullet::~CBossBullet()
{
}

void CBossBullet::Initialize()
{

    m_tInfo.fCX = 20.f;
    m_tInfo.fCY = 20.f;
    
    m_fSpeed = 3.f;
    
    m_iAttack = 1;

    m_fAngle = 90;
 
          m_fDistance =0;
          
    __super::Update_Rect();
}



int CBossBullet::Update()
{
	if (m_bDead == true)
		return OBJ_DEAD;

   // {
   //     m_tInfo.fX += (cos(m_fAngle * (PI / 180)) * m_fSpeed)+ m_tBarrel_Pos.X;
   //     m_tInfo.fY += (sin(m_fAngle * (PI / 180)) * m_fSpeed)+ m_tBarrel_Pos.Y;
   // }
   //

	switch (m_bulletType)
	{
	case Cos:
		Attack_Cos();
		break;
	case Circular:
		Attack_Circular();
		break;
	case Guided:
		Attack_Guided();
		break;
	case Around:
		Attack_Around();
		break;
	}


	//Attack_Circular();
  // Attack_Cos();

	__super::Update_Rect();


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
	if (m_bulletType == Guided)
	{


		HBRUSH myBrush = CreateSolidBrush(RGB(200, 150, 0));
		HPEN myPen = CreatePen(PS_SOLID, 1, RGB(200, 150, 0));

		HBRUSH OldBrush = (HBRUSH)SelectObject(hDC, myBrush);
		HPEN OldPen = (HPEN)SelectObject(hDC, myPen);

		Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

		SelectObject(hDC, OldBrush);
		SelectObject(hDC, OldPen);
		DeleteObject(myBrush);
		DeleteObject(myPen);

	}
	else
	{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	}
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
   m_tInfo.fY += m_fSpeed;
}

void CBossBullet::Attack_Guided()
{
	m_fSpeed = 2.f;


	{
		float tmp_Angle;
		if (m_tTarget)
		{

			float x = m_tTarget->Get_Info().fX - m_tInfo.fX;
			float y = m_tTarget->Get_Info().fY - m_tInfo.fY;

			tmp_Angle = acos(x / sqrtf(pow(x, 2) + pow(y, 2)));

			if (y < 0)
				tmp_Angle = 2 * PI - tmp_Angle;

            m_tInfo.fX += cos(tmp_Angle)* m_fSpeed;
            m_tInfo.fY +=m_fSpeed;
        }
    }


}

void CBossBullet::Attack_Around()
{
	
	m_fSpeed = 3;
	m_tInfo.fX += (cos(m_fAngle * (PI / 180)) * m_fSpeed);
	m_tInfo.fY += (sin(m_fAngle * (PI / 180)) * m_fSpeed);
}

