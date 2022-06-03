#pragma once
#include "stdafx.h"
#include "Resource.h"
#include "Player.h"
#include "Monster.h"

static HBITMAP BG_MAP;

extern HINSTANCE g_hInst;



enum class WINDOW {
	Main = 0,
	UI,
	BackGround
};

static Player User;


class GFramework
{
private:
	//인스턴스 핸들 변수
	HINSTANCE mhInstance;
	//.윈도우 핸들 변수
	HWND mhMainWnd;
	HWND mhUIWnd;
	HWND mhBackGroundWnd;
	// 윈도우 클래스 변수
	WNDCLASSEX mwcxMain;
	WNDCLASSEX mwcxUI;
	WNDCLASSEX mwcxBackGround;

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