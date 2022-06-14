#include "main.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR    lpCmdLine, _In_ int nCmdShow)
{
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWPROGRAMMINGFRAMEWORK));

    MSG Message;

    g_hInst = hInstance;

    gFramework.Init();

    // 시작할때 코드
    //HWND hWnd;
    /*whlie()
    {*/
        MessageBox(hwndBG, L"GameStart", L"게임 시작", NULL);
    //}
    


    gFramework.ShowWnd(nCmdShow);


    while (true)
    {
       /* for (int i = 0; i < SOUND_NUM; ++i)
            gFramework.GetSound()[i].Update();*/
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


