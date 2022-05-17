#pragma once
#include "stdafx.h"
class GFramework
{
private:
	HWND mhMainWnd;
	HWND mhUIWnd;
	HWND mhPlayerWnd;
	HWND mhMainWnd_UI;
	HWND mhMainWnd_BackGround;
	HBITMAP m_hBitmap;
public:
	GFramework();
	~GFramework();
	void Init(HWND hwnd);
	void InitUI(HWND hwndUI);
	void InitBackGround(HWND hwndBG);
	void Reset();
	void Update(const float fTime);
	void Draw(HDC hdc);
	void KeyboardProcess(UINT iMessage, WPARAM wParam, LPARAM lParam);
	void MouseProcess(UINT iMessage, WPARAM wParam, LPARAM lParam);
};

