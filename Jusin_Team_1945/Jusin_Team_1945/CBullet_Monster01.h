#pragma once
#include "CBullet.h"

class CBullet_Monster01 : public CBullet
{
public:
    CBullet_Monster01();
    virtual ~CBullet_Monster01();



public:
    void Initialize() override;
    int  Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;


};

