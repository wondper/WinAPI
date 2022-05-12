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
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = NULL;

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance;

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
    switch (message)
    {
    case WM_CREATE:
        gFramework.Init(hwnd);
        gFramework.InitUI(hwndUI);
        gFramework.InitBackGround(hwndBG);
        break;
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
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWPROGRAMMINGFRAMEWORK, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWPROGRAMMINGFRAMEWORK));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (true)
    {
        if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT) break;
            if (!::TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                ::TranslateMessage(&msg);
                ::DispatchMessage(&msg);
            }
        }
    }
    gFramework.Reset();
    return (int)msg.wParam;
}
