#include "main.h"

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

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine, _In_ int nCmdShow)
{
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWPROGRAMMINGFRAMEWORK));

    MSG Message;

    g_hInst = hInstance;


    gFramework.InitWCX(WINDOW::Main);
    gFramework.InitWCX(WINDOW::UI);
    gFramework.InitWCX(WINDOW::BackGround);

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


