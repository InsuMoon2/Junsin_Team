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
	DIR_LD,
	DIR_RD,
	DIR_END
};

enum class ESceneType
{
	Stage01 = 0,
	Stage02,
	Stage03,
	TempStage,

	Stage_End
};
//���� ���� �߰�
enum OBJID { ERASER_ITEM, ERASER_BULLET, PLAYER, BULLET, MONSTER01, MONSTER02, MOUSE, ITEM, BOSS, SHIELD, POTION, PET, OBJ_END };

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

// ���ſ� ����ü
typedef struct POSINFO
{
	float X;
	float Y;
}POS;
// ������ ���� �Ҹ���
enum BT { Circular, Cos, Guided, Around, BT_END };

// �������ϱ� ��� ���ٿ�
//TCHAR szBuff[32] = L"";
//swprintf_s(szBuff, L" : %d", temp);
//TextOut(hDC, 50, 140, szBuff, lstrlen(temp));
