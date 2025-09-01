#pragma once
#include "CBullet.h"

class CBullet_Monster02 : public CBullet
{
public:
    CBullet_Monster02();
    virtual ~CBullet_Monster02();



public:
    void Initialize() override;
    int  Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;

private:
    BOOL m_bStart = true;


};

