#pragma once
#include "CBullet.h"

class CBoss01Bullet : public CBullet
{
    public:
        CBoss01Bullet();
        ~CBoss01Bullet();

    public:
        void Initialize() override;
        int Update() override;
        void Late_Update() override;
        void Render(HDC hDC) override;
        void Release() override;

};

