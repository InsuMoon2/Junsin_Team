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

	// ��ǥ ����
	static T* Create(float fX, float fY)
	{
		T* pObj = new T;
		pObj->Set_Pos(fX, fY);
		pObj->Initialize();

		return pObj;
	}
};

