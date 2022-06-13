#include "GameObject.h"


GameObject::GameObject(int* ResCode)
	: mType(-1), mHP{ 3 }, mPosition{ 0, 0 }, mWidth{ 0 }, mHeight{ 0 },
	mBitMapAnim{ 0 }, mCoolTime{ 15 }, mState(0)
{
	for (int i = 0; i < 6; ++i)
		mAppearanceBitmap[i] = NULL;
	random_device rd;
	mt19937 mersenne(rd());

	BITMAP bmp;
	SetBitmap(ResCode);
	auto bitmap = GetBitmap();
	GetObject(bitmap[0], sizeof(BITMAP), &bmp);
	SetBitmapFrame(bmp.bmWidth, bmp.bmHeight);

	uniform_int_distribution<> rand_X(0, GetSystemMetrics(SM_CXSCREEN) - mWidth);
	mPosition.x = rand_X(mersenne);

	uniform_int_distribution<> rand_Y(0, GetSystemMetrics(SM_CYSCREEN) - 300 - mHeight);
	mPosition.y = rand_Y(mersenne);

}

void GameObject::PlaySound()
{
	Beep(1, 10);
}

void GameObject::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState)
{
	HBITMAP oldBit;
	oldBit = (HBITMAP)SelectObject(memdc, mAppearanceBitmap[mBitMapAnim]);

	switch (mState)
	{
	case MONSTER_CREATE:
		TransparentBlt(hdc, mPosition.x, mPosition.y, mWidth, mHeight, memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
		break;
	case MONSTER_ATTACK:
		TransparentBlt(hdc, mPosition.x, mPosition.y, mWidth, mHeight, memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
		break;
	case MONSTER_DEATH:
		TransparentBlt(hdc, mPosition.x, mPosition.y, mWidth, mHeight, memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
		break;
	}

	SelectObject(memdc, oldBit);
}

void GameObject::DrawPlayerWindow(HDC hdc, HDC memdc, int mBitMapAnim, int PLeft, int PTop, int PRight, int PBottom, char mState)
{
	HBITMAP oldBit;
	oldBit = (HBITMAP)SelectObject(memdc, mAppearanceBitmap[mBitMapAnim]);

	switch (mState)
	{
	case MONSTER_CREATE:
		TransparentBlt(hdc, mPosition.x - PLeft, mPosition.y - PTop, mWidth, mHeight, memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
		break;
	case MONSTER_ATTACK:
		TransparentBlt(hdc, mPosition.x - PLeft, mPosition.y - PTop, mWidth, mHeight, memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
		break;
	case MONSTER_DEATH:
		TransparentBlt(hdc, mPosition.x - PLeft, mPosition.y - PTop, mWidth, mHeight, memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
		break;
	case OBJECT_NOT_DRAW:
		TransparentBlt(hdc, mPosition.x - PLeft, mPosition.y - PTop, mWidth, mHeight, memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
		break;
	}
	SelectObject(memdc, oldBit);
}

void GameObject::SetBitmap(int* ResCode)
{
	for (int i = 0; i < 6; ++i)
		mAppearanceBitmap[i] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(ResCode[i]));
}

Cake::Cake(int* ResCode) : GameObject(ResCode)
{
	SetType(CAKE);
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

void Cake::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim, mState);
}

Megazine::Megazine(int* ResCode) : GameObject(ResCode)
{
	SetType(MEGAZINE);
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

void Megazine::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim, mState);
}


Scope::Scope(int* ResCode) : GameObject(ResCode)
{
	SetType(SCOPE);
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

void Scope::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim, mState);
}


Zombie::Zombie(int* ResCode) : GameObject(ResCode)
{
	SetType(ZOMBIE);
	SetHP(5);
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

void Zombie::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim, mState);
}


Bee::Bee(int* ResCode) : GameObject(ResCode)
{
	SetType(BEE);
	SetHP(3);
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

void Bee::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim, mState);
}


Boss::Boss(int* ResCode) : GameObject(ResCode)
{
	SetType(BOSS);
	SetHP(10);
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

void Boss::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim, mState);
}

