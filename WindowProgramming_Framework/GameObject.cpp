#include "GameObject.h"


GameObject::GameObject(int *ResCode)
	: mHP{ 3 }, mPosition{ 0, 0 }, mWidth{ 0 }, mHeight{ 0 }, mBitMapAnim{0}
{
		random_device rd;
		mt19937 mersenne(rd());
		
		BITMAP bmp;
		SetBitmap(ResCode);
		auto bitmap = GetBitmap();
		GetObject(bitmap[0], sizeof(BITMAP), &bmp);
		SetBitmapFrame(bmp.bmWidth, bmp.bmHeight);

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
	TransparentBlt(hdc, 0, 0,100, 100, memdc, 0, 0, 100, 100, RGB(0, 255, 0));
	SelectObject(memdc, oldBit);
	DeleteDC(memdc);
}

void GameObject::SetBitmap(int* ResCode)
{
	for(int i=0;i<6;++i)
		mAppearanceBitmap[i] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(ResCode[i]));
}




Cake::Cake(int *ResCode) : GameObject(ResCode)
{
	SetType(0);
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

void Cake::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim);
}

Megazine::Megazine(int* ResCode) : GameObject(ResCode)
{
	SetType(1);
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

void Megazine::DrawBitmap(HDC hdc, HDC memdc,int mBitMapAnim)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim);
}


Scope::Scope(int* ResCode) : GameObject(ResCode)
{
	SetType(2);
}

Scope::~Scope()
{

}

void Scope::PlaySound()
{

}

void Scope::Anim(char Action)
{

}

void Scope::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim);
}



Zombie::Zombie(int* ResCode) : GameObject(ResCode)
{
	SetType(3);
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

void Zombie::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim);
}

Bee::Bee(int* ResCode) : GameObject(ResCode)
{
	SetType(4);
}

Bee::~Bee()
{

}

void Bee::PlaySound()
{

}

void Bee::Anim(char Action)
{

}

void Bee::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim);
}


Boss::Boss(int* ResCode) : GameObject(ResCode)
{
	SetType(5);
}

Boss::~Boss()
{

}

void Boss::PlaySound()
{

}

void Boss::Anim(char Action)
{

}

void Boss::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim);
}

