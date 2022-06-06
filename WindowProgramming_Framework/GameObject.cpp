#include "GameObject.h"

GameObject::GameObject(int *ResCode)
	: mHP{ 1 }, mPosition{ 0, 0 }, mWidth{ 0 }, mHeight{ 0 }
{
	BITMAP bmp;
	for (int i = 0; i < 6; ++i)
		mAppearanceBitmap[i] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(ResCode[i]));
	GetObject(mAppearanceBitmap[0], sizeof(BITMAP), &bmp);
	SetBitmapFrame(bmp.bmWidth, bmp.bmHeight);
	SetType(0);

}

void GameObject::PlaySound()
{
	Beep(1, 10);
}

void GameObject::DrawBitmap(HDC hdc, HDC memdc)
{
	HBITMAP oldBit;
	oldBit = (HBITMAP)SelectObject(memdc, mAppearanceBitmap[1]);
	BitBlt(hdc, mPosition.x, mPosition.y, mWidth, mHeight, memdc, 0, 0, SRCCOPY);
	SelectObject(memdc, oldBit);
	DeleteDC(memdc);
}

Cake::Cake(int *ResCode) : GameObject(ResCode)
{

}

Cake::~Cake()
{

}

void Cake::PlaySound()
{

}

void Cake::Anim(char Action)
{

}

void Cake::DrawBitmap(HDC hdc, HDC memdc)
{
	GameObject::DrawBitmap(hdc, memdc);
}


Megazine::Megazine() : GameObject(IDB_ITEM_BULLET)
{

}

Megazine::~Megazine()
{

}

void Megazine::PlaySound()
{

}

void Megazine::Anim(char Action)
{

}

void Megazine::DrawBitmap(HDC hdc, HDC memdc)
{
	GameObject::DrawBitmap(hdc, memdc);
}


Zombie::Zombie() : GameObject(IDB_MONSTER_ZOMBIE1)
{

}

Zombie::~Zombie()
{

}

void Zombie::PlaySound()
{

}

void Zombie::Anim(char Action)
{

}

void Zombie::DrawBitmap(HDC hdc, HDC memdc)
{
	GameObject::DrawBitmap(hdc, memdc);
}




Bat::~Bat()
{

}

Boss::~Boss()
{

}