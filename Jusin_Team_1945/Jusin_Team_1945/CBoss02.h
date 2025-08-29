#pragma once
#include "Obj.h"
class CBoss02 :
    public Obj
{
public:
    CBoss02();
    ~CBoss02();

    // Obj을(를) 통해 상속됨
    void Initialize() override;

    int Update() override;

    void Late_Update() override;

    void Render(HDC hDC) override;

    void Release() override;

public:
    Obj* Create_Bullet(DIRECTION eDir);


    void		Set_Bullet(list<Obj*>* pBullet)
    {
        m_pBossBullet = pBullet;
    }

private:
    list<Obj*>* m_pBossBullet;


};

