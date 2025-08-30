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


    void Attack_Circular();
    void Attack_Cos();
};

