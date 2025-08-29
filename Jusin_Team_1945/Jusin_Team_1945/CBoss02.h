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

public:
    CObj* Create_Bullet(DIRECTION eDir);


    void		Set_Bullet(list<CObj*>* pBullet)
    {
        m_pBossBullet = pBullet;
    }

private:
    list<CObj*>* m_pBossBullet;


};

