#pragma once
#include "stdafx.h"
#include "Resource.h"
#include "Player.h"
#include "GameObject.h"
#define stage 3 // �������� ���� �Դϴ�
#define MAX_m 10 // �ִ� ���� ���� �����Դϴ�.

#define STAGE_ONE_ZOMBIE 3 // �ִ� ���� ���� �����Դϴ�.

#define STAGE_TWO_ZOMBIE 3
#define STAGE_TWO_BEE 3

#define STAGE_THREE_ZOMBIE 6
#define STAGE_THREE_BEE 6

#define CAKE 0
#define MEGAZINE 1
#define SCOPE 2
#define ZOMBIE 3
#define BEE 4
#define BOSS 5

#define STAGE_TEST_ZOMBIE 3
#define STAGE_TEST_BEE 3
#define STAGE_TEST_BOSS 1


#define STAGE_FIXED_OBJECT_KIND 3
#define STAGE_ONE_ADDITIONAL_OBJECT_KIND 1
#define STAGE_TWO_ADDITIONAL_OBJECT_KIND 2
#define STAGE_THREE_ADDITIONAL_OBJECT_KIND 3

#define CAKE_COUNT 3
#define MEGAZINE_COUNT 3
#define SCOPE_COUNT 2

#define BITMAP_SPRITE_COUNT 6
#define MAX_OBJECT_KIND 6


#define MONSTER_CREATE 0
#define MONSTER_ATTACK 1
#define MONSTER_DEATH 2

#define MONSTER_NONE 10


static HBITMAP BG_MAP;

static HWND hwndMain;
static HWND hwndUI;
static HWND hwndBG;

extern HINSTANCE g_hInst;

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
	// ������ Ŭ���� ����
	WNDCLASSEX mwcxMain;
	WNDCLASSEX mwcxUI;
	WNDCLASSEX mwcxBackGround;

	WNDCLASSEX mwcxMonster;


	HBITMAP m_hBitmap;

	GameObject** mGameObject;

	int mRound = 0;

public:
	GFramework();
	~GFramework();

	void InitWCX(WINDOW wnd);
	void Init(HWND hwnd, HINSTANCE gInst);

	void RegisterWnd();
	void ShowWnd(HINSTANCE hInstance, int nCmdShow);

	void Reset();
	void Update(const float fTime);
	void Draw(HDC hdc);
	void KeyboardProcess(UINT iMessage, WPARAM wParam, LPARAM lParam);
	void MouseProcess(UINT iMessage, WPARAM wParam, LPARAM lParam);	
	void SwitchScene(int SceneNum);

	GameObject** GetGameObject() { return mGameObject; }

	void CreateMonster(int Round);
	void CreateItem();
		
	int GetRound() const { return mRound; }
	void SetRound(int round) { mRound = round; }
	//Create Item

	// Create Monster

	// 
};

extern GFramework gFramework;

LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM); // �ϴ� UI �����츦 �����ϴ� ������ ���ν��� �Դϴ�
LRESULT CALLBACK UIWndProc(HWND, UINT, WPARAM, LPARAM); // ������ �����츦 �����ϴ� ������ ���ν��� �Դϴ�
//LRESULT CALLBACK MonsterWndProc(HWND, UINT, WPARAM, LPARAM); // ������ �����츦 �����ϴ� ������ ���ν��� �Դϴ�


//Callback func

LRESULT CALLBACK BackGroundWndProc(HWND, UINT, WPARAM, LPARAM); // ������ �����츦 �����ϴ� ������ ���ν��� �Դϴ�