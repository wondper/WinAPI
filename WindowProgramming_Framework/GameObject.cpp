#include "GameObject.h"


GameObject::GameObject()
	: mType(-1), mHP{ 3 }, mPosition{ 0, 0 }, mWidth{ 0 }, mHeight{ 0 },
	mBitMapAnim{ 0 }, mCoolTime{ 15 }, mState(0)
{
	for (int i = 0; i < 6; ++i)
		mAppearanceBitmap[i] = NULL;
}

GameObject::GameObject(int ResCode[6])
	: mType(-1), mHP{ 3 }, mPosition{ 0, 0 }, mWidth{ 0 }, mHeight{ 0 },
	mBitMapAnim{ 0 }, mCoolTime{ 15 }, mState(0)
{
	for (int i = 0; i < 6; ++i)
		mAppearanceBitmap[i] = NULL;
	random_device rd;
	mt19937 mersenne(rd());

	BITMAP bmp;
	
	auto bitmap = GetBitmap();
	GetObject(bitmap[0], sizeof(BITMAP), &bmp);
	SetBitmapFrame(bmp.bmWidth, bmp.bmHeight);

	uniform_int_distribution<> rand_X(0, GetSystemMetrics(SM_CXSCREEN) - mWidth);
	mPosition.x = rand_X(mersenne);

	uniform_int_distribution<> rand_Y(0, GetSystemMetrics(SM_CYSCREEN) - 300 - mHeight);
	mPosition.y = rand_Y(mersenne);

}

void GameObject::Initialize()
{
	mType = -1;
	mHP = 3;
	mPosition.x = 0, mPosition.y = 0;
	mWidth = 0;
	mHeight = 0;
	mBitMapAnim = 0;
	mCoolTime = 15;
	mState = 0;
	for (int i = 0; i < 6; ++i)
		mAppearanceBitmap[i] = NULL;

	random_device rd;
	mt19937 mersenne(rd());

	BITMAP bmp;

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
	case OBJECT_CREATE: // 오브젝트 생성시
		TransparentBlt(hdc, mPosition.x, mPosition.y , mWidth, mHeight, memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
		break;
	case MONSTER_ATTACK:// 몬스터가 공격시
		if (mBitMapAnim < 3)
			TransparentBlt(hdc, mPosition.x - (50 * mBitMapAnim), mPosition.y - (50 * mBitMapAnim),
				mWidth + (30 * mBitMapAnim), mHeight + (30 * mBitMapAnim), memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
		else
			TransparentBlt(hdc, mPosition.x - (50 * (6 - mBitMapAnim)), mPosition.y - (50 * (6 - mBitMapAnim)),
				mWidth + (30 * (6 - mBitMapAnim)), mHeight + (30 * (6 - mBitMapAnim)), memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
		break;

	case MONSTER_HIT:// 몬스터가 공격을 받았을시 깜빡깜빡
		if (mBitMapAnim % 2 == 1)
			TransparentBlt(hdc, mPosition.x , mPosition.y, mWidth, mHeight, memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
		break;
	case MONSTER_DEATH:// 몬스터가 사망시
		TransparentBlt(hdc, mPosition.x , mPosition.y+ (100 * mBitMapAnim), mWidth, mHeight, memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
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
	case OBJECT_CREATE: // 오브젝트 생성시
		TransparentBlt(hdc, mPosition.x - PLeft, mPosition.y - PTop, mWidth, mHeight, memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
		break;
	case MONSTER_ATTACK:// 몬스터가 공격시
		if (mBitMapAnim < 3)
			TransparentBlt(hdc, mPosition.x - PLeft - (50 * mBitMapAnim), mPosition.y - PTop - (50 * mBitMapAnim),
				mWidth + (30 * mBitMapAnim), mHeight + (30 * mBitMapAnim), memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
		else
			TransparentBlt(hdc, mPosition.x - PLeft - (50 * (6 - mBitMapAnim)), mPosition.y - PTop - (50 * (6 - mBitMapAnim)),
				mWidth + (30 * (6 - mBitMapAnim)), mHeight + (30 * (6 - mBitMapAnim)), memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
		break;

	case MONSTER_HIT:// 몬스터가 공격을 받았을시 깜빡깜빡
		if(mBitMapAnim%2  == 1)
		TransparentBlt(hdc, mPosition.x - PLeft, mPosition.y - PTop, mWidth, mHeight, memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
		break;
	case MONSTER_DEATH:// 몬스터가 사망시
		TransparentBlt(hdc, mPosition.x - PLeft, mPosition.y - PTop + (100 * mBitMapAnim), mWidth, mHeight, memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
		break;

	default:
		TransparentBlt(hdc, mPosition.x - PLeft, mPosition.y - PTop, mWidth, mHeight, memdc, 0, 0, mWidth, mHeight, RGB(0, 255, 0));
		break;
	
	}
	SelectObject(memdc, oldBit);
}

void GameObject::SetBitmap(int ResCode[6])
{
	for (int i = 0; i < 6; ++i)
		mAppearanceBitmap[i] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(ResCode[i]));
}

Cake::Cake() 
{
	
}

Cake::Cake(int ResCode[6]) : GameObject(ResCode)
{
	SetType(CAKE);
	for (int i = 0; i < 6; ++i)
		GetBitmap()[i] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(ResCode[i]));
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

void Cake::Initialize()
{
	SetType(CAKE);
	SetHP(3);
	
	SetBitMapAnim(0);
	SetCoolTime(15);
	SetState(OBJECT_CREATE);

	HBITMAP BitSprite[6];
	for (int i = 0; i < 6; ++i)
	{
		BitSprite[i] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ITEM_CAKE));
		SetBitmapIndex(i, BitSprite[i]);
	}

	random_device rd;
	mt19937 mersenne(rd());

	BITMAP bmp;

	auto bitmap = GetBitmap();
	GetObject(bitmap[0], sizeof(BITMAP), &bmp);
	SetBitmapFrame(bmp.bmWidth, bmp.bmHeight);

	uniform_int_distribution<> rand_X(0, GetSystemMetrics(SM_CXSCREEN) - GetWidth());
	uniform_int_distribution<> rand_Y(0, GetSystemMetrics(SM_CYSCREEN) - 300 - GetHeight());

	SetPosition(rand_X(mersenne), rand_Y(mersenne));

}

void Cake::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim, mState);
}


Megazine::Megazine()
{

}

Megazine::Megazine(int ResCode[6]) : GameObject(ResCode)
{
	SetType(MEGAZINE);
	for (int i = 0; i < 6; ++i)
		GetBitmap()[i] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(ResCode[i]));
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

void Megazine::Initialize()
{
	SetType(MEGAZINE);
	SetHP(3);
	SetBitMapAnim(0);
	SetCoolTime(15);
	SetState(OBJECT_CREATE);

	HBITMAP BitSprite[6];
	for (int i = 0; i < 6; ++i)
	{
		BitSprite[i] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ITEM_MAGAZINE));
		SetBitmapIndex(i, BitSprite[i]);
	}

	random_device rd;
	mt19937 mersenne(rd());

	BITMAP bmp;

	auto bitmap = GetBitmap();
	GetObject(bitmap[0], sizeof(BITMAP), &bmp);
	SetBitmapFrame(bmp.bmWidth, bmp.bmHeight);

	uniform_int_distribution<> rand_X(0, GetSystemMetrics(SM_CXSCREEN) - GetWidth());
	uniform_int_distribution<> rand_Y(0, GetSystemMetrics(SM_CYSCREEN) - 300 - GetHeight());

	SetPosition(rand_X(mersenne), rand_Y(mersenne));

}

void Megazine::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim, mState);
}






Scope::Scope()
{

}

Scope::Scope(int ResCode[6]) : GameObject(ResCode)
{
	SetType(SCOPE);
	for (int i = 0; i < 6; ++i)
		GetBitmap()[i] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(ResCode[i]));
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

void Scope::Initialize()
{
	SetType(SCOPE);
	SetHP(3);

	SetBitMapAnim(0);
	SetCoolTime(15);
	SetState(OBJECT_CREATE);

	HBITMAP BitSprite[6];
	for (int i = 0; i < 6; ++i)
	{
		BitSprite[i] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ITEM_SCOPE));
		SetBitmapIndex(i, BitSprite[i]);
	}

	random_device rd;
	mt19937 mersenne(rd());

	BITMAP bmp;

	auto bitmap = GetBitmap();
	GetObject(bitmap[0], sizeof(BITMAP), &bmp);
	SetBitmapFrame(bmp.bmWidth, bmp.bmHeight);

	uniform_int_distribution<> rand_X(0, GetSystemMetrics(SM_CXSCREEN) - GetWidth());
	uniform_int_distribution<> rand_Y(0, GetSystemMetrics(SM_CYSCREEN) - 300 - GetHeight());

	SetPosition(rand_X(mersenne), rand_Y(mersenne));

}

void Scope::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim, mState);
}


Zombie::Zombie()
{

}

Zombie::Zombie(int ResCode[6]) : GameObject(ResCode)
{
	SetType(ZOMBIE);
	for (int i = 0; i < 6; ++i)
		GetBitmap()[i] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(ResCode[i]));
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

void Zombie::Initialize()
{
	SetType(ZOMBIE);
	SetHP(4);

	SetBitMapAnim(0);
	SetCoolTime(10);
	SetState(OBJECT_CREATE);

	HBITMAP BitSprite[6];
	BitSprite[0] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_ZOMBIE1));
	BitSprite[1] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_ZOMBIE2));
	BitSprite[2] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_ZOMBIE3));
	BitSprite[3] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_ZOMBIE4));
	BitSprite[4] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_ZOMBIE5));
	BitSprite[5] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_ZOMBIE6));

	for (int i = 0; i < 6; ++i)
	{
		SetBitmapIndex(i, BitSprite[i]);
	}

	random_device rd;
	mt19937 mersenne(rd());

	BITMAP bmp;

	auto bitmap = GetBitmap();
	GetObject(bitmap[0], sizeof(BITMAP), &bmp);
	SetBitmapFrame(bmp.bmWidth, bmp.bmHeight);

	uniform_int_distribution<> rand_X(0, GetSystemMetrics(SM_CXSCREEN) - GetWidth());
	uniform_int_distribution<> rand_Y(0, GetSystemMetrics(SM_CYSCREEN) - 300 - GetHeight());

	SetPosition(rand_X(mersenne), rand_Y(mersenne));

}

void Zombie::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim, mState);
}


Bee::Bee()
{

}

Bee::Bee(int ResCode[6]) : GameObject(ResCode)
{
	SetType(BEE);
	for (int i = 0; i < 6; ++i)
		GetBitmap()[i] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(ResCode[i]));
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

void Bee::Initialize()
{
	SetType(ZOMBIE);
	SetHP(2);

	SetBitMapAnim(0);
	SetCoolTime(8);
	SetState(OBJECT_CREATE);

	HBITMAP BitSprite[6];
	BitSprite[0] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_BEE1));
	BitSprite[1] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_BEE2));
	BitSprite[2] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_BEE3));
	BitSprite[3] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_BEE4));
	BitSprite[4] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_BEE5));
	BitSprite[5] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_BEE6));

	for (int i = 0; i < 6; ++i)
	{
		SetBitmapIndex(i, BitSprite[i]);
	}

	random_device rd;
	mt19937 mersenne(rd());

	BITMAP bmp;

	auto bitmap = GetBitmap();
	GetObject(bitmap[0], sizeof(BITMAP), &bmp);
	SetBitmapFrame(bmp.bmWidth, bmp.bmHeight);

	uniform_int_distribution<> rand_X(0, GetSystemMetrics(SM_CXSCREEN) - GetWidth());
	uniform_int_distribution<> rand_Y(0, GetSystemMetrics(SM_CYSCREEN) - 300 - GetHeight());

	SetPosition(rand_X(mersenne), rand_Y(mersenne));

}


void Bee::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim, mState);
}


Boss::Boss()
{

}

Boss::Boss(int ResCode[6]) : GameObject(ResCode)
{
	SetType(BOSS);
	for (int i = 0; i < 6; ++i)
		GetBitmap()[i] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(ResCode[i]));
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

void Boss::Initialize()
{
	SetType(ZOMBIE);
	SetHP(BOSSHP);

	SetBitMapAnim(0);
	SetCoolTime(20);
	SetState(OBJECT_CREATE);

	HBITMAP BitSprite[6];
	BitSprite[0] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_BOSS1));
	BitSprite[1] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_BOSS2));
	BitSprite[2] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_BOSS3));
	BitSprite[3] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_BOSS4));
	BitSprite[4] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_BOSS5));
	BitSprite[5] = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_MONSTER_BOSS6));

	for (int i = 0; i < 6; ++i)
	{
		SetBitmapIndex(i, BitSprite[i]);
	}

	random_device rd;
	mt19937 mersenne(rd());

	BITMAP bmp;

	auto bitmap = GetBitmap();
	GetObject(bitmap[0], sizeof(BITMAP), &bmp);
	SetBitmapFrame(bmp.bmWidth, bmp.bmHeight);

	uniform_int_distribution<> rand_X(0, GetSystemMetrics(SM_CXSCREEN) - GetWidth());
	uniform_int_distribution<> rand_Y(0, GetSystemMetrics(SM_CYSCREEN) - 300 - GetHeight());

	SetPosition(rand_X(mersenne), rand_Y(mersenne));

}


void Boss::DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState)
{
	GameObject::DrawBitmap(hdc, memdc, mBitMapAnim, mState);
}
