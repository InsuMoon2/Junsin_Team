#pragma once

#include <vector>

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
	void			Set_PosinNumber(int _iNumber) { m_iBarrel_Number = _iNumber; }

	const RECT*		Get_Rect()	 { return &m_tRect; }
	void			Set_Dead()	 { m_bDead = true; }
	INFO			Get_Info()	 { return m_tInfo; }

	int			    Get_Hp()	 { return m_iHp; }
	int				Get_Attack() { return m_iAttack; }
	int				Get_Def()    { return m_iDef; }
	float			Get_Speed()  { return m_fSpeed; }

	int				Get_PosinNumber() { return m_iBarrel_Number; }

public:

	void  Set_Bullet(list<CObj*>* pBullet) { m_pBullet = pBullet; }
	virtual CObj* Create_Bullet(DIRECTION eDir);
	virtual CObj* Create_Bullet(float angle);

	virtual CObj* Create_PlayerBullet(DIRECTION eDir);
	virtual void Create_PlayerBullet(vector<POS>& vPos, float angle);

	virtual CObj* Create_BossBullet(float angle, BT type);

	virtual CObj* Create_Boss01Bullet(DIRECTION eDir);
	virtual CObj* Create_Boss01Bullet(float angle);
	
	virtual CObj* Create_MonsterBullet01(DIRECTION eDir);
	virtual CObj* Create_MonsterBullet02(DIRECTION eDir,float angle);

	void  Set_Owner(CObj* _pOwner) { m_pOwner = _pOwner; }
	CObj* Get_Owner()			   { return m_pOwner; }
	
	 void Set_Angle(float angle) { m_fAngle = angle; }
	 void Set_Target(CObj* target) { m_tTarget = target; }
	 void Set_ID(int _ID) { m_iID = _ID; }

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

	// 안은수 : 포신
	float m_fAngle;
	POS m_tBarrel_Pos;
	int m_iBarrel_Len;

	CObj* m_tTarget;

	// 황유림 : 몬스터 ID
	int m_iID;

	// 문인수 : 포신 개수
	int m_iBarrel_Number;
};

