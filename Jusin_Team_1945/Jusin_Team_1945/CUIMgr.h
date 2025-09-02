#pragma once
class CObj;
class CScene;
class CUIMgr
{
private:
	CUIMgr();
	~CUIMgr();

public:

	void Initialize();
	int Update();
	void LateUpdate();
	void Render(HDC hDC);
	void Release();

	static CUIMgr* Get_Instance()
	{
		static CUIMgr s_Instance;

		return &s_Instance;
	}

	static void Render_HP(HDC hdc, CObj* my);
	static void Render_Stage(HDC hdc);
	static void Render_Barrel(HDC hdc,int barrelNum);

	static void Render_GameOver(HDC hdc, int winCX, int winCY, bool over = true);

	//static CUIMgr* Get_Instance()
	//{
	//	if (m_pInstance == nullptr)
	//	{
	//		m_pInstance = new CUIMgr;
	//	}
	//
	//	return m_pInstance;
	//}
	//
	//static void Destroy_Instance()
	//{
	//	if (m_pInstance)
	//	{
	//		delete m_pInstance;
	//		m_pInstance = nullptr;
	//
	//	}
	//}

	private:
	//	static CUIMgr* m_pInstance;
};

