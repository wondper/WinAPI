#pragma once
#include "stdafx.h"
#include "Resource.h"
#define stage 3 // 스테이지 개수 입니다
#define MAX_m 10 // 최대 몬스터 생성 갯수입니다.

static HBITMAP BG_MAP;

extern HINSTANCE g_hInst;

struct Player
{
	POINT P = { 0,0 }; // Plaeyr의 x와 y좌표

	int HP = 1000;
	int Win_SizeX = 200;
	int Win_SizeY = 200;
	int WinFrameSpeed = 20;

	int Bullet = 8;
	int Score = 1000;

	int Weapon = 1;

	HDC Player_memDC;

	RECT Player_AimintZone;
	HBITMAP Player_Aiming;
	int Aming_sizeX = 40;
	int Aming_sizeY = 40;

	TCHAR str_Bullet[10];
	TCHAR str_Score[10];

	bool Triger = false;
	int TrigerFrame = 0; // 발사 애니매이션 프레임 갯수입니다.

	bool gameOver = false;


};
static Player User;

struct Monster
{
	bool create = false;

	POINT P = { rand()%1200,rand()%200}; // Monster의 x와 y좌표

	int Win_SizeX = 200;
	int Win_SizeY = 400;

	int Hp = 3;

	bool Dead = true;

	int skin = 0;
	// 0 좀비
	// 1 박쥐
	// 2 숙주

	int Stats = 0;
	// 0 대기 상태
	// 1 피격 상태
	// 2 사망 상태
	int ActionFrame = 0;


	HBITMAP sprite[6];
	HBITMAP sprite_mask[6];
	HDC memDC= NULL;
};

static Monster monster[stage][MAX_m]; // 스테이지별 적을 저장할 배열
static int m_count[stage] = {3,5,3};// 스테이지별 적 수
static int stage_count=0;


struct Item
{
	int x= 0;
	int y = 0;

	int width;
	int height;


	int type = 0;
	// 0 : 케이크 <-체력 회복
	// 1 : 탄환 <-탄창 충천
	// 2 : 스코프 <- 윈도우 크기 증가?

	HBITMAP sprite[6];
	HDC memDC = NULL;
};


enum class WINDOW {
	Main = 0,
	UI,
	BackGround,
	Monster,
};

class GFramework
{
private:
	//인스턴스 핸들 변수
	HINSTANCE mhInstance;
	//.윈도우 핸들 변수
	HWND mhMainWnd;
	HWND mhUIWnd;
	HWND mhBackGroundWnd;

	HWND mhMonsterWnd[MAX_m];

	// 윈도우 클래스 변수
	WNDCLASSEX mwcxMain;
	WNDCLASSEX mwcxUI;
	WNDCLASSEX mwcxBackGround;

	WNDCLASSEX mwcxMonster;


	HBITMAP m_hBitmap;
public:
	GFramework();
	~GFramework();

	void InitWCX(WINDOW wnd);

	void RegisterWnd();
	void ShowWnd(HINSTANCE hInstance, int nCmdShow);

	void Init(HWND hwnd, HINSTANCE gInst);
	void InitUI(HWND hwndUI);
	void InitBackGround(HWND hwndBG);
	void Reset();
	void Update(const float fTime);
	void Draw(HDC hdc);
	void KeyboardProcess(UINT iMessage, WPARAM wParam, LPARAM lParam);
	void MouseProcess(UINT iMessage, WPARAM wParam, LPARAM lParam);

	HWND GetUIhwnd() const { return mhUIWnd; }
	HWND GetMainhwnd() const { return mhMainWnd; }
	HWND GetBackgroundWnd() const { return mhBackGroundWnd; }
	
	HWND GetMonsterWnd() const { return mhMonsterWnd[0]; }
	// 하나만 선언해야하는 ??
};

extern GFramework gFramework;

LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM); // 하단 UI 윈도우를 관리하는 윈도우 프로시저 입니다
LRESULT CALLBACK UIWndProc(HWND, UINT, WPARAM, LPARAM); // 조준점 윈도우를 관리하는 윈도우 프로시저 입니다
LRESULT CALLBACK MonsterWndProc(HWND, UINT, WPARAM, LPARAM); // 조준점 윈도우를 관리하는 윈도우 프로시저 입니다


//Callback func

LRESULT CALLBACK BackGroundWndProc(HWND, UINT, WPARAM, LPARAM); // 조준점 윈도우를 관리하는 윈도우 프로시저 입니다