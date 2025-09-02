#pragma once

#include "CItem.h"

class CItem_Erase : public CItem
{
public:
	CItem_Erase();
	virtual ~CItem_Erase();

public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void Use_Item(CObj* _pObj) override;

};

