#pragma once
//#include "Resource.h"
#include "stdafx.h"
#include "GFramework.h"
#include "Resource.h"

#define MAX_LOADSTRING 100

//For console
#ifdef _DEBUG
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") 
#endif
#endif
// ���� ����:

constexpr int RectSide = 20;
constexpr int MAXBoard = 25;

WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.
HINSTANCE g_hInst;                                // ���� �ν��Ͻ��Դϴ�.

LPCTSTR lpszClass = L"Window Class Name";
LPCTSTR lpszWindowName = L"Window Program";
static GFramework gFramework;

HWND hwnd;
HWND hwndUI;
HWND hwndBG;

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

