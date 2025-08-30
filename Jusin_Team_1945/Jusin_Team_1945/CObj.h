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
	void			Set_Speed(float _fSpeed) { m_fSpeed = _fSpeed; }

	void			Set_Direction(DIRECTION eDir) { m_eDir = eDir; }

	const RECT*		Get_Rect()	 { return &m_tRect; }
	void			Set_Dead()	 { m_bDead = true; }
	INFO			Get_Info()	 { return m_tInfo; }

	int			    Get_Hp()	 { return m_iHp; }
	int				Get_Attack() { return m_iAttack; }
	int				Get_Def()    { return m_iDef; }
	float			Get_Speed()  { return m_fSpeed; }

public:
	// 문인수 : Player-> Obj로 Set,Create Bullet 이동
	void  Set_Bullet(list<CObj*>* pBullet) { m_pBullet = pBullet; }
	virtual CObj* Create_Bullet(DIRECTION eDir = DIRECTION::DIR_END, float angle = 0)
	{
		return nullptr;
	}

	// 문인수 : Monster의 총알이 자기 자신과 충돌, 자기 자신을 무시하기 위해서 
	void  Set_Owner(CObj* _pOwner) { m_pOwner = _pOwner; }
	CObj* Get_Owner()			   { return m_pOwner; }

	// 안은수: 총알 발사 셋팅
	 void Set_Angle(float angle) { m_fAngle = angle; }

protected:
	void		Update_Rect();

	INFO		m_tInfo;
	RECT		m_tRect;
	DIRECTION	m_eDir;

	float		m_fSpeed;
	bool		m_bDead;
	
	int			m_iHp;
	int			m_iAttack;
	int			m_iDef;
		
	CObj*		 m_pOwner;

	list<CObj*>* m_pBullet;

	// 안은수 :
	float m_fAngle;

};

