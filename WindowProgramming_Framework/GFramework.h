#pragma once
#include "stdafx.h"
#include "Resource.h"
#define stage 3

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
	// 0 ����
	// 1 ����
	// 2 ����

	int Stats = 0;
	// 0 ��� ����
	// 1 �ǰ� ����
	// 2 ��� ����


	HBITMAP sprite[6];
	HBITMAP sprite_mask[6];
	HDC memDC= NULL;

};
Monster monster[stage][10]; // ���������� ���� ������ �迭
static int m_count[stage];// ���������� �� ��
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
	BackGround
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

	HWND mhMonsterWnd;

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
};

extern GFramework gFramework;

LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM); // �ϴ� UI �����츦 �����ϴ� ������ ���ν��� �Դϴ�
LRESULT CALLBACK UIWndProc(HWND, UINT, WPARAM, LPARAM); // ������ �����츦 �����ϴ� ������ ���ν��� �Դϴ�


//Callback func

LRESULT CALLBACK BackGroundWndProc(HWND, UINT, WPARAM, LPARAM); // ������ �����츦 �����ϴ� ������ ���ν��� �Դϴ�