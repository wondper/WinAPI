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
	//�ν��Ͻ� �ڵ� ����
	HINSTANCE mhInstance;
	//.������ �ڵ� ����
	// ������ Ŭ���� ����
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

LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM); // �ϴ� UI �����츦 �����ϴ� ������ ���ν��� �Դϴ�
LRESULT CALLBACK UIWndProc(HWND, UINT, WPARAM, LPARAM); // ������ �����츦 �����ϴ� ������ ���ν��� �Դϴ�
//LRESULT CALLBACK MonsterWndProc(HWND, UINT, WPARAM, LPARAM); // ������ �����츦 �����ϴ� ������ ���ν��� �Դϴ�


//Callback func

LRESULT CALLBACK BackGroundWndProc(HWND, UINT, WPARAM, LPARAM); // ������ �����츦 �����ϴ� ������ ���ν��� �Դϴ�