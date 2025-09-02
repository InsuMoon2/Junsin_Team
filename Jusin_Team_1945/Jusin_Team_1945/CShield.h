#pragma once

#include "CObj.h"
#include "CTimerMgr.h"

class CShield : public CObj
{
public:
	CShield();
	virtual ~CShield();

public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
};

class CShield_Player : public CShield
{
public:
	CShield_Player();
	virtual ~CShield_Player();

public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

};

class CShield_Erase : public CShield
{
public:
	CShield_Erase();
	virtual ~CShield_Erase();

public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
};

class CShield_Pet : public CShield
{
public:
	CShield_Pet();
	virtual ~CShield_Pet();

public:
	void Initialize() override;
	int  Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

private:
	CTimerMgr m_Pet_Handle;
	int		  m_Pet_Attack = 0;
};

