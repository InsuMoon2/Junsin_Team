#pragma once

#include "Obj.h"

template<typename T>
class AbstractFactory
{
public:
	static Obj* Create()
	{
		Obj* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	// ÁÂÇ¥ ¼³Á¤
	static Obj* Create(float fX, float fY)
	{
		Obj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(fX, fY);

		return pObj;
	}
};

