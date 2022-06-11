#include "GFramework.h"
GFramework::GFramework()
{
    
	//mhInstance = g_hInst;
    void* raw_memory = operator new[](static_cast<int>(OBJECT_TYPE{OBJECT_TYPE::END}) *sizeof(GameObject*));
    mGameObject = static_cast<GameObject**>(raw_memory);
    auto GameobjectKindNum = static_cast<int>(OBJECT_TYPE{ OBJECT_TYPE::END });
    for (int i = 0; i < GameobjectKindNum; ++i)
    {
        new(&mGameObject[i]) GameObject*;
    }
}

GFramework::~GFramework()
{
    /*void* raw_memory; raw_memory = operator new[](static_cast<int>(OBJECT_TYPE{ OBJECT_TYPE::END }) * sizeof(GameObject*));

    
    for (int i = 6 - 1; i >= 0; --i) {
        switch (mRound) 
        {
        case 0:
            raw_memory = operator new[](static_cast<int>(OBJECT_TYPE{ OBJECT_TYPE::END }) * sizeof(Cake*));
            mGameObject[i].~GameObject();
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        }
        }
        operator delete[](raw_memory);

    for (int i = 0; i < 6; ++i)
        delete[] mGameObject[i];
    delete[] mGameObject;*/
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
    /*case WINDOW::Monster:
        wcex.lpfnWndProc = MonsterWndProc;
        wcex.lpszClassName = L"MonsterGroundWindow";
        wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
        mwcxBackGround = wcex;
		break;*/
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

    SetLayeredWindowAttributes(hwndBG, RGB(0, 0, 0), 0, LWA_COLORKEY);
    ShowWindow(hwndBG, nCmdShow);

    //for (int i = 0; i < MAX_m; i++)
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
    SetRound(Round);
    int CakeSprite[6], MegazineSprite[6], ScopeSprite[6], ZombieSprite[6], BeeSprite[6], BossSprite[6];
    /*int RoundCake{}, RoundMegazine{}, RoundScope{};*/
    int RoundZombie{}, RoundBee{}, RoundBoss{};

    for (int i = 0; i < BITMAP_SPRITE_COUNT; ++i)
    {
        CakeSprite[i] = IDB_ITEM_CAKE;
        MegazineSprite[i] = IDB_ITEM_MAGAZINE;
        ScopeSprite[i] = IDB_ITEM_SCOPE;
    }

    void* raw_memory = operator new[](CAKE_COUNT * sizeof(Cake));
    mGameObject[0] = static_cast<Cake*>(raw_memory);
    for (int i = 0; i < CAKE_COUNT; ++i)
        new(&mGameObject[0][i]) Cake(CakeSprite);
    

    raw_memory = operator new[](MEGAZINE_COUNT * sizeof(Megazine));
    mGameObject[1] = static_cast<Megazine*>(raw_memory);
    for (int i = 0; i < MEGAZINE_COUNT; ++i)
        new(&mGameObject[1][i]) Megazine(MegazineSprite);
    
    raw_memory = operator new[](SCOPE_COUNT * sizeof(Scope));
    mGameObject[2] = static_cast<Scope*>(raw_memory);
    for (int i = 0; i < SCOPE_COUNT; ++i)
        new(&mGameObject[2][i]) Scope(ScopeSprite);

    switch (Round)
    {
    case 0: 
    {
        RoundZombie = STAGE_TEST_ZOMBIE;
        ZombieSprite[0] = IDB_MONSTER_ZOMBIE1;
        ZombieSprite[1] = IDB_MONSTER_ZOMBIE2;
        ZombieSprite[2] = IDB_MONSTER_ZOMBIE3;
        ZombieSprite[3] = IDB_MONSTER_ZOMBIE4;
        ZombieSprite[4] = IDB_MONSTER_ZOMBIE5;
        ZombieSprite[5] = IDB_MONSTER_ZOMBIE6;

        raw_memory = operator new[](RoundZombie * sizeof(Zombie));
        mGameObject[3] = static_cast<Zombie*>(raw_memory);
        for (int i = 0; i < RoundZombie; ++i)
            new(&mGameObject[3][i]) Zombie(ZombieSprite);

        RoundBee = STAGE_TEST_BEE;

        BeeSprite[0] = IDB_MONSTER_BEE1;
        BeeSprite[1] = IDB_MONSTER_BEE2;
        BeeSprite[2] = IDB_MONSTER_BEE3;
        BeeSprite[3] = IDB_MONSTER_BEE4;
        BeeSprite[4] = IDB_MONSTER_BEE5;
        BeeSprite[5] = IDB_MONSTER_BEE6;

        raw_memory = operator new[](RoundBee * sizeof(Bee));
        mGameObject[4] = static_cast<Bee*>(raw_memory);
        for (int i = 0; i < RoundBee; ++i)
            new(&mGameObject[4][i]) Bee(BeeSprite);

        RoundBoss = STAGE_TEST_BOSS;

        BossSprite[0] = IDB_MONSTER_BOSS1;
        BossSprite[1] = IDB_MONSTER_BOSS2;
        BossSprite[2] = IDB_MONSTER_BOSS3;
        BossSprite[3] = IDB_MONSTER_BOSS4;
        BossSprite[4] = IDB_MONSTER_BOSS5;
        BossSprite[5] = IDB_MONSTER_BOSS6;

       raw_memory = operator new[](RoundBoss * sizeof(Boss));
        mGameObject[5] = static_cast<Boss*>(raw_memory);
        for (int i = 0; i < RoundBoss; ++i)
            new(&mGameObject[5][i]) Boss(BossSprite);

    }
        break;
    case 1:
    {
        RoundZombie = STAGE_ONE_ZOMBIE;

        ZombieSprite[0] = IDB_MONSTER_ZOMBIE1;
        ZombieSprite[1] = IDB_MONSTER_ZOMBIE2;
        ZombieSprite[2] = IDB_MONSTER_ZOMBIE3;
        ZombieSprite[3] = IDB_MONSTER_ZOMBIE4;
        ZombieSprite[4] = IDB_MONSTER_ZOMBIE5;
        ZombieSprite[5] = IDB_MONSTER_ZOMBIE6;

        void* raw_memory = operator new[](RoundZombie * sizeof(Zombie));
        mGameObject[3] = static_cast<Zombie*>(raw_memory);
        for (int i = 0; i < 3; ++i)
        {
            new(&mGameObject[3][i]) Zombie(ZombieSprite);

            // STAGE_ONE_OBJECT_KIND 의 값을 2에서 6으로 바꾼 후,
            // &mGameObject[static_cast<int>(OBJECT_TYPE{ OBJECT_TYPE::ZOMBIE })][i] == &mGameObject[3][i]
            //  에 값을 넣었을때 게임이 꺼짐
        }
    }
        break;
    case 2:
        break;
    case 3:
        break;
    }
        // destruct in inverse order    
        /*for (int i = 6 - 1; i >= 0; --i) {
            mGameObject[i].~GameObject();
        }
        operator delete[](raw_memory);*/
}


void GFramework::CreateItem()
{
    int CakeSprite[6];
    CakeSprite[0] = IDB_ITEM_CAKE;
    CakeSprite[1] = IDB_ITEM_CAKE;
    CakeSprite[2] = IDB_ITEM_CAKE;
    CakeSprite[3] = IDB_ITEM_CAKE;
    CakeSprite[4] = IDB_ITEM_CAKE;
    CakeSprite[5] = IDB_ITEM_CAKE;

    void* raw_memory = operator new[](3 * sizeof(Cake));
    mGameObject[1] = static_cast<Cake*>(raw_memory);
    for (int i = 0; i < 3; ++i)
    {
        new(&mGameObject[1][i]) Cake(CakeSprite);
    }
}




bool MouseCollisionCheck(int Mx, int My ,int left, int top, int right, int bottom)
{
    if (left < Mx &&  Mx<right &&    top < My && My < bottom)
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
            if (User.GetPosition().y + FRAME_SPEED < GetSystemMetrics(SM_CYSCREEN) -200 - User.GetWinSizeY())
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
            User.GetPosition().x+User.GetWinSizeX() - 10, User.GetPosition().y+ User.GetWinSizeY() - 10 };
        ClipCursor(&rectView);

        User.SetRect(User.GetPosition().x, User.GetPosition().y, User.GetPosition().x + AIMSIZEX, User.GetPosition().y + AIMSIZEY);
        break;


    case WM_MOUSEMOVE:
    {
        AimPosition = { LOWORD(lParam) ,HIWORD(lParam) };
        InvalidateRect(hWnd, NULL, TRUE); // UI핸들을 보냄.
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

            for (int j = 0; j < STAGE_FIXED_OBJECT_KIND + round; ++j)
            {
                for (int i = 0; i < ICount[j]; i++) {
                    auto GameObject = gFramework.GetGameObject();
                    if (MouseCollisionCheck(User.GetPosition().x + LOWORD(lParam), User.GetPosition().y + HIWORD(lParam)
                        , GameObject[j][i].GetPosition().x, GameObject[j][i].GetPosition().y,
                        GameObject[j][i].GetPosition().x + GameObject[j][i].GetWidth(),
                        GameObject[j][i].GetPosition().y + GameObject[j][i].GetHeight()))
                    {
                        switch (gFramework.GetGameObject()[j][i].GetType())
                        {
                        case CAKE:
                            User.SetHP(User.GetHP() + 10);
                            break;

                        case MEGAZINE:
                            User.SetBullet(User.GetBullet() + 2);
                            break;

                        case SCOPE:
                            User.SetPosition(User.GetPosition().x - 5 , User.GetPosition().y - 5);
                            User.SetWinSizeX(User.GetWinSizeX() + 10);   User.SetWinSizeY(User.GetWinSizeY() + 10);
                            SetWindowPos(hWnd, NULL, User.GetPosition().x, User.GetPosition().y, User.GetWinSizeX(), User.GetWinSizeY(), NULL);

                            rectView = { User.GetPosition().x + 10, User.GetPosition().y + 40,
                                User.GetPosition().x + User.GetWinSizeX() - 10, User.GetPosition().y + User.GetWinSizeY() - 10 };
                            ClipCursor(&rectView);

                            User.SetRect(User.GetPosition().x, User.GetPosition().y, User.GetPosition().x + AIMSIZEX, User.GetPosition().y + AIMSIZEY);
                            break;


                        case ZOMBIE:
                            gFramework.GetGameObject()[j][i].SetHP(gFramework.GetGameObject()[j][i].GetHP() - 1);
                            if (gFramework.GetGameObject()[j][i].GetHP() <= 0)
                            {
                                // 사망 처리
                            }
                            break;

                        case BEE:
                            gFramework.GetGameObject()[j][i].SetHP(gFramework.GetGameObject()[j][i].GetHP() - 1);
                            if (gFramework.GetGameObject()[j][i].GetHP() <= 0)
                            {
                                // 사망 처리
                            }
                            break;

                        case BOSS:
                            gFramework.GetGameObject()[j][i].SetHP(gFramework.GetGameObject()[j][i].GetHP() - 1);
                            if (gFramework.GetGameObject()[j][i].GetHP() <= 0)
                            {
                                // 사망 처리
                            }
                            break;
                        }
                    }
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
            InvalidateRect(hwndUI, NULL, TRUE); // UI핸들을 보냄.
          

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

       



        // 플레이어와 게임오브젝트의 위치가 겹칠때 겹친 위치에 이미지가 출력됨 (미완성)
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
        SelectObject(memdc, AimBit);
        TransparentBlt(hDC, AimPosition.x - AimWidth / 4, AimPosition.y - AimHeight / 4, AimWidth / 2, AimHeight / 2, memdc, 0, 0, 134, 134, RGB(0, 255, 0));

        for (int j = 0; j < STAGE_FIXED_OBJECT_KIND + gFramework.GetRound() + 2; ++j)
        {
            for (int i = 0; i < ICount[j]; i++)
            {
                auto GameObject = gFramework.GetGameObject();

                if (GameObject[j] == nullptr)
                    continue;

                if (BoxCollisionCheck(User.GetPosition().x, User.GetPosition().y, User.GetPosition().x + User.GetWinSizeX(), User.GetPosition().y + User.GetWinSizeY(),
                    GameObject[j][i].GetPosition().x, GameObject[j][i].GetPosition().y,
                    GameObject[j][i].GetPosition().x + GameObject[j][i].GetWidth(),
                    GameObject[j][i].GetPosition().y + GameObject[j][i].GetHeight()))
                {
                    GameObject[j][i].DrawPlayerWindow(hDC, memdc, GameObject[j][i].GetBitMapAnim(), User.GetPosition().x, User.GetPosition().y,
                        User.GetPosition().x + User.GetWinSizeX(), User.GetPosition().y + User.GetWinSizeY());
                }
            }
        }



        DeleteDC(memdc);
        EndPaint(hWnd, &ps);
        return 0;
    }
    break;


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


        //Score Text Set, TextOut
        User.SetScorestr();
        TextOut(hDC, 0, 50, User.GetScoreStr().c_str(), static_cast<int>(User.GetScoreStr().size()));


        oldBit = (HBITMAP)SelectObject(memDC, mBitMap_BackGround);
        BitBlt(hDC, 0, 0, 1300, 450, memDC, 0, 0 , SRCCOPY);


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
        Rectangle(hDC, 310, 55, 310 +User.GetHP(), 105);
        
     
        
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
    HDC hDC, memdc, mem1dc;

    PAINTSTRUCT ps;
    HBRUSH hBrush, oldhBrush;

    static int frame = 0;

    switch (message)
    {

    case WM_CREATE:
    { //wndCount++;
        int Round = 0;
        gFramework.CreateMonster(Round);
        //gFramework.CreateItem();
        SetTimer(hWnd, 1, 100, NULL);
    }
    break;

    case WM_TIMER:
        switch (wParam)
        {
        case 1:
            // 몬스터 애니메이션 틱
            for (int j = 0; j < MAX_OBJECT_KIND; ++j)
            {
                if (gFramework.GetGameObject()[j] != nullptr)
                {
                    for (int i = 0; i < BITMAP_SPRITE_COUNT; ++i)
                    {
                        gFramework.GetGameObject()[j][i].SetmBitMapAnim((gFramework.GetGameObject()[j][i].GetBitMapAnim() + 1) % 5);
                    }
                }
            }
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
    case WM_PAINT:
    {
        hDC = BeginPaint(hWnd, &ps);
        memdc = CreateCompatibleDC(hDC);


        auto GameObject = gFramework.GetGameObject();
       
        int ICount[MAX_OBJECT_KIND] = { 3, 3, 2, 3, 3, 1 };
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

        for (int j = MAX_OBJECT_KIND-1; j > -1; --j)  // 전부 돎
        {
            for (int i = ICount[j]-1; i > -1; --i) // ICount까지
            {
                GameObject[j][i].DrawBitmap(hDC, memdc, GameObject[j][i].GetBitMapAnim());
            }
        }

        /*hBrush = CreateSolidBrush(RGB(255, 255, 255));
        oldhBrush = (HBRUSH)SelectObject(hDC, hBrush);
        Rectangle(hDC, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
        SelectObject(hDC, hBrush);
        DeleteObject(hBrush);*/

        DeleteDC(memdc);

        EndPaint(hWnd, &ps);
    }
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
