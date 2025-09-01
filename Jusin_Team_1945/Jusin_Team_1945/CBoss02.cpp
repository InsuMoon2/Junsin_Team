#include "pch.h"
#include "CObj.h"
#include "CBoss02.h"
#include "AbstractFactory.h"
#include "CBullet.h"
#include "CBossBullet.h"


CBoss02::CBoss02(): m_dwTime(GetTickCount()), m_fBarrel_Speed(0), m_bHp(false), m_dwTime01(GetTickCount())
{
	ZeroMemory(&m_tHpUi, sizeof(m_tHpUi));
}

CBoss02::~CBoss02()
{
	Release();
}

void CBoss02::Initialize()
{
	m_tInfo = { WINCX / 2, -10, 100, 100 };
	m_fSpeed = 7.f;

	m_iHp = 100;

	m_tHpUi = { 50,50,WINCX - 50,70 };

	m_iBarrel_Len = 100;

	m_fAngle = 90.f;
	m_fBarrel_Speed = 10.f;


	__super::Update_Rect();

}

int CBoss02::Update()
{
	if (m_bDead == true)
		return OBJ_DEAD;

	
	if (m_tInfo.fY <= 150)
	{
		m_tInfo.fY += m_fSpeed;
	}
	else if (m_tInfo.fY >= 150)
		m_bHp = true;

	
	m_tBarrel_Pos.X = m_tInfo.fX + (m_iBarrel_Len * cosf(m_fAngle * (PI / 180)));
	m_tBarrel_Pos.Y = m_tInfo.fY + (m_iBarrel_Len * sinf(m_fAngle * (PI / 180)));



	if (m_bHp == true)
	{

	
		attackTime1 = Mgr1.GetCurrentTimeCount(2);

		m_tInfo.fX -= m_fSpeed;

		if (attackTime1 == 2 && bCheck)
		{
			Attack_Guided();
	

	
	
	
	
			bCheck = false;
		}
	

	}


	
	if (m_dwTime + 1000 < GetTickCount())
	{

		if (m_iHp <= 50)
		{
			Attack_Guided();
		}
		else
		{
			Attack_Circular();

		}
			m_dwTime = GetTickCount();
	}

	if (m_dwTime01 + 5000 < GetTickCount())
	{

		if (m_iHp <= 50)
		{
			Attack_Cos();
		}
		m_dwTime = GetTickCount();
	}


	__super::Update_Rect();
	Key_Input();  

	return 0;
}

void CBoss02::Late_Update()
{
	if (m_iHp <= 0)
	{
		m_bDead = true;
	}

	if (m_tRect.left <= 0 || m_tRect.right >= WINCX)
	{
		m_fSpeed *= -1;
	}

}

void CBoss02::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	Rectangle(hDC, m_tRect.left + 10, m_tRect.top + 10, m_tRect.right - 10, m_tRect.bottom - 10);
	
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, NULL);
	LineTo(hDC, m_tBarrel_Pos.X, m_tBarrel_Pos.Y);

	// hp ui
	{
		if (m_bHp == true)
		{
			Rectangle(hDC, m_tHpUi.left, m_tHpUi.top, m_tHpUi.right, m_tHpUi.bottom);

			HBRUSH myBrush = CreateSolidBrush(RGB(255, 0, 0));
			HPEN myPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));

			HBRUSH OldBrush = (HBRUSH)SelectObject(hDC, myBrush);
			HPEN OldPen = (HPEN)SelectObject(hDC, myPen);

			Rectangle(hDC, m_tHpUi.left, m_tHpUi.top, m_tHpUi.right * m_iHp / 100, m_tHpUi.bottom);

			SelectObject(hDC, OldBrush);
			SelectObject(hDC, OldPen);
			DeleteObject(myBrush);
			DeleteObject(myPen);

		}
	}
}

void CBoss02::Release()
{

}



void CBoss02::Key_Input()
{
	if (GetAsyncKeyState('8'))
	{
		Attack_Guided();

	}

	//if (GetAsyncKeyState(VK_RIGHT))
	//{
	//
	//	{
	//		m_tInfo.fX += m_fSpeed;
	//	}
	//}
	//
	//if (GetAsyncKeyState(VK_LEFT))
	//{
	//
	//	{
	//		m_tInfo.fX -= m_fSpeed;
	//	}
	//}
	//
	//
	//if (GetAsyncKeyState(VK_UP))
	//{
	//	m_tInfo.fY -= m_fSpeed;
	//}
	//
	//if (GetAsyncKeyState(VK_DOWN))
	//{
	//	m_tInfo.fY += m_fSpeed;
	//}
}

void CBoss02::Attack_Circular()
{
	float tmp_Angle ;

	if (m_tTarget)
	{

		float x = m_tTarget->Get_Info().fX - m_tInfo.fX;
		float y = m_tTarget->Get_Info().fY - m_tInfo.fY;

		tmp_Angle = acos(x / sqrtf(pow(x, 2) + pow(y, 2)));

		if (y < 0)
			tmp_Angle = 2 * PI - tmp_Angle;

		m_fAngle = tmp_Angle * (180.0 / PI);

		for (int i = -20; i < 21; i += 10)
		{
		CObj* tmp1 = Create_BossBullet(m_fAngle +i , Circular);
		tmp1->Set_Pos(m_tBarrel_Pos.X-i, m_tBarrel_Pos.Y);
		m_pBullet->push_back(tmp1);


		}
	}
}

void CBoss02::Attack_Cos()
{

	m_iBarrel_Len = 200;

	m_fAngle += m_fBarrel_Speed;
	if (m_fAngle >= 135 || m_fAngle <= 45)
	{
		m_fBarrel_Speed *= -1;
	}
	
	
	m_pBullet->push_back(Create_BossBullet(m_fAngle, Cos));

}

void CBoss02::Attack_Guided()
{
	CObj* bullet = Create_BossBullet(m_fAngle, Guided);
	if (m_tTarget)
	{
		bullet->Set_Target(this->m_tTarget);
	}
	m_pBullet->push_back(bullet);

}

