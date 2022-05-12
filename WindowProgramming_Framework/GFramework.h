#pragma once
#include "stdafx.h"
class GFramework
{
private:
	HWND m_hwnd;
	HWND m_hwnd_UI;
	HWND m_hwnd_BackGround;
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

