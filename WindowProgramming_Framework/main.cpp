#include "main.h"
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = NULL;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = NULL;
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = NULL;

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    g_hInst = hInstance;
    //MainWnd
    hwnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        550, 300, 400, 300, nullptr, nullptr, hInstance, nullptr);
    //UIWnd
    hwndUI = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        0, 680, 250, 150, nullptr, nullptr, hInstance, nullptr);
    //BackGroundWnd
    hwndBG = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        0, 0, 1600, 850, nullptr, nullptr, hInstance, nullptr);
    if (!hwnd)
    {
        return FALSE;
    }

    ShowWindow(hwndBG, nCmdShow);
    UpdateWindow(hwndBG);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    ShowWindow(hwndUI, nCmdShow);
    UpdateWindow(hwndUI); 
    
    

    return TRUE;
}

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hDC;
    static int size = 300;
    static int speed = 10;
    static POINT p;

    static HBITMAP hBitMap;
    HDC memdc;
    switch (message)
    {
    case WM_CREATE:
        hBitMap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));
        gFramework.Init(hwnd, g_hInst);
        gFramework.InitUI(hwndUI);
        gFramework.InitBackGround(hwndBG);
        break;

    case WM_MOUSEMOVE:
        /*
        p.left = LOWORD(lParam);
        p.right = HIWORD(lParam);


        SetWindowPos(hWnd, NULL, p.left, p.top, size, size, NULL);
        */
        break;

    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(g_hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hwnd);
            DestroyWindow(hwndUI);
            DestroyWindow(hwndBG);

            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
            //return DefWindowProc(hwndUI, message, wParam, lParam);
            //return DefWindowProc(hwndBG, message, wParam, lParam);

        }
    }
    break;

    case WM_CHAR:
        switch (wParam)
        {
        case 'w':
            if (p.y > 0)
            {
                p.y -= speed;
            }
            break;

        case 'a':
            if (p.x > 0)
            {
                p.x -= speed;
            }
            break;

        case 's':
            if (p.y + size < 720)
            {
                p.y += speed;
            }
            break;

        case 'd':
            if (p.x + size < 1280)
            {
                p.x += speed;
            }
            break;


        case 'q':
            PostQuitMessage(0);
            break;
        }
        SetWindowPos(hWnd, NULL, p.x, p.y, size, size, NULL);
        // SetWindowPos(hWnd, NULL,x,y, width, height, NULL);

        InvalidateRect(hWnd, NULL, TRUE);

        break;

    case WM_KEYDOWN:
    case WM_KEYUP:
    {
        gFramework.KeyboardProcess(message, wParam, lParam);
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        memdc = CreateCompatibleDC(hdc);
        SelectObject(memdc, hBitMap);
        StretchBlt(hdc, 0, 0, 1000, 1000, memdc, p.x, p.y, 1280, 720, SRCCOPY);
        DeleteDC(memdc);
        gFramework.Draw(hdc);
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        gFramework.Reset();
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine, _In_ int nCmdShow)
{
    //UNREFERENCED_PARAMETER(hPrevInstance);
    //UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    //LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    //LoadStringW(hInstance, IDC_WINDOWPROGRAMMINGFRAMEWORK, szWindowClass, MAX_LOADSTRING);
    //MyRegisterClass(hInstance);

    //if (!InitInstance(hInstance, nCmdShow))
    //{
        //return FALSE;
    //}

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWPROGRAMMINGFRAMEWORK));

    //MSG msg;

    //CTRL + C
    HWND hWnd;
    HWND MainhWnd;
    MSG Message;
    WNDCLASSEX WndClass;
    g_hInst = hInstance;


    gFramework.InitWCX(WINDOW::Main);
    gFramework.InitWCX(WINDOW::UI);
    //gFramework.InitWCX(WINDOW::BackGround);

    gFramework.RegisterWnd();
    gFramework.ShowWnd(hInstance, nCmdShow);

    //CTRL + V

    // 기본 메시지 루프입니다:
    while (true)
    {
        if (::PeekMessage(&Message, NULL, 0, 0, PM_REMOVE))
        {
            if (Message.message == WM_QUIT) break;
            if (!::TranslateAccelerator(Message.hwnd, hAccelTable, &Message))
            {
                ::TranslateMessage(&Message);
                ::DispatchMessage(&Message);
            }
        }
    }
    gFramework.Reset();
    return (int)Message.wParam;
}


