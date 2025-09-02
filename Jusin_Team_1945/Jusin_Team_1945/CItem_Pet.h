#pragma once

#include "CItem.h"

class CItem_Pet : public CItem
{
public:
	CItem_Pet();
	virtual ~CItem_Pet();

public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void Use_Item(CObj* _pObj) override;
};

