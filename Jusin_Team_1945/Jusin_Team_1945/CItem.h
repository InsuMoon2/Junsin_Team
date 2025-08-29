#pragma once

#include "CObj.h"

class CItem : public CObj
{
public:
	CItem();
	virtual ~CItem();

public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

public:
	// 아이템 사용 효과
	virtual void Use_Item(CObj* _pObj);
};

