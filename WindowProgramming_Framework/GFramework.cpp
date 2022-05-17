#include "GFramework.h"
GFramework::GFramework()
{

}

GFramework::~GFramework()
{

}

void GFramework::Init(HWND hwnd)
{
	mhMainWnd = hwnd;
}

void GFramework::InitUI(HWND hwndUI)
{
	mhMainWnd_UI = hwndUI;
}

void GFramework::InitBackGround(HWND hwndBG)
{
	mhMainWnd_BackGround = hwndBG;
}

void GFramework::Update(const float fTime)
{

}

void GFramework::Reset()
{

}

void GFramework::Draw(HDC hdc)
{

}

void GFramework::KeyboardProcess(UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_KEYDOWN:
	{
		if (wParam == VK_ESCAPE)
		{
			SendMessage(mhMainWnd, WM_DESTROY, 0, 0);
			return;
		}
	}
	break;


	case WM_KEYUP:
	{

	}
	break;


	}
}

void GFramework::MouseProcess(UINT iMessage, WPARAM wParam, LPARAM lParam)
{

}

