#include "pch.h"
#include "CObj.h"
#include "CBoss02.h"
#include "AbstractFactory.h"
#include "CBullet.h"
#include "CBossBullet.h"


CBoss02::CBoss02(): m_dwTime(GetTickCount())
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



	Update_Rect();

}

int CBoss02::Update()
{
	if (m_bDead == true)
		return OBJ_DEAD;

	Update_Rect();

	if (m_tInfo.fY <= 150)
	{
		m_tInfo.fY += m_fSpeed;
	}
	m_bHp = true;

	
	m_tBarrel_Pos.X = m_tInfo.fX + (m_iBarrel_Len * cosf(m_fAngle * (PI / 180)));
	m_tBarrel_Pos.Y = m_tInfo.fY + (m_iBarrel_Len * sinf(m_fAngle * (PI / 180)));



	

	if (m_dwTime + 500 < GetTickCount())
	{
		//Attack_Circular();
		Attack_Cos();


		m_dwTime = GetTickCount();
	}


	Key_Input();  

	return 0;
}

void CBoss02::Late_Update()
{
	if (m_iHp <= 0)
	{
		m_bDead = true;
	}



}

void CBoss02::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	Rectangle(hDC, m_tRect.left + 10, m_tRect.top + 10, m_tRect.right - 10, m_tRect.bottom - 10);
	
	// 포신 랜더 (쓸지 말지는 선택 하쇼)
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, NULL);
	LineTo(hDC, m_tBarrel_Pos.X, m_tBarrel_Pos.Y);

	// hp ui 셋팅
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
		m_pBullet->push_back(Create_BossBullet( m_fAngle));

	}

	if (GetAsyncKeyState(VK_RIGHT))
	{

		{
			m_tInfo.fX += m_fSpeed;
		}
	}

	if (GetAsyncKeyState(VK_LEFT))
	{

		{
			m_tInfo.fX -= m_fSpeed;
		}
	}


	if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fY -= m_fSpeed;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fY += m_fSpeed;
	}
}

void CBoss02::Attack_Circular()
{
	float tmp_Angle;

	if (m_tTarget)
	{

		float x = m_tTarget->Get_Info().fX - m_tInfo.fX;
		float y = m_tTarget->Get_Info().fY - m_tInfo.fY;

		tmp_Angle = acos(x / sqrtf(pow(x, 2) + pow(y, 2)));

		// tmp_Angle *= (180 / PI);
		if (y < 0)
			tmp_Angle = 2 * PI - tmp_Angle;

		m_fAngle = tmp_Angle * (180.0 / PI);

		//m_tInfo.FX += (cos(tmp_Angle) * m_fSpeed);
		//m_tInfo.FY += (sin(tmp_Angle) * m_fSpeed);

		m_pBullet->push_back(Create_BossBullet(m_fAngle + 10));
		m_pBullet->push_back(Create_BossBullet(m_fAngle - 10));
		m_pBullet->push_back(Create_BossBullet(m_fAngle + 20));
		m_pBullet->push_back(Create_BossBullet(m_fAngle - 20));
		m_pBullet->push_back(Create_BossBullet(m_fAngle));
	}
}

void CBoss02::Attack_Cos()
{

	m_pBullet->push_back(Create_BossBullet(m_fAngle));

}

