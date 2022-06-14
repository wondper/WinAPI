#include "GFramework.h"
GFramework::GFramework()
{
    InitWCX(WINDOW::BackGround);
    InitWCX(WINDOW::Main);
    InitWCX(WINDOW::UI);

    gFramework.RegisterWnd();
}

GFramework::~GFramework()
{
}

void GFramework::Init()
{
    for (int i = 0; i < 6; ++i)
    {
        mCake[i].Initialize();
        mMegazine[i].Initialize();
        mScope[i].Initialize();
        mZombie[i].Initialize();
        mBee[i].Initialize();
        mBoss[i].Initialize();
    }
    CreateObject();

    //Round Set
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
    }

}

void GFramework::RegisterWnd()
{
    RegisterClassEx(&mwcxBackGround);
    RegisterClassEx(&mwcxMain);
    RegisterClassEx(&mwcxUI);
}

void GFramework::ShowBGWnd(int nCmdShow)
{
    hwndBG = CreateWindowEx(WS_EX_LAYERED | WS_EX_TOOLWINDOW, L"BackGroundWindow", L"BackGround", WS_VISIBLE, 0, 0,
        GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), nullptr, nullptr, mhInstance, nullptr);
    SetLayeredWindowAttributes(hwndBG, RGB(0, 0, 0), 0, LWA_COLORKEY);
    ShowWindow(hwndBG, nCmdShow);
}

void GFramework::ShowMainWnd(int nCmdShow)
{
    hwndMain = CreateWindow(L"MainWindow", L"Main", NULL, 0, 0, 200, 200, NULL, NULL, mhInstance, NULL);
    ShowWindow(hwndMain, nCmdShow);
}

void GFramework::ShowUIWnd(int nCmdShow)
{
    hwndUI = CreateWindow(L"UIWindow", L"UI", NULL, 0, GetSystemMetrics(SM_CYSCREEN) - 250, GetSystemMetrics(SM_CXSCREEN), 250, NULL, NULL, mhInstance, NULL);
    ShowWindow(hwndUI, nCmdShow);
}

void GFramework::ShowWnd(int nCmdShow)
{
    ShowBGWnd(nCmdShow);
    ShowMainWnd(nCmdShow);
    ShowUIWnd(nCmdShow);
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
void GFramework::CreateObject()
{
    int Sprite[6];

    for (size_t i = 0; i < 6; i++)
    {
        Sprite[i] = IDB_ITEM_CAKE;
    }

    for (size_t i = 0; i < 6; i++)
    {
        mCake[i].SetBitmap(Sprite);
    }

    for (size_t i = 0; i < 6; i++)
    {
        Sprite[i] = IDB_ITEM_MAGAZINE;
    }

    for (size_t i = 0; i < 6; i++)
    {
        mMegazine[i].SetBitmap(Sprite);
    }

    for (size_t i = 0; i < 6; i++)
    {
        Sprite[i] = IDB_ITEM_SCOPE;
    }

    for (size_t i = 0; i < 6; i++)
    {
        mScope[i].SetBitmap(Sprite);
    }


    Sprite[0] = IDB_MONSTER_ZOMBIE1;
    Sprite[1] = IDB_MONSTER_ZOMBIE2;
    Sprite[2] = IDB_MONSTER_ZOMBIE3;
    Sprite[3] = IDB_MONSTER_ZOMBIE4;
    Sprite[4] = IDB_MONSTER_ZOMBIE5;
    Sprite[5] = IDB_MONSTER_ZOMBIE6;

    for (size_t i = 0; i < 6; i++)
    {
        mZombie[i].SetBitmap(Sprite);
    }

    Sprite[0] = IDB_MONSTER_BEE1;
    Sprite[1] = IDB_MONSTER_BEE2;
    Sprite[2] = IDB_MONSTER_BEE3;
    Sprite[3] = IDB_MONSTER_BEE4;
    Sprite[4] = IDB_MONSTER_BEE5;
    Sprite[5] = IDB_MONSTER_BEE6;

    for (size_t i = 0; i < 6; i++)
    {
        mBee[i].SetBitmap(Sprite);
    }

    Sprite[0] = IDB_MONSTER_BOSS1;
    Sprite[1] = IDB_MONSTER_BOSS2;
    Sprite[2] = IDB_MONSTER_BOSS3;
    Sprite[3] = IDB_MONSTER_BOSS4;
    Sprite[4] = IDB_MONSTER_BOSS5;
    Sprite[5] = IDB_MONSTER_BOSS6;

    for (size_t i = 0; i < 6; i++)
    {
        mBoss[i].SetBitmap(Sprite);
    }

}


bool MouseCollisionCheck(int Mx, int My, int left, int top, int right, int bottom)
{
    if (left < Mx && Mx < right && top < My && My < bottom)
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

    static POINT AimPosition{ 0,0 };
    static int AimWidth;
    static int AimHeight;

    BITMAP bmp;

    switch (message)
    {

    case WM_CREATE:
        GetClientRect(hWnd, &rectView);

        AimBit = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_PLAY_AIM));
        GetObject(AimBit, sizeof(BITMAP), &bmp);
        AimWidth = bmp.bmWidth;
        AimHeight = bmp.bmHeight;
        BG_MAP = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BG1_STAGE));
        SetTimer(hWnd, 4, 3000, NULL); // 3초마다 탄알 1개 충전
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
                SetWindowPos(hWnd, NULL, User.GetPosition().x, User.GetPosition().y, User.GetWinSizeX(), User.GetWinSizeY(), NULL);

                InvalidateRect(hWnd, NULL, TRUE);
            }
            break;

        case 'a':
            if (User.GetPosition().x - FRAME_SPEED > 0)
            {
                User.SetPositionX(User.GetPosition().x - FRAME_SPEED);
                SetWindowPos(hWnd, NULL, User.GetPosition().x, User.GetPosition().y, User.GetWinSizeX(), User.GetWinSizeY(), NULL);

                InvalidateRect(hWnd, NULL, TRUE);
            }
            break;
        case 's':
            if (User.GetPosition().y + FRAME_SPEED < GetSystemMetrics(SM_CYSCREEN) - 200 - User.GetWinSizeY())
            {
                User.SetPositionY(User.GetPosition().y + FRAME_SPEED);
                SetWindowPos(hWnd, NULL, User.GetPosition().x, User.GetPosition().y, User.GetWinSizeX(), User.GetWinSizeY(), NULL);

                InvalidateRect(hWnd, NULL, TRUE);
            }
            break;
        case 'd':
            if (User.GetPosition().x + FRAME_SPEED < GetSystemMetrics(SM_CXSCREEN) - User.GetWinSizeX())
            {
                User.SetPositionX(User.GetPosition().x + FRAME_SPEED);
                SetWindowPos(hWnd, NULL, User.GetPosition().x, User.GetPosition().y, User.GetWinSizeX(), User.GetWinSizeY(), NULL);
                InvalidateRect(hWnd, NULL, TRUE);
            }
            break;
        }
        rectView = { User.GetPosition().x + 10, User.GetPosition().y + 40,
            User.GetPosition().x + User.GetWinSizeX() - 10, User.GetPosition().y + User.GetWinSizeY() - 10 };
        ClipCursor(&rectView);

        User.SetRect(User.GetPosition().x, User.GetPosition().y, User.GetPosition().x + AIMSIZEX, User.GetPosition().y + AIMSIZEY);
        break;


    case WM_MOUSEMOVE:
    {
        AimPosition = { LOWORD(lParam) ,HIWORD(lParam) };
        InvalidateRect(hWnd, NULL, TRUE);
    }
    break;

    case WM_LBUTTONDOWN:
    {
        User.DecreaseBulletCount();
        int ICount[MAX_OBJECT_KIND];
        int round = gFramework.GetRound();
        switch (round)
        {
        case 1:
        {
            int Count[6] = { 3, 3, 2, STAGE_ONE_ZOMBIE, 0, 0 };
            for (int i = 0; i < 6; ++i)
                ICount[i] = Count[i];
        }
        break;
        case 2:
        {
            int Count[6] = { 3, 3, 2, STAGE_TWO_ZOMBIE, STAGE_TWO_BEE, 0 };
            for (int i = 0; i < 6; ++i)
                ICount[i] = Count[i];
        }
        break;
        case 3:
        {
            int Count[6] = { 3, 3, 2, STAGE_THREE_ZOMBIE, STAGE_THREE_BEE, 1 };
            for (int i = 0; i < 6; ++i)
                ICount[i] = Count[i];
        }
        break;
        default:
        {
            int Count[6] = { 3, 3, 2, 3, 3, 1 };
            for (int i = 0; i < 6; ++i)
                ICount[i] = Count[i];
        }
        break;
        }

        for (size_t j = 0; j < STAGE_FIXED_OBJECT_KIND + round; ++j)
        {
            switch (j)
            {
            case CAKE:
                for (size_t i = 0; i < ICount[j]; i++)
                {
                    if (MouseCollisionCheck(User.GetPosition().x + LOWORD(lParam), User.GetPosition().y + HIWORD(lParam)
                        , gFramework.GetCake()[i].GetPosition().x, gFramework.GetCake()[i].GetPosition().y,
                        gFramework.GetCake()[i].GetPosition().x + gFramework.GetCake()[i].GetWidth(),
                        gFramework.GetCake()[i].GetPosition().y + gFramework.GetCake()[i].GetHeight()))
                    {
                        if (gFramework.GetCake()[i].GetState() != OBJECT_DELETE)
                        {
                            User.SetHP(User.GetHP() + 100);
                            gFramework.GetCake()[i].SetState(OBJECT_DELETE);
                           
                        }
                    }

                }

                break;
            case MEGAZINE:
                for (size_t i = 0; i < ICount[j]; i++)
                {
                    if (MouseCollisionCheck(User.GetPosition().x + LOWORD(lParam), User.GetPosition().y + HIWORD(lParam)
                        , gFramework.GetMegazine()[i].GetPosition().x, gFramework.GetMegazine()[i].GetPosition().y,
                        gFramework.GetMegazine()[i].GetPosition().x + gFramework.GetMegazine()[i].GetWidth(),
                        gFramework.GetMegazine()[i].GetPosition().y + gFramework.GetMegazine()[i].GetHeight()))
                    {
                        if (gFramework.GetMegazine()[i].GetState() != OBJECT_DELETE)
                        {
                            if (User.GetBullet() < 10)User.SetBullet(User.GetBullet() + 2);
                            User.SetScore(User.GetScore() + 30);

                            gFramework.GetMegazine()[i].SetState(OBJECT_DELETE);
                        }
                    }
                }
                break;

            case SCOPE:
                for (size_t i = 0; i < ICount[j]; i++)
                {
                    if (MouseCollisionCheck(User.GetPosition().x + LOWORD(lParam), User.GetPosition().y + HIWORD(lParam)
                        , gFramework.GetScope()[i].GetPosition().x, gFramework.GetScope()[i].GetPosition().y,
                        gFramework.GetScope()[i].GetPosition().x + gFramework.GetScope()[i].GetWidth(),
                        gFramework.GetScope()[i].GetPosition().y + gFramework.GetScope()[i].GetHeight()))
                    {
                        if (gFramework.GetScope()[i].GetState() != OBJECT_DELETE)
                        {
                            User.SetPosition(User.GetPosition().x - 20, User.GetPosition().y - 10);
                            User.SetWinSizeX(User.GetWinSizeX() + 40);   User.SetWinSizeY(User.GetWinSizeY() + 20);
                            SetWindowPos(hWnd, NULL, User.GetPosition().x, User.GetPosition().y, User.GetWinSizeX(), User.GetWinSizeY(), NULL);

                            rectView = { User.GetPosition().x + 10, User.GetPosition().y + 40,
                                User.GetPosition().x + User.GetWinSizeX() - 10, User.GetPosition().y + User.GetWinSizeY() - 10 };
                            ClipCursor(&rectView);

                            User.SetScore(User.GetScore() + 30);
                            User.SetRect(User.GetPosition().x, User.GetPosition().y, User.GetPosition().x + AIMSIZEX, User.GetPosition().y + AIMSIZEY);
                            gFramework.GetScope()[i].SetState(OBJECT_DELETE);
                        }
                    }
                }
                break;

            case ZOMBIE:
                for (size_t i = 0; i < ICount[j]; i++)
                {
                    if (MouseCollisionCheck(User.GetPosition().x + LOWORD(lParam), User.GetPosition().y + HIWORD(lParam)
                        , gFramework.GetZombie()[i].GetPosition().x, gFramework.GetZombie()[i].GetPosition().y,
                        gFramework.GetZombie()[i].GetPosition().x + gFramework.GetZombie()[i].GetWidth(),
                        gFramework.GetZombie()[i].GetPosition().y + gFramework.GetZombie()[i].GetHeight()))
                    {
                        if (gFramework.GetZombie()[i].GetState() != OBJECT_DELETE)
                        {
                            gFramework.GetZombie()[i].SetHP(gFramework.GetZombie()[i].GetHP() - 1);

                            if (gFramework.GetZombie()[i].GetHP() > 0) // HP 가 남아있으면 HIT 상태 처리
                            { 
                                gFramework.GetZombie()[i].SetState(MONSTER_HIT);
                                gFramework.GetZombie()[i].SetBitMapAnim(0);
                            }
                            else  // HP 가 0이면 DELETE상태 처리
                            {
                                gFramework.GetZombie()[i].SetState(MONSTER_DEATH);
                                gFramework.GetZombie()[i].SetBitMapAnim(0);
                            }
                        }
                    }
                }
                break;

            case BEE:
                for (size_t i = 0; i < ICount[j]; i++)
                {
                    if (MouseCollisionCheck(User.GetPosition().x + LOWORD(lParam), User.GetPosition().y + HIWORD(lParam)
                        , gFramework.GetBee()[i].GetPosition().x, gFramework.GetBee()[i].GetPosition().y,
                        gFramework.GetBee()[i].GetPosition().x + gFramework.GetBee()[i].GetWidth(),
                        gFramework.GetBee()[i].GetPosition().y + gFramework.GetBee()[i].GetHeight()))
                    {
                        if (gFramework.GetBee()[i].GetState() != OBJECT_DELETE)
                        {
                            gFramework.GetBee()[i].SetHP(gFramework.GetBee()[i].GetHP() - 1);

                            if (gFramework.GetBee()[i].GetHP() > 0) // HP 가 남아있으면 HIT 상태 처리
                            {

                                gFramework.GetBee()[i].SetState(MONSTER_HIT);
                                gFramework.GetBee()[i].SetBitMapAnim(0);
                            }
                            else  // HP 가 0이면 DELETE상태 처리
                            {
                                gFramework.GetBee()[i].SetState(MONSTER_DEATH);
                                gFramework.GetBee()[i].SetBitMapAnim(0);
                            }
                        }
                    }
                }
                break;

            case BOSS:
                for (size_t i = 0; i < ICount[j]; i++)
                {
                    if (MouseCollisionCheck(User.GetPosition().x + LOWORD(lParam), User.GetPosition().y + HIWORD(lParam)
                        , gFramework.GetBoss()[i].GetPosition().x, gFramework.GetBoss()[i].GetPosition().y,
                        gFramework.GetBoss()[i].GetPosition().x + gFramework.GetBoss()[i].GetWidth(),
                        gFramework.GetBoss()[i].GetPosition().y + gFramework.GetBoss()[i].GetHeight()))
                    {
                        if (gFramework.GetBoss()[i].GetState() != OBJECT_DELETE)
                        {
                            gFramework.GetBoss()[i].SetHP(gFramework.GetBoss()[i].GetHP() - 1);

                            if (gFramework.GetBoss()[i].GetHP() > 0) // HP 가 남아있으면 HIT 상태 처리
                            {

                                gFramework.GetBoss()[i].SetState(MONSTER_HIT);
                                gFramework.GetBoss()[i].SetBitMapAnim(0);
                            }
                            else  // HP 가 0이면 DELETE상태 처리
                            {
                                gFramework.GetBoss()[i].SetState(MONSTER_DEATH);
                                gFramework.GetBoss()[i].SetBitMapAnim(0);
                            }
                        }
                    }
                }
                break;
            }


        }

        Triger = true;
        SetTimer(hwndMain, 3, 10, NULL);
    }

    InvalidateRect(hwndBG, NULL, TRUE); // UI핸들을 보냄.
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
                    SetWindowPos(hWnd, NULL, User.GetPosition().x - 5, User.GetPosition().y + 5, User.GetWinSizeX() - 5, User.GetWinSizeY() + 5, NULL);
                    break;
                case 1:
                    SetWindowPos(hWnd, NULL, User.GetPosition().x, User.GetPosition().y - 5, User.GetWinSizeX(), User.GetWinSizeY(), NULL);
                    break;
                case 2:
                    SetWindowPos(hWnd, NULL, User.GetPosition().x + 5, User.GetPosition().y, User.GetWinSizeX(), User.GetWinSizeY(), NULL);
                    break;
                case 3:
                    SetWindowPos(hWnd, NULL, User.GetPosition().x - 5, User.GetPosition().y - 5, User.GetWinSizeX(), User.GetWinSizeY(), NULL);
                    break;
                case 4:
                    SetWindowPos(hWnd, NULL, User.GetPosition().x, User.GetPosition().y + 5, User.GetWinSizeX(), User.GetWinSizeY(), NULL);
                    break;
                case 5:
                    SetWindowPos(hWnd, NULL, User.GetPosition().x + 5, User.GetPosition().y + 5, User.GetWinSizeX(), User.GetWinSizeY(), NULL);
                    break;
                case 6:
                    SetWindowPos(hWnd, NULL, User.GetPosition().x, User.GetPosition().y, User.GetWinSizeX(), User.GetWinSizeY(), NULL);
                    Trigerframe = 0;
                    Triger = false;
                    KillTimer(hWnd, 3);
                    break;
                }
            }
            InvalidateRect(hwndMain, NULL, TRUE); // UI핸들을 보냄.

            break;

        case 4:
            if (User.GetBullet() < 9)
                User.SetBullet(User.GetBullet() + 1);
            InvalidateRect(hwndUI, NULL, TRUE); 


            break;
        }

        break;
    case WM_PAINT:
    {
        hDC = BeginPaint(hWnd, &ps);
        gFramework.Draw(hDC);
        memdc = CreateCompatibleDC(hDC);
        SelectObject(memdc, BG_MAP);
        StretchBlt(hDC, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), memdc, User.GetPosition().x, User.GetPosition().y,
            GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SRCCOPY);

        int ICount[MAX_OBJECT_KIND] = { 3, 3, 2, 3, 3, 3 };
        int round = gFramework.GetRound();
        switch (round)
        {
        case 1:
        {
            int Count[6] = { 3, 3, 2, STAGE_ONE_ZOMBIE, 0, 0 };
            for (int i = 0; i < 6; ++i)
                ICount[i] = Count[i];
        }
        break;
        case 2:
        {
            int Count[6] = { 3, 3, 2, STAGE_TWO_ZOMBIE, STAGE_TWO_BEE, 0 };
            for (int i = 0; i < 6; ++i)
                ICount[i] = Count[i];
        }
        break;
        case 3:
        {
            int Count[6] = { 3, 3, 2, STAGE_THREE_ZOMBIE, STAGE_THREE_BEE, 1 };
            for (int i = 0; i < 6; ++i)
                ICount[i] = Count[i];
        }
        break;
        default:
        {
            int Count[6] = { 3, 3, 2, 3, 3, 1 };
            for (int i = 0; i < 6; ++i)
                ICount[i] = Count[i];
        }
        break;
        }

         for (int j = STAGE_FIXED_OBJECT_KIND + round; j > -1; --j)  // 전부 돎
         {
             for (int i = ICount[j] - 1; i > -1; --i) // ICount까지
             {
                 switch (j)
                {
                case CAKE:

                    if (BoxCollisionCheck(User.GetPosition().x, User.GetPosition().y, User.GetPosition().x + User.GetWinSizeX(), User.GetPosition().y + User.GetWinSizeY(),
                        gFramework.GetCake()[i].GetPosition().x, gFramework.GetCake()[i].GetPosition().y,
                        gFramework.GetCake()[i].GetPosition().x + gFramework.GetCake()[i].GetWidth(),
                        gFramework.GetCake()[i].GetPosition().y + gFramework.GetCake()[i].GetHeight()))
                    {
                        if (gFramework.GetCake()[i].GetState() != OBJECT_DELETE)
                            gFramework.GetCake()[i].DrawPlayerWindow(hDC, memdc, gFramework.GetCake()[i].GetBitMapAnim(), User.GetPosition().x, User.GetPosition().y,
                            User.GetPosition().x + User.GetWinSizeX(), User.GetPosition().y + User.GetWinSizeY(), gFramework.GetCake()[i].GetState());
                    }
                    break;

                case MEGAZINE:
                    if (BoxCollisionCheck(User.GetPosition().x, User.GetPosition().y, User.GetPosition().x + User.GetWinSizeX(), User.GetPosition().y + User.GetWinSizeY(),
                        gFramework.GetMegazine()[i].GetPosition().x, gFramework.GetMegazine()[i].GetPosition().y,
                        gFramework.GetMegazine()[i].GetPosition().x + gFramework.GetMegazine()[i].GetWidth(),
                        gFramework.GetMegazine()[i].GetPosition().y + gFramework.GetMegazine()[i].GetHeight()))
                    {
                        if (gFramework.GetMegazine()[i].GetState() != OBJECT_DELETE)
                            gFramework.GetMegazine()[i].DrawPlayerWindow(hDC, memdc, gFramework.GetMegazine()[i].GetBitMapAnim(), User.GetPosition().x, User.GetPosition().y,
                            User.GetPosition().x + User.GetWinSizeX(), User.GetPosition().y + User.GetWinSizeY(), gFramework.GetMegazine()[i].GetState());
                    }
                    break;
                case SCOPE:

                    if (BoxCollisionCheck(User.GetPosition().x, User.GetPosition().y, User.GetPosition().x + User.GetWinSizeX(), User.GetPosition().y + User.GetWinSizeY(),
                        gFramework.GetScope()[i].GetPosition().x, gFramework.GetScope()[i].GetPosition().y,
                        gFramework.GetScope()[i].GetPosition().x + gFramework.GetScope()[i].GetWidth(),
                        gFramework.GetScope()[i].GetPosition().y + gFramework.GetScope()[i].GetHeight()))
                    {
                        if (gFramework.GetScope()[i].GetState() != OBJECT_DELETE)
                            gFramework.GetScope()[i].DrawPlayerWindow(hDC, memdc, gFramework.GetScope()[i].GetBitMapAnim(), User.GetPosition().x, User.GetPosition().y,
                            User.GetPosition().x + User.GetWinSizeX(), User.GetPosition().y + User.GetWinSizeY(), gFramework.GetScope()[i].GetState());
                    }
                    break;

                case ZOMBIE:
                    if (BoxCollisionCheck(User.GetPosition().x, User.GetPosition().y, User.GetPosition().x + User.GetWinSizeX(), User.GetPosition().y + User.GetWinSizeY(),
                        gFramework.GetZombie()[i].GetPosition().x, gFramework.GetZombie()[i].GetPosition().y,
                        gFramework.GetZombie()[i].GetPosition().x + gFramework.GetZombie()[i].GetWidth(),
                        gFramework.GetZombie()[i].GetPosition().y + gFramework.GetZombie()[i].GetHeight()))
                    {
                        if (gFramework.GetZombie()[i].GetState() != OBJECT_DELETE)
                            gFramework.GetZombie()[i].DrawPlayerWindow(hDC, memdc, gFramework.GetZombie()[i].GetBitMapAnim(), User.GetPosition().x, User.GetPosition().y,
                            User.GetPosition().x + User.GetWinSizeX(), User.GetPosition().y + User.GetWinSizeY(), gFramework.GetZombie()[i].GetState());
                    }
                    break;

                case BEE:
                    if (BoxCollisionCheck(User.GetPosition().x, User.GetPosition().y, User.GetPosition().x + User.GetWinSizeX(), User.GetPosition().y + User.GetWinSizeY(),
                        gFramework.GetBee()[i].GetPosition().x, gFramework.GetBee()[i].GetPosition().y,
                        gFramework.GetBee()[i].GetPosition().x + gFramework.GetBee()[i].GetWidth(),
                        gFramework.GetBee()[i].GetPosition().y + gFramework.GetBee()[i].GetHeight()))
                    {
                        if (gFramework.GetBee()[i].GetState() != OBJECT_DELETE)
                            gFramework.GetBee()[i].DrawPlayerWindow(hDC, memdc, gFramework.GetBee()[i].GetBitMapAnim(), User.GetPosition().x, User.GetPosition().y,
                            User.GetPosition().x + User.GetWinSizeX(), User.GetPosition().y + User.GetWinSizeY(), gFramework.GetBee()[i].GetState());
                    }
                    break;

                case BOSS:
                    if (BoxCollisionCheck(User.GetPosition().x, User.GetPosition().y, User.GetPosition().x + User.GetWinSizeX(), User.GetPosition().y + User.GetWinSizeY(),
                        gFramework.GetBoss()[i].GetPosition().x, gFramework.GetBoss()[i].GetPosition().y,
                        gFramework.GetBoss()[i].GetPosition().x + gFramework.GetBoss()[i].GetWidth(),
                        gFramework.GetBoss()[i].GetPosition().y + gFramework.GetBoss()[i].GetHeight()))
                    {
                        if (gFramework.GetBoss()[i].GetState() != OBJECT_DELETE)
                            gFramework.GetBoss()[i].DrawPlayerWindow(hDC, memdc, gFramework.GetBoss()[i].GetBitMapAnim(), User.GetPosition().x, User.GetPosition().y,
                            User.GetPosition().x + User.GetWinSizeX(), User.GetPosition().y + User.GetWinSizeY(), gFramework.GetBoss()[i].GetState());
                    }
                    break;


                }
            }
        }

        SelectObject(memdc, AimBit);
        TransparentBlt(hDC, AimPosition.x - AimWidth / 4, AimPosition.y - AimHeight / 4, AimWidth / 2, AimHeight / 2, memdc, 0, 0, 134, 134, RGB(0, 255, 0));


        DeleteDC(memdc);
        EndPaint(hWnd, &ps);
        return 0;
    }
    break;


    case WM_DESTROY:
        PostQuitMessage(0);
      
        return 0;

    }
    return DefWindowProc(hWnd, message, wParam, lParam);

}

LRESULT CALLBACK UIWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hDC, memDC;
    PAINTSTRUCT ps;
    HBRUSH hBrush, oldhBrush;

    static HBITMAP mBitMap_Magazine;
    static HBITMAP mBitMap_BackGround;
    static HBITMAP oldBit;

    switch (message) {

    case WM_CREATE:
        mBitMap_Magazine = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_UI_BULLET));
        mBitMap_BackGround = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_UI_BACKGROUND));

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

        oldBit = (HBITMAP)SelectObject(memDC, mBitMap_BackGround);
        BitBlt(hDC, 0, 0, 1300, 450, memDC, 0, 0, SRCCOPY);


        oldBit = (HBITMAP)SelectObject(memDC, mBitMap_Magazine);
        //BulletText Set, TextOut
        User.SetBulletstr();
        for (int i = 0; i < User.GetBullet(); i++)
        {
            TransparentBlt(hDC, 280 + i * 11, 160, 10, 50, memDC, 0, 0, 9, 46, RGB(0, 255, 0));
        }
        SelectObject(memDC, oldBit);
        DeleteDC(memDC);

        hBrush = CreateSolidBrush(RGB(148, 228, 241));
        oldhBrush = (HBRUSH)SelectObject(hDC, hBrush);
        Rectangle(hDC, 310, 65, 310 + User.GetHP() * 1.2, 95);

        //Score Text Set, TextOut
        User.SetScorestr();
        TextOut(hDC, 300, 230, User.GetScoreStr().c_str(), static_cast<int>(User.GetScoreStr().size()));



        SelectObject(hDC, hBrush);
        DeleteObject(hBrush);

        EndPaint(hWnd, &ps);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT CALLBACK BackGroundWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hDC, memdc, mem1dc;

    PAINTSTRUCT ps;
    HBRUSH hBrush, oldhBrush;

    static int CreateTime = 0;

    int ICount[MAX_OBJECT_KIND];
    int round = gFramework.GetRound();
    static int answer;
    switch (message)
    {

    case WM_CREATE:
    {
        int Round = 0;
        SetTimer(hWnd, 1, 100, NULL);
        SetTimer(hWnd, 2, 1000, NULL); //

        SetTimer(hWnd, 3, 1000, NULL); // 쿨타임 감소틱
     

    }
    break;

    case WM_TIMER:
        switch (wParam)
        {
        case 1:
            switch (round)
            {
            case 1:
            {
                int Count[6] = { 3, 3, 2, STAGE_ONE_ZOMBIE, 0, 0 };
                for (int i = 0; i < 6; ++i)
                    ICount[i] = Count[i];
            }
            break;
            case 2:
            {
                int Count[6] = { 3, 3, 2, STAGE_TWO_ZOMBIE, STAGE_TWO_BEE, 0 };
                for (int i = 0; i < 6; ++i)
                    ICount[i] = Count[i];
            }
            break;
            case 3:
            {
                int Count[6] = { 3, 3, 2, STAGE_THREE_ZOMBIE, STAGE_THREE_BEE, 1 };
                for (int i = 0; i < 6; ++i)
                    ICount[i] = Count[i];
            }
            break;
            default:
            {
                int Count[6] = { 3, 3, 2, 3, 3, 1 };
                for (int i = 0; i < 6; ++i)
                    ICount[i] = Count[i];
            }
            break;
            }
            for (int j = 0; j < MAX_OBJECT_KIND; ++j)
            {
                for (int i = ICount[j] - 1; i > -1; --i) // ICount까지
                {
                    switch (j)
                    {
                    case ZOMBIE:
                        if (gFramework.GetZombie()[i].GetState() != OBJECT_DELETE)
                        {
                            gFramework.GetZombie()[i].SetBitMapAnim((gFramework.GetZombie()[i].GetBitMapAnim() + 1) % 6);
                        }
                        break;

                    case BEE:
                        if (gFramework.GetBee()[i].GetState() != OBJECT_DELETE)
                        {
                            gFramework.GetBee()[i].SetBitMapAnim((gFramework.GetBee()[i].GetBitMapAnim() + 1) % 6);
                        }
                        break;

                    case BOSS:
                        if (gFramework.GetBoss()[i].GetState() != OBJECT_DELETE)
                        {
                            gFramework.GetBoss()[i].SetBitMapAnim((gFramework.GetBoss()[i].GetBitMapAnim() + 1) % 6);
                        }
                        break;
                    }

                }
            }
            InvalidateRect(hWnd, NULL, TRUE);
            InvalidateRect(hwndMain, NULL, TRUE);
            break;

        case 2:
            CreateTime++;
            // 게임 시작시 오브젝트 등장 틱
            // 2초후 사라짐
            if (CreateTime)
            {
                switch (round)
                {
                case 1:
                {
                    int Count[6] = { 3, 3, 2, STAGE_ONE_ZOMBIE, 0, 0 };
                    for (int i = 0; i < 6; ++i)
                        ICount[i] = Count[i];
                }
                break;
                case 2:
                {
                    int Count[6] = { 3, 3, 2, STAGE_TWO_ZOMBIE, STAGE_TWO_BEE, 0 };
                    for (int i = 0; i < 6; ++i)
                        ICount[i] = Count[i];
                }
                break;
                case 3:
                {
                    int Count[6] = { 3, 3, 2, STAGE_THREE_ZOMBIE, STAGE_THREE_BEE, 1 };
                    for (int i = 0; i < 6; ++i)
                        ICount[i] = Count[i];
                }
                break;
                default:
                {
                    int Count[6] = { 3, 3, 2, 3, 3, 1 };
                    for (int i = 0; i < 6; ++i)
                        ICount[i] = Count[i];
                }
                break;
                }
                for (int j = 0; j < STAGE_FIXED_OBJECT_KIND + round; ++j)
                {
                    for (int i = ICount[j] - 1; i > -1; --i) // ICount까지
                    {
                        switch (j)
                        {
                        case CAKE:
                            if (gFramework.GetCake()[i].GetState() != OBJECT_DELETE && gFramework.GetCake()[i].GetState() != OBJECT_NOT_DRAW)
                            {
                                gFramework.GetCake()[i].SetState(OBJECT_NOT_DRAW);
                            }
                            break;

                        case MEGAZINE:
                            if (gFramework.GetMegazine()[i].GetState() != OBJECT_DELETE && gFramework.GetMegazine()[i].GetState() != OBJECT_NOT_DRAW)
                            {
                                gFramework.GetMegazine()[i].SetState(OBJECT_NOT_DRAW);
                            }
                            break;

                        case SCOPE:
                            if (gFramework.GetScope()[i].GetState() != OBJECT_DELETE && gFramework.GetScope()[i].GetState() != OBJECT_NOT_DRAW)
                            {
                                gFramework.GetScope()[i].SetState(OBJECT_NOT_DRAW);
                            }
                            break;

                        case ZOMBIE:
                            if (gFramework.GetZombie()[i].GetState() != OBJECT_DELETE && gFramework.GetZombie()[i].GetState() != OBJECT_NOT_DRAW)
                            {
                                gFramework.GetZombie()[i].SetState(OBJECT_NOT_DRAW);
                            }
                            break;

                        case BEE:
                            if (gFramework.GetBee()[i].GetState() != OBJECT_DELETE && gFramework.GetBee()[i].GetState() != OBJECT_NOT_DRAW)
                            {
                                gFramework.GetBee()[i].SetState(OBJECT_NOT_DRAW);
                            }
                            break;

                        case BOSS:
                            if (gFramework.GetBoss()[i].GetState() != OBJECT_DELETE && gFramework.GetBoss()[i].GetState() != OBJECT_NOT_DRAW)
                            {
                                gFramework.GetBoss()[i].SetState(OBJECT_NOT_DRAW);
                            }
                            break;
                        }

                    }
                }
                CreateTime = 0;
                KillTimer(hWnd, 2);
            }
            break;



        case 3:
            switch (round)
            {
            case 1:
            {
                int Count[6] = { 3, 3, 2, STAGE_ONE_ZOMBIE, 0, 0 };
                for (int i = 0; i < 6; ++i)
                    ICount[i] = Count[i];
            }
            break;
            case 2:
            {
                int Count[6] = { 3, 3, 2, STAGE_TWO_ZOMBIE, STAGE_TWO_BEE, 0 };
                for (int i = 0; i < 6; ++i)
                    ICount[i] = Count[i];
            }
            break;
            case 3:
            {
                int Count[6] = { 3, 3, 2, STAGE_THREE_ZOMBIE, STAGE_THREE_BEE, 1 };
                for (int i = 0; i < 6; ++i)
                    ICount[i] = Count[i];
            }
            break;
            default:
            {
                int Count[6] = { 3, 3, 2, 3, 3, 1 };
                for (int i = 0; i < 6; ++i)
                    ICount[i] = Count[i];
            }
            break;
            }
            // 몬스터 공격 쿨타임 감소 틱
            for (int j = 0; j < STAGE_FIXED_OBJECT_KIND + round; ++j)
            {
                for (int i = ICount[j] - 1; i > -1; --i) // ICount까지
                {
                    switch (j)
                    {
                    case ZOMBIE:
                        if (gFramework.GetZombie()[i].GetState() != OBJECT_DELETE)
                        {
                            gFramework.GetZombie()[i].SetCoolTime(gFramework.GetZombie()[i].GetCoolTime()-1);
                            if (gFramework.GetZombie()[i].GetCoolTime() <= 0)
                            {
                                gFramework.GetZombie()[i].SetState(MONSTER_ATTACK);
                                User.SetHP(User.GetHP() - 30);
                                if (User.GetHP() <= 0) // 플레이어 사망시
                                {

                                }

                                gFramework.GetZombie()[i].SetCoolTime(8); // 8초마다 한번
                            }

                        }
                        break;

                    case BEE:
                        if (gFramework.GetBee()[i].GetState() != OBJECT_DELETE )
                        {
                            gFramework.GetBee()[i].SetCoolTime(gFramework.GetBee()[i].GetCoolTime() - 1);
                            if (gFramework.GetBee()[i].GetCoolTime() <= 0)
                            {
                                gFramework.GetBee()[i].SetState(MONSTER_ATTACK);
                                User.SetHP(User.GetHP() - 30);
                                if (User.GetHP() <= 0) // 플레이어 사망시
                                {

                                }

                                gFramework.GetBee()[i].SetCoolTime(5); // 5초마다 한번
                            }
                        }
                        break;

                    case BOSS:
                        if (gFramework.GetBoss()[i].GetState() != OBJECT_DELETE)
                        {
                            gFramework.GetBoss()[i].SetCoolTime(gFramework.GetBoss()[i].GetCoolTime() - 1);
                            if (gFramework.GetBoss()[i].GetCoolTime() <= 0)
                            {
                                gFramework.GetBoss()[i].SetState(MONSTER_ATTACK);
                                User.SetHP(User.GetHP() - 30);
                                if (User.GetHP() <= 0) // 플레이어 사망시
                                {

                                }

                                gFramework.GetBoss()[i].SetCoolTime(10); 
                            }
                        }
                        break;
                    }

                }
            }
            InvalidateRect(hWnd, NULL, TRUE);
            InvalidateRect(hwndMain, NULL, TRUE);

            break;
        }


    case WM_PAINT:
    {
        hDC = BeginPaint(hWnd, &ps);
        memdc = CreateCompatibleDC(hDC);
        int ICount[MAX_OBJECT_KIND] = { 3, 3, 2, 3, 3, 1 };
        int round = 0;

        switch (round)
        {
        case 1:
        {
            int Count[6] = { 3, 3, 2, STAGE_ONE_ZOMBIE, 0, 0 };
            for (int i = 0; i < 6; ++i)
                ICount[i] = Count[i];
        }
        break;
        case 2:
        {
            int Count[6] = { 3, 3, 2, STAGE_TWO_ZOMBIE, STAGE_TWO_BEE, 0 };
            for (int i = 0; i < 6; ++i)
                ICount[i] = Count[i];
        }
        break;
        case 3:
        {
            int Count[6] = { 3, 3, 2, STAGE_THREE_ZOMBIE, STAGE_THREE_BEE, 1 };
            for (int i = 0; i < 6; ++i)
                ICount[i] = Count[i];
        }
        break;
        default:
        {
            int Count[6] = { 3, 3, 2, 3, 3, 1 };
            for (int i = 0; i < 6; ++i)
                ICount[i] = Count[i];
        }
        break;
        }


        for (int j = STAGE_FIXED_OBJECT_KIND + round; j > -1; --j)  // 전부 돎
        {
            for (int i = ICount[j] - 1; i > -1; --i) // ICount까지
            {
                switch (j)
                {
                case CAKE:
                    if (gFramework.GetCake()[i].GetState() != OBJECT_DELETE && gFramework.GetCake()[i].GetState() != OBJECT_NOT_DRAW)
                    {
                        gFramework.GetCake()[i].DrawBitmap(hDC, memdc, gFramework.GetCake()[i].GetBitMapAnim(), gFramework.GetCake()[i].GetState());
                    }
                    break;

                case MEGAZINE:
                    if (gFramework.GetMegazine()[i].GetState() != OBJECT_DELETE && gFramework.GetMegazine()[i].GetState() != OBJECT_NOT_DRAW)
                    {
                        gFramework.GetMegazine()[i].DrawBitmap(hDC, memdc, gFramework.GetMegazine()[i].GetBitMapAnim(), gFramework.GetMegazine()[i].GetState());
                    }
                    break;

                case SCOPE:
                    if (gFramework.GetScope()[i].GetState() != OBJECT_DELETE && gFramework.GetScope()[i].GetState() != OBJECT_NOT_DRAW)
                    {
                        gFramework.GetScope()[i].DrawBitmap(hDC, memdc, gFramework.GetScope()[i].GetBitMapAnim(), gFramework.GetScope()[i].GetState());
                    }
                    break;

                case ZOMBIE:
                    if (gFramework.GetZombie()[i].GetState() != OBJECT_DELETE && gFramework.GetZombie()[i].GetState() != OBJECT_NOT_DRAW)
                    {
                        gFramework.GetZombie()[i].DrawBitmap(hDC, memdc, gFramework.GetZombie()[i].GetBitMapAnim(), gFramework.GetZombie()[i].GetState());
                        if (gFramework.GetZombie()[i].GetBitMapAnim() >= 5)
                        {
                            switch (gFramework.GetZombie()[i].GetState())
                            {
                            case MONSTER_ATTACK:
                                gFramework.GetZombie()[i].SetState(OBJECT_NOT_DRAW);
                                break;

                            case MONSTER_HIT:
                                gFramework.GetZombie()[i].SetState(OBJECT_NOT_DRAW);
                                break;

                            case MONSTER_DEATH:
                                gFramework.GetZombie()[i].SetState(OBJECT_DELETE);
                                break;
                            }
                        }
                    }
                    break;

                case BEE:
                    if (gFramework.GetBee()[i].GetState() != OBJECT_DELETE && gFramework.GetBee()[i].GetState() != OBJECT_NOT_DRAW)
                    {
                        gFramework.GetBee()[i].DrawBitmap(hDC, memdc, gFramework.GetBee()[i].GetBitMapAnim(), gFramework.GetBee()[i].GetState());
                    }
                    break;

                case BOSS:
                    if (gFramework.GetBoss()[i].GetState() != OBJECT_DELETE && gFramework.GetBoss()[i].GetState() != OBJECT_NOT_DRAW)
                    {
                        gFramework.GetBoss()[i].DrawBitmap(hDC, memdc, gFramework.GetBoss()[i].GetBitMapAnim(), gFramework.GetBoss()[i].GetState());
                    }
                    break;
                }

            }
        }

        DeleteDC(memdc);

        EndPaint(hWnd, &ps);
    }
    break;


    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
