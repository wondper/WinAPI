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
// 전역 변수:

constexpr int RectSide = 20;
constexpr int MAXBoard = 25;

WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
HINSTANCE g_hInst;                                // 현재 인스턴스입니다.

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

