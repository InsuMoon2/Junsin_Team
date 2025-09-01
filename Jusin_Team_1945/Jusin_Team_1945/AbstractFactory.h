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

	// 좌표 설정
	static T* Create(float fX, float fY)
	{
		T* pObj = new T;
		pObj->Set_Pos(fX, fY);
		pObj->Initialize();
		return pObj;
	}

	//몬스터 ID 설정
	static CObj* Create(float fX, float fY, int ID)
	{
		CObj* pObj = new T;
		pObj->Set_Pos(fX, fY);
		pObj->Initialize();
		pObj->Set_ID(ID);
		return pObj;
	}

	static CObj* Create(CObj* target)
	{
		if (!target)
			return nullptr;

		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Target(target);


		return pObj;
	}

};

