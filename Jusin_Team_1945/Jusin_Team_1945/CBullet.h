#pragma once

#include "CObj.h"

class CBullet : public CObj
{
public:
    CBullet();
    virtual ~CBullet();

public:
    void Initialize() override;
    int  Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;

public:
    virtual CObj* Create_Bullet(DIRECTION eDir, float angle) override { return nullptr; }
};



