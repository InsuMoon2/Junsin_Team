#pragma once

#include "CObj.h"

class CEraser : public CObj
{
public:
	CEraser();
	virtual ~CEraser();

public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
};

class CEraser2 : public CEraser
{
public:
	CEraser2();
	virtual ~CEraser2();

public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
};

