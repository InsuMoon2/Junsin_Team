// Jusin_Team_1945.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "Jusin_Team_1945.h"
#include "MainGame.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
HWND        g_hWnd;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,         // 현재 프로그램의 고유 식별 번호
    _In_opt_ HINSTANCE hPrevInstance,  // 전에 실행되었던 인스턴스 핸들(없을 경우 null값이 자동으로 삽입 / 호환성을 위해 존재)
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)           // 실행한 창의 스타일(모양 / 최대, 최소화 등)의 옵션 인자
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_JUSINTEAM1945, szWindowClass, MAX_LOADSTRING);

    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_JUSINTEAM1945));

    MSG msg;
    msg.message = WM_NULL;

    MainGame        MainGameClass;

    MainGameClass.Initialize();

    // 기본 메시지 루프입니다:
    /*while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }*/


    DWORD       dwTime = GetTickCount();        // 100

    while (true)
    {
        // PM_REMOVE : 메세지를 읽어옴과 동시에 메세지 큐에서 메세지를 제거
        // PM_NOREMOVE : 메세지 큐에 메세지가 존재하는지만 파악, 메세지를 읽어오려면 GetMessage 함수를 다시 호출해야 함

        // PeekMessage : 메세지 큐에 메세지가 없을 경우 0을 리턴
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (WM_QUIT == msg.message)
                break;

            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }

        else
        {
            // 122 < 111
            if (dwTime + 10 < GetTickCount())
            {
                MainGameClass.Update();
                MainGameClass.Late_Update();
                MainGameClass.Render();

                // 112
                dwTime = GetTickCount();
            }
        }
    }


    return (int)msg.wParam;
}

// 함수 호출 규약 : 함수의 실행이 종료되면 할당되었던 스택 메모리를 반환해야 하는데 함수를 호출하는 호출원(caller)에서 정리할 것인지
// 아니면 호출 받은 피호출자(callee)에서 할 것인가에 대한 약속 또는 규약

// cdecl만 caller가 스택을 정리!!!!

// __cdecl   : c/ c++언어의 기본 호출 규약, caller(호출원)이 스택을 정리한다. 공통점은 자기 자신에게 매개 변수가 어떤 것이 들어올지 모른다(가변인자 함수) 그래서 스스로 스택 메모리를 정리 할 수 없다.

// __stdcall : winapi의 기본 호출 규약, callee(피호출자)가 스택을 정리, 공통점은 고정인자 함수

// __fastcall : 함수 호출을 빠르게 처리하기 위한 규약, ecx, edx라는 레지스터를 통해 코드를 저장, 호출하여 함수 호출이 빨라짐

// __thiscall : this 포인터만 ecx에 저장하고 나머지는 스택에 저장하는 방식



//
//  함수: MyRegisterClass()
//
//  용도: 창 생성 시, 창 스타일을 지정 또는 변경
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;       // 윈도우 생성 시, 각종 값을 저장하기 위한 구조체

    wcex.cbSize = sizeof(WNDCLASSEX);       // 자기 자신의 자료형 크기를 저장

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    // 윈도우 스타일을 정의, 어떤 형태를 가질 것인가 지정
    // 초기화되는 값의 의미는 윈도우 창의 수직,수평의 크기가 변할 경우 윈도우를 다시 그리겠다는 의미

    wcex.lpfnWndProc = WndProc;
    // 저장해둔 함수가 호출되어 메세지를 처리하도록 하는 포인터

    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    // 윈도우가 특수한 목적으로 사용하는 여분의 공간, 일종의 예약 영역, 사용하지 않는 경우 0

    wcex.hInstance = hInstance;
    // 윈도우 클래스를 사용하는 프로그램 버노

    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_JUSINTEAM1945));
    // 윈도우에서 사용할 아이콘 지정

    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    // 윈도우에 출려갈 마우스 커서 지정

    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    // 윈도우 배경화면 색상

    wcex.lpszMenuName = NULL;//MAKEINTRESOURCEW(IDC_DEFAULTWINDOW);
    // 창 상단 메뉴

    wcex.lpszClassName = szWindowClass;
    // 실행파일 이름 저장(일반적으로 프로젝트 이름과 실행파일의 이름을 일치시킴)

    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    // 윈도우 상단에 나타는 작은 아이콘 모양 지정

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    RECT rcWindow{ 0, 0, WINCX, WINCY };


    // 최종 렉트의 크기 = rcWindow 사이즈 + 창 옵션(기본 창 스타일) + 메뉴 바 크기 고려 여부
    AdjustWindowRect(&rcWindow, WS_OVERLAPPEDWINDOW, FALSE);

    // 윈도우 핸들
    HWND hWnd = CreateWindowW(szWindowClass,         // 실행파일 이름
        szTitle,                // 캡션 타이틀
        WS_OVERLAPPEDWINDOW,    // 만들고자 하는 창의 스타일(기본 값)    
        CW_USEDEFAULT, 0,       // 생성되는 창 시작점의 X, Y좌표
        rcWindow.right - rcWindow.left,
        rcWindow.bottom - rcWindow.top,     // 생성되는 창의 가로, 세로 사이즈
        nullptr,                // 부모 윈도우가 있다면 부모 윈도우 핸들, 없으면 NULL
        nullptr,                // 윈도우가 사용할 메뉴 핸들(레지스터에 등록된 대로 사용할 것이면 NULL)
        hInstance,              // 윈도우를 만드는 주체
        nullptr);               // 운영체제가 특수한 목적으로 사용하는 값

    if (!hWnd)
    {
        return FALSE;
    }

    g_hWnd = hWnd;

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

// 기본 라이브러리

// 1. KERNEL : 메모리를 관리하고 프로그램을 실행시키는 명령어 집합
// 2. USER : 유저 인터페이스와 윈도우 창 관리 명령어 집합
// 3. GDI : 화면 처리와 그래픽 담당 명령어 집합


// RECT            rc{ 100, 100, 200, 200 };
// list<RECT>      BulletList;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:         // 창이 생성될 때 호출
        //    SetTimer(hWnd, 0, 0, 0);

        //    // 2 인자 : 타이머의 id
        //    // 3 인자 : 타이머 주기, 0인 경우 기본갑승로 1 / 1000 초에 해당
        //    // 4 인자 : null인 경우, 3인자에서 설정한 주기대로 WM_TIMER 메세지가 발생
        //    break;

        //case WM_TIMER:
        //    InvalidateRect(hWnd, 0, true);

        //   // 윈도우 갱신 함수
        //   //  1 인자 : 갱신할 윈도우 핸들
        //   //  2 인자 : 갱신할 범위(null인 경우 윈도우 전체 영역)
        //   //  3 인자 : true 인 경우 그려져 있지 않은 부분도 갱신, false 인 경우 새로 그리는 부분만 갱신

        //    break;


    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(g_hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    //case WM_PAINT:
    //    {
    //        PAINTSTRUCT ps;
    //        HDC hdc = BeginPaint(hWnd, &ps);
    //        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

    //        //// 2, 3 매개 변수 위치에 커서를 이동
    //        //MoveToEx(hdc, 100, 100, NULL);
    //        //
    //        //// 선 그리기 함수
    //        //LineTo(hdc, 200, 200);
    //        //
    //        //LineTo(hdc, 200, 300);
    //        //
    //        //Rectangle(hdc, 300, 300, 400, 400);
    //        //Ellipse(hdc, 600, 600, 700, 700);

    //       Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

    //       for (auto& Bullet : BulletList)
    //       {
    //           Ellipse(hdc, Bullet.left, Bullet.top, Bullet.right, Bullet.bottom);

    //           Bullet.top -= 10;
    //           Bullet.bottom -= 10;

    //       }


    //        EndPaint(hWnd, &ps);
    //    }
    //    break;

    case WM_KEYDOWN:

        switch (wParam)
        {
        case VK_ESCAPE:
            DestroyWindow(hWnd);
            break;
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
