#pragma once
#include "stdafx.h"
#include "Resource.h"
#define stage 3 // �������� ���� �Դϴ�
#define MAX_m 10 // �ִ� ���� ���� �����Դϴ�.

static HBITMAP BG_MAP;

extern HINSTANCE g_hInst;

struct Player
{
	POINT P = { 0,0 }; // Plaeyr�� x�� y��ǥ

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
	int TrigerFrame = 0; // �߻� �ִϸ��̼� ������ �����Դϴ�.

	bool gameOver = false;


};
static Player User;

struct Monster
{
	bool create = false;

	POINT P = { rand()%1200,rand()%200}; // Monster�� x�� y��ǥ

	int Win_SizeX = 200;
	int Win_SizeY = 400;

	int Hp = 3;

	bool Dead = true;

	int skin = 0;
	// 0 ����
	// 1 ����
	// 2 ����

	int Stats = 0;
	// 0 ��� ����
	// 1 �ǰ� ����
	// 2 ��� ����
	int ActionFrame = 0;


	HBITMAP sprite[6];
	HBITMAP sprite_mask[6];
	HDC memDC= NULL;
};

static Monster monster[stage][MAX_m]; // ���������� ���� ������ �迭
static int m_count[stage] = {3,5,3};// ���������� �� ��
static int stage_count=0;


struct Item
{
	int x= 0;
	int y = 0;

	int width;
	int height;


	int type = 0;
	// 0 : ����ũ <-ü�� ȸ��
	// 1 : źȯ <-źâ ��õ
	// 2 : ������ <- ������ ũ�� ����?

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
	//�ν��Ͻ� �ڵ� ����
	HINSTANCE mhInstance;
	//.������ �ڵ� ����
	HWND mhMainWnd;
	HWND mhUIWnd;
	HWND mhBackGroundWnd;

	HWND mhMonsterWnd[MAX_m];

	// ������ Ŭ���� ����
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
	// �ϳ��� �����ؾ��ϴ� ??
};

extern GFramework gFramework;

LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM); // �ϴ� UI �����츦 �����ϴ� ������ ���ν��� �Դϴ�
LRESULT CALLBACK UIWndProc(HWND, UINT, WPARAM, LPARAM); // ������ �����츦 �����ϴ� ������ ���ν��� �Դϴ�
LRESULT CALLBACK MonsterWndProc(HWND, UINT, WPARAM, LPARAM); // ������ �����츦 �����ϴ� ������ ���ν��� �Դϴ�


//Callback func

LRESULT CALLBACK BackGroundWndProc(HWND, UINT, WPARAM, LPARAM); // ������ �����츦 �����ϴ� ������ ���ν��� �Դϴ�