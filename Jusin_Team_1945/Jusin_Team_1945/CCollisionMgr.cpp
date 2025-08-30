#include "pch.h"
#include "CCollisionMgr.h"

#include "CItem.h"

void CCollisionMgr::Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src)
{
	RECT	rcCol{};

	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (Dst->Get_Owner() == Src)
				continue;

			if (IntersectRect(&rcCol, Dst->Get_Rect(), Src->Get_Rect()))
			{
				Dst->Set_Dead();
				Src->Set_Dead();
			}
		}
	}

}

void CCollisionMgr::Collision_Circle(list<CObj*> _bullet, list<CObj*> _monster)
{
	for (auto& Dst : _monster)
	{
		for (auto& Src : _bullet)
		{
			// Dst(총알)의 생성자가 Src(몬스터)와 같으면 충돌 검사 무시
			if (Dst->Get_Owner() == Src)
				continue;

			if (Check_Circle(Dst, Src))
			{
				Dst->Set_Hp(Dst->Get_Hp() - Src->Get_Attack());
				Src->Set_Dead();
			}
		}
	}
}

bool CCollisionMgr::Check_Circle(CObj* _Dst, CObj* _Src)
{
	float	fWidth  = fabsf(_Dst->Get_Info().fX - _Src->Get_Info().fX);
	float	fHeight = fabsf(_Dst->Get_Info().fY - _Src->Get_Info().fY);

	float	fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

	float	fRadius = (_Dst->Get_Info().fCX + _Src->Get_Info().fCX) * 0.5f;

	return fRadius >= fDiagonal;
}

void CCollisionMgr::Collision_Item(list<CObj*> _pPlayer, list<CObj*> _pItem)
{
	for (auto& player : _pPlayer)
	{
		for (auto& item : _pItem)
		{
			RECT	rcCol{};

			if (IntersectRect(&rcCol, player->Get_Rect(), item->Get_Rect()))
			{
				dynamic_cast<CItem*>(item)->Use_Item(player);
				item->Set_Dead();
			}
		}
	}
}