#pragma once

#include "CObj.h"

template<typename T>
class AbstractFactory
{
public:
	static CObj* Create()
	{
		CObj* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	// ÁÂÇ¥ ¼³Á¤
	static CObj* Create(float fX, float fY)
	{
		CObj* pObj = new T;
		pObj->Set_Pos(fX, fY);
		pObj->Initialize();

		return pObj;
	}
};

