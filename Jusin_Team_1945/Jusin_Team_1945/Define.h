#pragma once

#include "Windows.h"

#define	WINCX		720
#define	WINCY		960

#define PURE	= 0

#define OBJ_DEAD		1
#define OBJ_NOEVENT		0

#define PI	3.141582f

extern HWND g_hWnd;

typedef struct tagInfo
{
	float  fX, fY;
	float  fCX, fCY;

}INFO;

enum DIRECTION
{
	DIR_LEFT, 
	DIR_RIGHT,
	DIR_UP,
	DIR_DOWN,
	DIR_LU,
	DIR_RU,
	DIR_END
};

enum class ESceneType
{
	None,
	Stage01,
	Stage02,
	Stage03,
	TempStage,

	Stage_End
};
//몬스터 종류 추가
enum OBJID { PLAYER, BULLET, MONSTER01, MONSTER02, MOUSE, SHIELD, BOSS, OBJ_END };

template<typename T>
void	Safe_Delete(T& P)
{
	if (P)
	{
		delete P;
		P = nullptr;
	}
}

struct DeleteObj
{
	template<typename T>
	void	operator()(T& p)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
};

// 포신용 구조체
typedef struct POSINFO
{
	float X;
	float Y;
}POS;
