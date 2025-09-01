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

    double normalize(double x, double in_min, double in_max) {
        return (x - in_min) / (in_max - in_min);
    }

    double rescale(double n, double out_min, double out_max) {
        return out_min + n * (out_max - out_min);
    }

    RECT m_tHpUi;

    bool m_bHp;


    DWORD		m_dwTime;
    DWORD m_dwTime01;
    DWORD m_dwTime02;
    DWORD m_dwTime03;

    float m_fBarrel_Speed;

    void Attack_Circular();
    void Attack_Cos();
    void Attack_Guided();
    void Attack_Around();


    CTimerMgr Mgr1;
    int attackTime1 = 0;

    bool bCheck = true;

};

