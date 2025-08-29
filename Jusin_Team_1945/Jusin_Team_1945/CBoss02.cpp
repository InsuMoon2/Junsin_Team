#include "pch.h"
#include "CObj.h"
#include "CBoss02.h"
#include "AbstractFactory.h"
#include "CBullet.h"

CBoss02::CBoss02()
{

}

CBoss02::~CBoss02()
{
    Release();
}

void CBoss02::Initialize()
{
    m_tInfo = { WINCX / 2,WINCY / 2, 50, 50 };
    m_fSpeed = 10.f;

    m_iHp = 100;
    
}

int CBoss02::Update()
{
    if (m_bDead == true)
        return OBJ_DEAD;

    Update_Rect();

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
    Rectangle(hDC, m_tRect.left+10, m_tRect.top+10, m_tRect.right-10, m_tRect.bottom-10);

}

void CBoss02::Release()
{

}



void CBoss02::Key_Input()
{
	if (GetAsyncKeyState('8'))

	{
        m_pBullet->push_back(Create_Bullet(DIR_DOWN));
	}
}

