#pragma once
#include "Obj.h"
class Mouse :  public Obj
{
public:
	Mouse();
	virtual ~Mouse();
	
public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
};

