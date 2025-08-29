#pragma once
#include "Obj.h"
class Player : public Obj
{
public:
	Player();
	virtual ~Player();

public:
	void		Set_Bullet(list<Obj*>* pBullet)
	{
		m_pBullet = pBullet;
	}

public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

private:
	void		Key_Input();
	Obj* Create_Bullet(DIRECTION eDir);

private:
	list<Obj*>* m_pBullet;
};

