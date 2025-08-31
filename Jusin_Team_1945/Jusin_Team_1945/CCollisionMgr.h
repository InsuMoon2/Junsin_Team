#pragma once

#include "CObj.h"

class CCollisionMgr
{
public:
	static void	Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src);
	static void Collision_Circle(list<CObj*> _bullet, list<CObj*> _monster);
	static void Collision_Circle(list<CObj*> _bullet, CObj* _HitObject);
	
	static bool	Check_Circle(CObj* _Dst, CObj* _Src);

	static void Collision_Item(CObj* _pPlayer, list<CObj*> _Src);

};

