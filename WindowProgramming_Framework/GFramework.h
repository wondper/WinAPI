#pragma once
#include "stdafx.h"
#include "Resource.h"
#define stage 3

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
	HBITMAP Player_Aiming;

	TCHAR str_Bullet[10];
	TCHAR str_Score[10];



	bool Triger = false;
	bool gameOver = false;


};
static Player User;

struct Monster
{
	bool create = false;

	int X = rand() % 3000;
	int Y = 40;

	int Win_SizeX = 200;
	int Win_SizeY = 400;

	int Hp = 3;

	int skin = 0;
	// 0 좀비
	// 1 박쥐
	// 2 숙주

	int Stats = 0;
	// 0 대기 상태
	// 1 피격 상태
	// 2 사망 상태


	HBITMAP sprite[6];
	HBITMAP sprite_mask[6];
	HDC memDC= NULL;

};
Monster monster[stage][10]; // 스테이지별 적을 저장할 배열
static int m_count[stage];// 스테이지별 적 수
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
	BackGround
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

	HWND mhMonsterWnd;

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
};

extern GFramework gFramework;

LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM); // 하단 UI 윈도우를 관리하는 윈도우 프로시저 입니다
LRESULT CALLBACK UIWndProc(HWND, UINT, WPARAM, LPARAM); // 조준점 윈도우를 관리하는 윈도우 프로시저 입니다


//Callback func

LRESULT CALLBACK BackGroundWndProc(HWND, UINT, WPARAM, LPARAM); // 조준점 윈도우를 관리하는 윈도우 프로시저 입니다