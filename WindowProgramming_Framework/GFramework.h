#pragma once
#include "stdafx.h"
#include "Resource.h"
#include "Player.h"
#include "GameObject.h"
#include "Sound.h"



static HBITMAP BG_MAP;

static HWND hwndMain;
static HWND hwndUI;
static HWND hwndBG;

extern HINSTANCE g_hInst;

static Player User;

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
	// 윈도우 클래스 변수
	WNDCLASSEX mwcxMain;
	WNDCLASSEX mwcxUI;
	WNDCLASSEX mwcxBackGround;

	WNDCLASSEX mwcxMonster;

	HBITMAP m_hBitmap;

	Cake mCake[6];
	Megazine mMegazine[6];
	Scope mScope[6];
	Zombie mZombie[6];
	Bee mBee[6];
	Boss mBoss[6];

	int mRound = 0;

	Sound mSound[SOUND_NUM];

public:
	GFramework();
	~GFramework();

	void InitWCX(WINDOW wnd);

	void RegisterWnd();

	void ShowBGWnd(int nCmdShow);
	void ShowMainWnd(int nCmdShow);
	void ShowUIWnd(int nCmdShow);

	void ShowWnd(int nCmdShow);

	void Init();

	void Reset();
	void Update(const float fTime);
	void Draw(HDC hdc);
	void KeyboardProcess(UINT iMessage, WPARAM wParam, LPARAM lParam);
	void MouseProcess(UINT iMessage, WPARAM wParam, LPARAM lParam);
	void SwitchScene(int SceneNum);

	void CreateObject();

	int GetRound() const { return mRound; }
	void SetRound(int round) { mRound = round; }

	Cake* GetCake() { return mCake; }
	Megazine* GetMegazine() { return mMegazine; }
	Scope* GetScope() { return mScope; }
	Zombie* GetZombie() { return mZombie; }
	Bee* GetBee() { return mBee; }
	Boss* GetBoss() { return mBoss; }
	
	Sound* GetSound() { return mSound; }
};

extern GFramework gFramework;

LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM); // 하단 UI 윈도우를 관리하는 윈도우 프로시저 입니다
LRESULT CALLBACK UIWndProc(HWND, UINT, WPARAM, LPARAM); // 조준점 윈도우를 관리하는 윈도우 프로시저 입니다
//LRESULT CALLBACK MonsterWndProc(HWND, UINT, WPARAM, LPARAM); // 조준점 윈도우를 관리하는 윈도우 프로시저 입니다


//Callback func

LRESULT CALLBACK BackGroundWndProc(HWND, UINT, WPARAM, LPARAM); // 조준점 윈도우를 관리하는 윈도우 프로시저 입니다