#include "pch.h"
#include "CBullet.h"

CBullet::CBullet()
{
}

CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	//__super::Update_Rect();
}

int CBullet::Update()
{
	
	__super::Update_Rect();


	return OBJ_NOEVENT;
}

void CBullet::Late_Update()
{
	
}


void CBullet::Render(HDC hDC)
{
}

void CBullet::Release()
{
}




