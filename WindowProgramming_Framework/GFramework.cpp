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
    hwndMain = hwnd;
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
        break;
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
    hwndUI = CreateWindow(L"UIWindow", L"UI", NULL, 0, GetSystemMetrics(SM_CYSCREEN) - 300, GetSystemMetrics(SM_CXSCREEN),300, NULL, NULL, hInstance, NULL);
    hwndMain = CreateWindow(L"MainWindow", L"Main", NULL, 0, 0, 200, 200, NULL, NULL, hInstance, NULL);
    hwndBG = CreateWindowEx(WS_EX_LAYERED | WS_EX_TOOLWINDOW, L"BackGroundWindow", L"BackGround", WS_VISIBLE, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), nullptr, nullptr, hInstance, nullptr);
    /*for (size_t i = 0; i < m_count[stage_count]; i++)
    {
        mhMonsterWnd[i] = CreateWindow(L"MonsterGroundWindow", L"Monster", NULL, monster[stage_count][i].P.x, monster[stage_count][i].P.y,
            monster[stage_count][i].Win_SizeX, monster[stage_count][i].Win_SizeY, NULL, NULL, hInstance, NULL);
    }*/
    SetLayeredWindowAttributes(hwndBG, RGB(0, 0, 0), 0, LWA_COLORKEY);
    ShowWindow(hwndBG, nCmdShow);

    //for (size_t i = 0; i < MAX_m; i++)
    //{
    //    ShowWindow(mhMonsterWnd[i], nCmdShow);
    //}


    ShowWindow(hwndUI, nCmdShow);
    ShowWindow(hwndMain, nCmdShow);
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
			SendMessage(hwndMain, WM_DESTROY, 0, 0);
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

void GFramework::CreateMonster(int Round)
{
    int arr[6];
    switch (Round)
    {
    case 1:
        arr[0] = IDB_MONSTER_ZOMBIE1;
        arr[1] = IDB_MONSTER_ZOMBIE2;
        arr[2] = IDB_MONSTER_ZOMBIE3;
        arr[3] = IDB_MONSTER_ZOMBIE4;
        arr[4] = IDB_MONSTER_ZOMBIE5;
        arr[5] = IDB_MONSTER_ZOMBIE6;

      

        break;
    case 2:
        break;
    case 3:
        break;
    }

    void* raw_memory = operator new[](6 * sizeof(Zombie));
    mGameObject = static_cast<Zombie*>(raw_memory);
    for (int i = 0; i < 6; ++i)
    {
        new(&mGameObject[i]) Zombie(arr);
    }


        // destruct in inverse order    
        /*for (int i = 6 - 1; i >= 0; --i) {
            mGameObject[i].~GameObject();
        }
        operator delete[](raw_memory);*/
}


bool MouseCollisionCheck(int Mx, int My ,int left, int top, int right, int bottom)
{
    if (left > Mx &&  Mx<right &&
        top > My && My < bottom)
        return true;
    else return false;
}

bool BoxCollisionCheck(int Box1Left, int Box1Top, int Box1Right, int Box1Bottom, 
    int Box2Left, int Box2Top, int Box2Right, int Box2Bottom)
{
    if ((Box1Left < Box2Right) && (Box1Top < Box2Bottom) &&
        (Box1Right > Box2Left) && (Box1Bottom > Box2Top))
        return true;
    else return false;
}


LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hDC, memdc;
    static RECT rectView; // 윈도우창 크기

    static HBITMAP AimBit; // 조준점 비트맵 이미지
    static HDC AimDC; // 조준점 DC
     
    static int Trigerframe = 0;
    static bool Triger = false;
    PAINTSTRUCT ps;

    static POINT AimPosition{0,0};

    switch (message)
    {

    case WM_CREATE:
        GetClientRect(hWnd, &rectView);
        BG_MAP = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BG1_STAGE));
        AimBit = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_PLAY_AIM));

        return 0;
    case WM_CHAR:
        switch (wParam)
        {
        case 'q': // 프로그램 종료
            PostQuitMessage(0);
            break;

        case 'f':
            break;

        case 'w':
            if (User.GetPosition().y - FRAME_SPEED > 0)
            {
                User.SetPositionY(User.GetPosition().y - FRAME_SPEED);
                SetWindowPos(hWnd, NULL, User.GetPosition().x, User.GetPosition().y, WINSIZEX, WINSIZEY, NULL);
            
                InvalidateRect(hWnd, NULL, TRUE);
            }
            break;

        case 'a':
            if (User.GetPosition().x - FRAME_SPEED > 0)
            {
                User.SetPositionX(User.GetPosition().x - FRAME_SPEED);
                SetWindowPos(hWnd, NULL, User.GetPosition().x, User.GetPosition().y, WINSIZEX, WINSIZEY, NULL);
        
                InvalidateRect(hWnd, NULL, TRUE);
            }
                break;
        case 's':
            if (User.GetPosition().y + FRAME_SPEED < GetSystemMetrics(SM_CYSCREEN) -200 - WINSIZEY)
            {
                User.SetPositionY(User.GetPosition().y + FRAME_SPEED);
                SetWindowPos(hWnd, NULL, User.GetPosition().x, User.GetPosition().y, WINSIZEX, WINSIZEY, NULL);
      
                InvalidateRect(hWnd, NULL, TRUE);
            }
                break;
        case 'd':
            if (User.GetPosition().x + FRAME_SPEED < GetSystemMetrics(SM_CXSCREEN) - WINSIZEX)
            {
                User.SetPositionX(User.GetPosition().x + FRAME_SPEED);
                SetWindowPos(hWnd, NULL, User.GetPosition().x, User.GetPosition().y, WINSIZEX, WINSIZEY, NULL);
                InvalidateRect(hWnd, NULL, TRUE);
            }
            break;
        }
        rectView = { User.GetPosition().x + 10, User.GetPosition().y + 40,
            User.GetPosition().x+WINSIZEX - 10, User.GetPosition().y+ WINSIZEY - 10 };
        ClipCursor(&rectView);

        User.SetRect(User.GetPosition().x, User.GetPosition().y, User.GetPosition().x + AIMSIZEX, User.GetPosition().y + AIMSIZEY);
        break;


    case WM_MOUSEMOVE:

      AimPosition = { LOWORD(lParam),HIWORD(lParam)};
        
        

        InvalidateRect(hWnd, NULL, TRUE); // UI핸들을 보냄.
        break;
    
    
    
    case WM_LBUTTONDOWN:

        if (User.GetBullet() > 0)
        {
            User.DecreaseBulletCount();
            for (size_t i = 0; i < STAGE_ONE_MONSTER; i++)
            {
                if (MouseCollisionCheck(User.GetPosition().x + LOWORD(lParam), User.GetPosition().y + HIWORD(lParam)
                    , gFramework.GetGameObject()[i].GetPosition().x, gFramework.GetGameObject()[i].GetPosition().y,
                    gFramework.GetGameObject()[i].GetPosition().x + gFramework.GetGameObject()[i].GetWidth(),
                    gFramework.GetGameObject()[i].GetPosition().y + gFramework.GetGameObject()[i].GetHeight()))
                {
                    gFramework.GetGameObject()[i].SetHP(gFramework.GetGameObject()[i].GetHP() - 1);
                    User.SetHP(User.GetHP() + 10);

                }
            }
            Triger = true;
            SetTimer(hwndMain,3,10,NULL);
        }
        InvalidateRect(hwndUI, NULL, TRUE); // UI핸들을 보냄.
        break;

    
        

    case WM_TIMER:
        switch (wParam)
        {
        case 3:
            if (Triger)
            {
                switch (Trigerframe++)
                {
                case 0:
                    SetWindowPos(hWnd, NULL, User.GetPosition().x - 5, User.GetPosition().y + 5, WINSIZEX - 5, WINSIZEY + 5, NULL);
                    break;
                case 1:
                    SetWindowPos(hWnd, NULL, User.GetPosition().x, User.GetPosition().y - 5, WINSIZEX, WINSIZEY, NULL);
                    break;
                case 2:
                    SetWindowPos(hWnd, NULL, User.GetPosition().x + 5, User.GetPosition().y, WINSIZEX, WINSIZEY, NULL);
                    break;
                case 3:
                    SetWindowPos(hWnd, NULL, User.GetPosition().x - 5, User.GetPosition().y - 5, WINSIZEX, WINSIZEY, NULL);
                    break;
                case 4:
                    SetWindowPos(hWnd, NULL, User.GetPosition().x, User.GetPosition().y + 5, WINSIZEX, WINSIZEY, NULL);
                    break;
                case 5:
                    SetWindowPos(hWnd, NULL, User.GetPosition().x + 5, User.GetPosition().y + 5, WINSIZEX, WINSIZEY, NULL);
                    break;
                case 6:
                    SetWindowPos(hWnd, NULL, User.GetPosition().x, User.GetPosition().y, WINSIZEX, WINSIZEY, NULL);
                    Trigerframe = 0;
                    Triger = false;
                    KillTimer(hWnd, 3);
                    break;
                }
            }
            InvalidateRect(hwndUI, NULL, TRUE); // UI핸들을 보냄.
          

            break;
        }

        break;
    case WM_PAINT:
        hDC = BeginPaint(hWnd, &ps);
        gFramework.Draw(hDC);
        memdc = CreateCompatibleDC(hDC);
        SelectObject(memdc, BG_MAP);
        StretchBlt(hDC, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), memdc, User.GetPosition().x, User.GetPosition().y, 
            GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SRCCOPY);

        SelectObject(memdc, AimBit);
        TransparentBlt(hDC, AimPosition.x, AimPosition.y, 134/2, 134/2, memdc, 0, 0, 134, 134, RGB(0, 255, 0));
        SelectObject(memdc, AimBit);
        DeleteDC(memdc);

        for (size_t i = 0; i < STAGE_ONE_MONSTER; i++)
        {
            if (BoxCollisionCheck(User.GetPosition().x, User.GetPosition().y, User.GetPosition().x + WINSIZEX, User.GetPosition().y + WINSIZEY,
                gFramework.GetGameObject()[i].GetPosition().x, gFramework.GetGameObject()[i].GetPosition().y,
                gFramework.GetGameObject()[i].GetPosition().x + gFramework.GetGameObject()[i].GetWidth(),
                gFramework.GetGameObject()[i].GetPosition().y + gFramework.GetGameObject()[i].GetHeight()))
            {
                gFramework.GetGameObject()[i].DrawBitmap(hDC, memdc, gFramework.GetGameObject()[i].GetBitMapAnim());
            }
        }



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
    HDC hDC,memDC;
    PAINTSTRUCT ps;
    HBRUSH hBrush, oldhBrush;
    
    static HBITMAP mBitMap_Magazine;
    static HBITMAP oldBit;

    switch (message) {

    case WM_CREATE:
        mBitMap_Magazine = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_UI_BULLET));
        

        break;
    case WM_LBUTTONDOWN:
    {
        User.DecreaseBulletCount();
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
        memDC = CreateCompatibleDC(hDC);


        hBrush = CreateSolidBrush(RGB(255, 0, 0));
        oldhBrush = (HBRUSH)SelectObject(hDC, hBrush);

        //Score Text Set, TextOut
        User.SetScorestr();
        TextOut(hDC, 0, 50, User.GetScoreStr().c_str(), static_cast<int>(User.GetScoreStr().size()));

        oldBit = (HBITMAP)SelectObject(memDC, mBitMap_Magazine);

        //BulletText Set, TextOut
        User.SetBulletstr();
        for (int i = 0; i < User.GetBullet(); i++)
        {
            BitBlt(hDC,i*18,80,10,50,memDC, 0,0, SRCCOPY );
        }
        SelectObject(memDC, oldBit);
        DeleteDC(memDC);

        Rectangle(hDC, 300, 130, User.GetHP(), 20);
        
     
        
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
    HDC hDC, memdc;

    PAINTSTRUCT ps;
    HBRUSH hBrush, oldhBrush;

    static int frame = 0;

    switch (message)
    {

    case WM_CREATE:
        //wndCount++;
        gFramework.CreateMonster(1); 
        SetTimer(hWnd, 1, 100, NULL);
        return 0;
    break;

    case WM_TIMER:
        switch (wParam)
        {
        case 1:
            // 몬스터 애니메이션 틱
            for (int i = 0; i < STAGE_ONE_MONSTER; ++i)
            {
                if (gFramework.GetGameObject() != nullptr)
                {
                    gFramework.GetGameObject()[i].SetmBitMapAnim((gFramework.GetGameObject()[i].GetBitMapAnim() + 1 )% 5);
                }
            }
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }


    case WM_PAINT:
        hDC = BeginPaint(hWnd, &ps);
        memdc = CreateCompatibleDC(hDC);

        //if (round == 1)
        {
            for (int i = 0; i < STAGE_ONE_MONSTER; ++i)
            if (gFramework.GetGameObject() != nullptr) gFramework.GetGameObject()[i].DrawBitmap(hDC, memdc, gFramework.GetGameObject()[i].GetBitMapAnim());
        }
     /*
     hBrush = CreateSolidBrush(RGB(255, 255, 255));
     oldhBrush = (HBRUSH)SelectObject(hDC, hBrush);
       Rectangle(hDC, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
     SelectObject(hDC, hBrush);
     DeleteObject(hBrush);
     */



        EndPaint(hWnd, &ps);
        break;
    case WM_DESTROY:
        //wndCount--;
        //if (wndCount == 0) {
            PostQuitMessage(0);
        //}
        return 0;
    break;
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
        return 0;
    case WM_CHAR:
      
        break;

    case WM_TIMER:
        switch (wParam)
        {
        case 1:
            for (size_t i = 0; i < m_count[stage_count]; i++)
            {
                if (monster[stage_count][i].Stats == 1) SetTimer(hWnd, 3, 50, NULL);
            }
            break;

        case 3:
            /*for (size_t i = 0; i < m_count[stage_count]; i++)
            {
                switch (monster[stage_count][i].ActionFrame++)
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
            }*/
           
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
