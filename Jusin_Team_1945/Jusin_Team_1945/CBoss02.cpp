#include "pch.h"
#include "CBoss02.h"

CBoss02::CBoss02()
{
}

CBoss02::~CBoss02()
{
    Release();
}

void CBoss02::Initialize()
{
    m_tInfo = { WINCX / 2, WINCY / 2, 50, 50 };
    m_fSpeed = 10.f;



}

int CBoss02::Update()
{
    return 0;
}

void CBoss02::Late_Update()
{
}

void CBoss02::Render(HDC hDC)
{
    Rectangle(hDC, m_tRect.right, m_tRect.top, m_tRect.right, m_tRect.bottom);
    Rectangle(hDC, m_tRect.right+10, m_tRect.top+10, m_tRect.right-10, m_tRect.bottom-10);

}

void CBoss02::Release()
{
}

