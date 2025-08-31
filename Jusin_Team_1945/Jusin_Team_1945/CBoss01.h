#pragma once

#include "CObj.h"
#include "CTimerMgr.h"

class CBoss01 : public CObj
{
public:
    CBoss01();
    virtual ~CBoss01();

public:
    void Initialize() override;
    int Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;

public:
    RECT m_tHpUi;

    bool m_bHp;

private:

    CTimerMgr Mgr1;
    int AttackTime = 0;

    CTimerMgr Mgr2;
    int SkillTime = 0;
};

