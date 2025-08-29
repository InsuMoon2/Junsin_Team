#include "pch.h"
#include "Player.h"
#include "Bullet.h"
#include "AbstractFactory.h"

Player::Player() : m_pBullet(nullptr)
{
}

Player::~Player()
{
	Release();
}

void Player::Initialize()
{
	m_tInfo = { WINCX >> 1, WINCY >> 1, 100.f, 100.f };
	m_fSpeed = 10.f;
}

int Player::Update()
{
	__super::Update_Rect();

	Key_Input();

	return OBJ_NOEVENT;
}

void Player::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void Player::Release()
{
}

void Player::Key_Input()
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

	else if (GetAsyncKeyState(VK_SPACE))
	{
		m_pBullet->push_back(Create_Bullet(DIR_UP));
		m_pBullet->push_back(Create_Bullet(DIR_LU));
		m_pBullet->push_back(Create_Bullet(DIR_RU));
	}
}

Obj* Player::Create_Bullet(DIRECTION eDir)
{
	//Obj* pBullet = new Bullet;
	//pBullet->Initialize();

	Obj* pBullet = AbstractFactory<Bullet>::Create(m_tInfo.fX, m_tInfo.fY);

	pBullet->Set_Direction(eDir);

	return pBullet;
}

void Player::Late_Update()
{
}
