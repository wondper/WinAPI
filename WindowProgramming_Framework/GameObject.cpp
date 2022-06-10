#include "GameObject.h"


GameObject::GameObject(int* ResCode)
	: mHP{ 3 }, mPosition{ 0, 0 }, mWidth{ 0 }, mHeight{ 0 }, mBitMapAnim{ 0 }
{
		random_device rd;
		mt19937 mersenne(rd());
		
	BITMAP bmp;
	for (int i = 0; i < 6; ++i)
		mAppearanceBitmap[i] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(ResCode[i]));

	GetObject(mAppearanceBitmap[0], sizeof(BITMAP), &bmp);
	SetBitmapFrame(bmp.bmWidth, bmp.bmHeight);
	SetType(0);

	uniform_int_distribution<> rand_X(0, GetSystemMetrics(SM_CXSCREEN) - mWidth);
	mPosition.x = rand_X(mersenne);

	uniform_int_distribution<> rand_Y(0, GetSystemMetrics(SM_CYSCREEN)- 300 - mHeight);
	mPosition.y = rand_Y(mersenne);

}

void GameObject::PlaySound()
{
	Beep(1, 10);
}

void GameObject::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim)
{
	HBITMAP oldBit;
	oldBit = (HBITMAP)SelectObject(memdc, mAppearanceBitmap[mBitMapAnim]); 
	TransparentBlt(hdc, mPosition.x, mPosition.y, mWidth, mHeight, memdc, 0, 0, mWidth, mHeight, RGB(0,255,0));
	SelectObject(memdc, oldBit);
}

void GameObject::DrawPlayerWindow(HDC hdc, HDC memdc, int mBitMapAnim, int PLeft, int PTop, int PRight, int PBottom)
{
	HBITMAP oldBit;
	oldBit = (HBITMAP)SelectObject(memdc, mAppearanceBitmap[mBitMapAnim]);
	TransparentBlt(hdc, mPosition.x - PLeft, mPosition.y - PTop, mWidth, mHeight, memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
	SelectObject(memdc, oldBit);
}



Cake::Cake(int* ResCode) : GameObject(ResCode) 
{
	
}

Cake::~Cake()
{

}

void Cake::PlaySound()
{

}

void Cake::Anim(int Action)
{

}

void Cake::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim);
}

Megazine::Megazine(int* ResCode) : GameObject(ResCode)
{

}

Megazine::~Megazine()
{

}

void Megazine::PlaySound()
{

}

void Megazine::Anim(int Action)
{

}

void Megazine::DrawBitmap(HDC hdc, HDC memdc,int mBitMapAnim)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim);
}


Scope::Scope(int* ResCode) : GameObject(ResCode)
{

}

Scope::~Scope()
{

}

void Scope::PlaySound()
{

}

void Scope::Anim(int Action)
{

}

void Scope::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim);
}



Zombie::Zombie(int* ResCode) : GameObject(ResCode)
{

}

Zombie::~Zombie()
{

}

void Zombie::PlaySound()
{

}

void Zombie::Anim(int Action)
{

}

void Zombie::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim);
}

Bat::Bat(int* ResCode) : GameObject(ResCode)
{

}

Bat::~Bat()
{

}

void Bat::PlaySound()
{

}

void Bat::Anim(int Action)
{

}

void Bat::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim);
}


Boss::Boss(int* ResCode) : GameObject(ResCode)
{

}

Boss::~Boss()
{

}

void Boss::PlaySound()
{

}

void Boss::Anim(int Action)
{

}

void Boss::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim);
}

