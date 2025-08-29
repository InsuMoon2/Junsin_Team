#pragma once

#include "Obj.h"

class CollisionMgr
{
public:
	static void	Collision_Rect(list<Obj*> _Dst, list<Obj*> _Src);
	
	static void	Collision_Circle(list<Obj*> _Dst, list<Obj*> _Src);
	static bool	Check_Circle(Obj* _Dst, Obj* _Src);

};

