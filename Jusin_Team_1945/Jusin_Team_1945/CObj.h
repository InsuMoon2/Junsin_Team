#pragma once

#include "Define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual void		Initialize()	PURE;
	virtual int			Update()		PURE;
	virtual void		Late_Update()	PURE;
	virtual void		Render(HDC hDC)	PURE;
	virtual void		Release()		PURE;

public:
	void			Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}

	void			Set_Hp(int _iHp)         { m_iHp = _iHp; }
	void			Set_Attack(int _iAttack) { m_iAttack = _iAttack; }
	void			Set_Def(int _iDef)       { m_iDef = _iDef; }

	void			Set_Direction(DIRECTION eDir) { m_eDir = eDir; }

	const RECT*		Get_Rect()	 { return &m_tRect; }
	void			Set_Dead()	 { m_bDead = true; }
	INFO			Get_Info()	 { return m_tInfo; }

	int			    Get_Hp()	 { return m_iHp; }
	int				Get_Attack() { return m_iAttack; }
	int				Get_Def()    { return m_iDef; }


protected:
	void		Update_Rect();

protected:
	INFO		m_tInfo;
	RECT		m_tRect;
	DIRECTION	m_eDir;

	float		m_fSpeed;
	bool		m_bDead;

	int			m_iHp;
	int			m_iAttack;
	int			m_iDef;

};

