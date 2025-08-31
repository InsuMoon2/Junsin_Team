#pragma once
#include "CBullet.h"
class CBossBullet :
    public CBullet
{
public:
    CBossBullet();
    ~CBossBullet();

public:
    void Initialize() override;
    int Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;
public:
    void Set_Type(BT bt) { m_bulletType = bt; }
    float m_fDistance;
    void Attack_Circular();
    void Attack_Cos();
    void Attack_Guided();

    BT m_bulletType;

    DWORD m_dwTime;
    


};

