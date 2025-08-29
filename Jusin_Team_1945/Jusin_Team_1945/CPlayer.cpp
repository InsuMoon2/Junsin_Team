#include "pch.h"
#include "CPlayer.h"
#include "CBullet.h"
#include "AbstractFactory.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo = { (WINCX >> 1), (WINCY >> 1) + 230, 100.f, 100.f };
	m_fSpeed = 10.f;
}

int CPlayer::Update()
{
	__super::Update_Rect();

	Key_Input();

	return OBJ_NOEVENT;
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
	//GetKeyState();

	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (GetAsyncKeyState(VK_UP))
		{
			m_tInfo.fX += m_fSpeed / sqrtf(2.f);
			m_tInfo.fY -= m_fSpeed / sqrtf(2.f);
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			m_tInfo.fX += m_fSpeed / sqrtf(2.f);
			m_tInfo.fY += m_fSpeed / sqrtf(2.f);
		}
		else
		{
			m_tInfo.fX += m_fSpeed;
		}
	}

	else if (GetAsyncKeyState(VK_LEFT))
	{
		if (GetAsyncKeyState(VK_UP))
		{
			m_tInfo.fX -= m_fSpeed / sqrtf(2.f);
			m_tInfo.fY -= m_fSpeed / sqrtf(2.f);
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			m_tInfo.fX -= m_fSpeed / sqrtf(2.f);
			m_tInfo.fY += m_fSpeed / sqrtf(2.f);
		}
		else
		{
			m_tInfo.fX -= m_fSpeed;
		}
	}

	else if (GetAsyncKeyState(VK_UP))
	{	
		m_tInfo.fY -= m_fSpeed;
	}

	else if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fY += m_fSpeed;
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	{
		m_pBullet->push_back(Create_Bullet(DIR_UP));
	}
}

void CPlayer::Late_Update()
{
}
