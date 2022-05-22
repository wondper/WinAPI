#include "GFramework.h"
GFramework::GFramework()
{
	//mhInstance = g_hInst;
}

GFramework::~GFramework()
{

}

void GFramework::Init(HWND hwnd, HINSTANCE gInst)
{
	mhMainWnd = hwnd;
    mhInstance = gInst;
}

void GFramework::InitWCX(WINDOW wnd)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	//wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = mhInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(RGB(100, 100, 100));
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"MainWindow";
	wcex.hIconSm = NULL;
	switch (wnd)
	{
	case WINDOW::Main:
		wcex.lpfnWndProc = MainWndProc;
		wcex.lpszClassName = L"MainWindow";
		wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		mwcxMain = wcex;
		break;
	case WINDOW::UI:
		wcex.lpfnWndProc = UIWndProc;
		wcex.lpszClassName = L"UIWindow";
		wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		mwcxUI = wcex;
		break;
	case WINDOW::BackGround:
		wcex.lpfnWndProc = BackGroundWndProc;
		wcex.lpszClassName = L"BackGroundWindow";
		wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		mwcxBackGround = wcex;
    case WINDOW::Monster:
        wcex.lpfnWndProc = MonsterWndProc;
        wcex.lpszClassName = L"MonsterGroundWindow";
        wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
        mwcxBackGround = wcex;
		break;
	}
    
}

void GFramework::RegisterWnd()
{
	RegisterClassEx(&mwcxMain);
	RegisterClassEx(&mwcxUI);
	RegisterClassEx(&mwcxBackGround);
}

void GFramework::ShowWnd(HINSTANCE hInstance, int nCmdShow)
{
	mhInstance = hInstance;
	mhUIWnd = CreateWindow(L"UIWindow", L"UI", NULL, 0, 800, GetSystemMetrics(SM_CXSCREEN), 200, NULL, NULL, hInstance, NULL);
    for (size_t i = 0; i < m_count[stage_count]; i++)
    {
        mhMonsterWnd[i] = CreateWindow(L"MonsterGroundWindow", L"Monster", NULL, monster[stage_count][i].P.x, monster[stage_count][i].P.y, 
            monster[stage_count][i].Win_SizeX, monster[stage_count][i].Win_SizeY, NULL, NULL, hInstance, NULL);
    }

    mhBackGroundWnd = CreateWindowEx(WS_EX_LAYERED | WS_EX_TOPMOST | WS_EX_TOOLWINDOW, L"BackGroundWindow", L"BackGround", WS_VISIBLE, 0, 0, 1200, 800, nullptr, nullptr, hInstance, nullptr);

    mhMainWnd = CreateWindow(L"MainWindow", L"Main", NULL, 0, 0, 200, 200, NULL, NULL, hInstance, NULL);

	ShowWindow(mhUIWnd, nCmdShow);
	ShowWindow(mhMainWnd, nCmdShow);

    for (size_t i = 0; i < MAX_m; i++)
    {
        ShowWindow(mhMonsterWnd[i], nCmdShow);
    }

    SetLayeredWindowAttributes(mhBackGroundWnd, RGB(0, 0, 0), 0, LWA_COLORKEY);
    ShowWindow(mhBackGroundWnd, nCmdShow);
}

void GFramework::InitUI(HWND hwndUI)
{
	//mhMainWnd_UI = hwndUI;
}

void GFramework::InitBackGround(HWND hwndBG)
{
	//mhMainWnd_BackGround = hwndBG;
}

void GFramework::Update(const float fTime)
{

}

void GFramework::Reset()
{

}

void GFramework::Draw(HDC hdc)
{

}

void GFramework::KeyboardProcess(UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_KEYDOWN:
	{
		if (wParam == VK_ESCAPE)
		{
			SendMessage(mhMainWnd, WM_DESTROY, 0, 0);
			return;
		}
	}
	break;


	case WM_KEYUP:
	{

	}
	break;


	}
}

void GFramework::MouseProcess(UINT iMessage, WPARAM wParam, LPARAM lParam)
{

}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hDC, memdc;
    PAINTSTRUCT ps;
    switch (message)
    {

    case WM_CREATE:
        BG_MAP = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));
        //     wndCount++;
        return 0;
    case WM_CHAR:
        switch (wParam)
        {

        case 'q':
            PostQuitMessage(0);
            break;

        case 'f':
            break;

        case 'w':
            User.P.y -= User.WinFrameSpeed;
            SetWindowPos(hWnd, NULL, User.P.x, User.P.y, User.Win_SizeX, User.Win_SizeY, NULL);
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case 'a':
            User.P.x -= User.WinFrameSpeed;
            SetWindowPos(hWnd, NULL, User.P.x, User.P.y, User.Win_SizeX, User.Win_SizeY, NULL);
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case 's':
            User.P.y += User.WinFrameSpeed;
            SetWindowPos(hWnd, NULL, User.P.x, User.P.y, User.Win_SizeX, User.Win_SizeY, NULL);
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case 'd':
            User.P.x += User.WinFrameSpeed;
            SetWindowPos(hWnd, NULL, User.P.x, User.P.y, User.Win_SizeX, User.Win_SizeY, NULL);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        break;


    case WM_LBUTTONDOWN:
        if (!User.Triger)
        {
            User.Bullet -= 1;
            User.Triger = true;
            SetTimer(hWnd, 3, 50, NULL);

            for (size_t i = 0; i < m_count[stage_count]; i++)
            {
                if (!monster[stage_count][i].Dead)
                {
                    monster[stage_count][i].Hp--;
                    monster[stage_count][i].Stats = 1;
                }
            }

        }
        InvalidateRect(hWnd, NULL, TRUE);

        break;


    case WM_TIMER:
        switch (wParam)
        {
        case 3:
            if(User.Triger)
            switch (User.TrigerFrame++)
            {
            case 0:
                SetWindowPos(hWnd, NULL, User.P.x + 5, User.P.y -5, User.Win_SizeX, User.Win_SizeY, NULL);
                break;
            case 1:
                SetWindowPos(hWnd, NULL, User.P.x - 5, User.P.y - 5, User.Win_SizeX, User.Win_SizeY, NULL);
                break;
            case 2:
                SetWindowPos(hWnd, NULL, User.P.x + 5, User.P.y, User.Win_SizeX, User.Win_SizeY, NULL);
                break;
            case 3:
                SetWindowPos(hWnd, NULL, User.P.x + 5, User.P.y + 5, User.Win_SizeX, User.Win_SizeY, NULL);
                break;
            case 4:
                SetWindowPos(hWnd, NULL, User.P.x - 5, User.P.y - 5, User.Win_SizeX, User.Win_SizeY, NULL);
                break;
            case 5:
                SetWindowPos(hWnd, NULL, User.P.x - 5, User.P.y - 5, User.Win_SizeX, User.Win_SizeY, NULL);
                break;
            case 6:
                SetWindowPos(hWnd, NULL, User.P.x, User.P.y, User.Win_SizeX, User.Win_SizeY, NULL);
                User.TrigerFrame = 0;
                User.Triger = false;
                KillTimer(hWnd, 3);
                break;
            }




            break;
        }




        break;
    case WM_PAINT:
        hDC = BeginPaint(hWnd, &ps);
        gFramework.Draw(hDC);
        memdc = CreateCompatibleDC(hDC);
        SelectObject(memdc, BG_MAP);
        StretchBlt(hDC, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), memdc, User.P.x, User.P.y, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CXSCREEN), SRCCOPY);

        DeleteDC(memdc);
        EndPaint(hWnd, &ps);
        return 0;


    case WM_DESTROY:
        //     wndCount--;
       // if (wndCount == 0) {
        PostQuitMessage(0);
        // }
        return 0;

    }
    return DefWindowProc(hWnd, message, wParam, lParam);

}

LRESULT CALLBACK UIWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hDC;
    PAINTSTRUCT ps;
    HBRUSH hBrush, oldhBrush;

    switch (message) {

    case WM_CREATE:
        SetTimer(hWnd, 1, 10, NULL);

        break;
    case WM_LBUTTONDOWN:

        InvalidateRect(hWnd, NULL, TRUE);
        break;


    case WM_TIMER:
        switch (wParam)
        {
        case 1:
            // UI 업데이트 틱
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        break;

    case WM_CHAR:
        switch (wParam)
        {
        case 'q':
            PostQuitMessage(0);
            break;


        }
        break;

    case WM_PAINT:
        hDC = BeginPaint(hWnd, &ps);
        hBrush = CreateSolidBrush(RGB(255, 0, 0));
        oldhBrush = (HBRUSH)SelectObject(hDC, hBrush);
        TextOut(hDC, 0, 30, L"SCORE : ", 8);
        wsprintf(User.str_Score, L"%d", User.Score);
        TextOut(hDC, 0, 50, User.str_Score, lstrlen(User.str_Score));


        TextOut(hDC, 0, 80, L"HandGun Bullet : ", 15);
        wsprintf(User.str_Bullet, L"%d", User.Bullet);
        TextOut(hDC, 0, 100, User.str_Bullet, lstrlen(User.str_Bullet));


        Rectangle(hDC, 80, 0, User.HP, 20);
        SelectObject(hDC, hBrush);
        DeleteObject(hBrush);





        EndPaint(hWnd, &ps);
        return 0;

    case WM_DESTROY:
        //wndCount--;
        //if (wndCount == 0) {
        PostQuitMessage(0);
        //}

        return 0;

    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT CALLBACK BackGroundWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hDC;
    PAINTSTRUCT ps;

    switch (message)
    {

    case WM_CREATE:
        //wndCount++;
        return 0;


    case WM_DESTROY:
        //wndCount--;
        //if (wndCount == 0) {
            PostQuitMessage(0);
        //}
        return 0;

    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT CALLBACK MonsterWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hDC, memdc;
    PAINTSTRUCT ps;

    switch (message)
    {

    case WM_CREATE:
        SetTimer(hWnd,1, 10, NULL); // 몬스터 프로시저 업데이트 타이머 입니다.
        for (size_t i = 0; i < m_count[stage_count]; i++)
        {

        }

        return 0;
    case WM_CHAR:
      
        break;

    case WM_TIMER:
        switch (wParam)
        {
        case 1:
            for (size_t i = 0; i < m_count[stage_count]; i++)
            {
                if (monster[stage_count][i].Stats == 1) SetTimer(hWnd,3,50,NULL);
            }
            break;



        case 3:
            for (size_t i = 0; i < m_count[stage_count]; i++)
            {
                switch (monster[stage_count][i].ActionFrame)
                {
                case 0:
                    SetWindowPos(hWnd, NULL, monster[stage_count][i].P.x + 5, monster[stage_count][i].P.y - 5, monster[stage_count][i].Win_SizeX, monster[stage_count][i].Win_SizeY, NULL);
                    break;
                case 1:
                    SetWindowPos(hWnd, NULL, monster[stage_count][i].P.x - 5, monster[stage_count][i].P.y - 5, monster[stage_count][i].Win_SizeX, monster[stage_count][i].Win_SizeY, NULL);
                    break;
                case 2:
                    SetWindowPos(hWnd, NULL, monster[stage_count][i].P.x + 5, monster[stage_count][i].P.y, monster[stage_count][i].Win_SizeX, monster[stage_count][i].Win_SizeY, NULL);
                    break;
                case 3:
                    SetWindowPos(hWnd, NULL, monster[stage_count][i].P.x + 5, monster[stage_count][i].P.y + 5, monster[stage_count][i].Win_SizeX, monster[stage_count][i].Win_SizeY, NULL);
                    break;
                case 4:
                    SetWindowPos(hWnd, NULL, monster[stage_count][i].P.x - 5, monster[stage_count][i].P.y - 5, monster[stage_count][i].Win_SizeX, monster[stage_count][i].Win_SizeY, NULL);
                    break;
                case 5:
                    SetWindowPos(hWnd, NULL, monster[stage_count][i].P.x - 5, monster[stage_count][i].P.y - 5, monster[stage_count][i].Win_SizeX, monster[stage_count][i].Win_SizeY, NULL);
                    break;
                case 6:
                    SetWindowPos(hWnd, NULL, monster[stage_count][i].P.x, monster[stage_count][i].P.y, monster[stage_count][i].Win_SizeX, User.Win_SizeY, NULL);
                    monster[stage_count][i].ActionFrame = 0;
                    monster[stage_count][i].Stats = 0;
                    KillTimer(hWnd, 3);
                    break;
                }
            }
           

            break;
        
        
        }



        break;




    case WM_LBUTTONDOWN:
     
        break;



    case WM_PAINT:
        hDC = BeginPaint(hWnd, &ps);
       
        EndPaint(hWnd, &ps);
        return 0;


    case WM_DESTROY:
        //     wndCount--;
       // if (wndCount == 0) {
        PostQuitMessage(0);
        // }
        return 0;

    }
    return DefWindowProc(hWnd, message, wParam, lParam);

}
