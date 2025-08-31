#include "pch.h"
#include "Define.h"
#include "CBossBullet.h"
#include "AbstractFactory.h"

CBossBullet::CBossBullet() : m_bulletType(BT_END), m_dwTime(GetTickCount())
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


	m_fDistance = 0;
	//prev_Degree = 0.f;
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
	Attack_Circular();

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


}

void CBossBullet::Attack_Guided()
{
	m_fSpeed = 1.f;


	{
		float tmp_Angle;
		if (m_tTarget)
		{

			float x = m_tTarget->Get_Info().fX - m_tInfo.fX;
			float y = m_tTarget->Get_Info().fY - m_tInfo.fY;

			tmp_Angle = acos(x / sqrtf(pow(x, 2) + pow(y, 2)));

			if (y < 0)
				tmp_Angle = 2 * PI - tmp_Angle;


			float tmp_Degree = tmp_Angle * (180.f / PI);

			if (m_dwTime + 1000 < GetTickCount())
			{
				//   prev_Degree = tmp_Degree;

				m_dwTime = GetTickCount();
			}

			//         if (tmp_Degree-prev_Degree > 10.f || tmp_Degree- prev_Degree < -10.f)
			//         {
			//
			//
			//
			//             m_tInfo.fX += cos(prev_Degree * (PI/180)) * m_fSpeed;
			//             m_tInfo.fY += sin(prev_Degree * (PI/180)) * m_fSpeed;
			//         }
			//         else
			//         {
			//
			//             m_tInfo.fX += cos(tmp_Angle)*m_fSpeed;
			//             m_tInfo.fY += sin(tmp_Angle)*m_fSpeed;
			//
			//         }
			//     



		}
		else
		{
			m_tInfo.fX += (cos(m_fAngle * (PI / 180)) * m_fSpeed) + m_tBarrel_Pos.X;
			m_tInfo.fY += (sin(m_fAngle * (PI / 180)) * m_fSpeed) + m_tBarrel_Pos.Y;
		}
	}


}

