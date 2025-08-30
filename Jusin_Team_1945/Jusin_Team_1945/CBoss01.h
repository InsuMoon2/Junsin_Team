#pragma once

#include "CObj.h"

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


};

