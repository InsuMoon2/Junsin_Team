#pragma once
#include "CObj.h"
class CBoss02 :
    public CObj
{
public:
    CBoss02();
    ~CBoss02();

    // Obj��(��) ���� ��ӵ�
    void Initialize() override;

    int Update() override;

    void Late_Update() override;

    void Render(HDC hDC) override;

    void Release() override;


    void Key_Input();
};

