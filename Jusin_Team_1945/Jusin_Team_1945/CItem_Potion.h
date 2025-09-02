#pragma once

#include "CItem.h"

class CItem_Potion : public CItem
{
public:
	CItem_Potion();
	virtual ~CItem_Potion();

public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	void Use_Item(CObj* _pObj) override;

private:
	int	m_heal;
};

