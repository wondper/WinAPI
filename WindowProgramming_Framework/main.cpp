#include "main.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine, _In_ int nCmdShow)
{
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWPROGRAMMINGFRAMEWORK));

    MSG Message;

    g_hInst = hInstance;

    gFramework.ShowWnd(nCmdShow);

<<<<<<< HEAD
    gFramework.ShowWnd(nCmdShow);

    //CTRL + V

    // 기본 메시지 루프입니다:
=======
>>>>>>> b16d82398f180b04b317353607371b2a2e57c031
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


