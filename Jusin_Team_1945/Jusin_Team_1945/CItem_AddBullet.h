#pragma once

#include "CItem.h"

class CItem_AddBullet : public CItem
{
public:
	CItem_AddBullet();
	virtual ~CItem_AddBullet();

public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

public:
	void Use_Item(CObj* _pObj) override;
};

