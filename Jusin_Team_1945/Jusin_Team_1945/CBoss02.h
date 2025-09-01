#pragma once
#include "CObj.h"
#include "CTimerMgr.h"
class CBoss02 :
    public CObj
{
public:
    CBoss02();
    ~CBoss02();

    // Obj을(를) 통해 상속됨
    void Initialize() override;

    int Update() override;

    void Late_Update() override;

    void Render(HDC hDC) override;

    void Release() override;

public:
    void Key_Input();

    RECT m_tHpUi;

    bool m_bHp;


    DWORD		m_dwTime;

    float m_fBarrel_Speed;

    void Attack_Circular();
    void Attack_Cos();
    void Attack_Guided();


    CTimerMgr Mgr1;
    int attackTime1 = 0;

    bool bCheck = true;

};

