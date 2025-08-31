#pragma once

#include "CBullet.h"

class CPlayerBullet : public CBullet
{
public:
    CPlayerBullet();
    virtual ~CPlayerBullet();

public:
    void Initialize() override;
    int  Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;
};

