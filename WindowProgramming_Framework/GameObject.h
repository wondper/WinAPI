#pragma once
#include "stdafx.h"
#include "resource.h"

extern HINSTANCE g_hInst;

#define BOSSHP 10

class GameObject
{
private:
	char mType = -1;
	char mState; // 몬스터 상태
	int mHP;

	int mWidth;
	int mHeight;

	POINT mPosition;
	HBITMAP mAppearanceBitmap[6];
	int mBitMapAnim; // 애니메이션을 위한 비트맵 선택 인자값


	int mCoolTime; // 공격 쿨타임
public:
	GameObject();
	GameObject(int ResCode[6]);
	virtual ~GameObject() {};

	virtual void PlaySound();
	virtual void Anim(char Action) {}; // Type에 따라 다른 애니메이션 설정.
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState);
	virtual void DrawPlayerWindow(HDC hdc, HDC memdc, int mBitMapAnim, int PLeft, int PRight, int PTop, int PBottom, char mState);

	virtual void Initialize();

	void SetBitmapIndex(int i, HBITMAP bit) { mAppearanceBitmap[i] = bit; }

	int GetHP() const { return mHP; }
	void SetHP(int hp) { mHP = hp; }

	int GetType() const { return mType; }
	void SetType(char type) { mType = type; }

	int GetState() const { return mState; }
	void SetState(char State) { mState = State; }


	int GetBitMapAnim() const { return mBitMapAnim; }
	void SetBitMapAnim(int BitMapAnim) { mBitMapAnim = BitMapAnim; }

	int GetWidth() const { return mWidth; }
	int GetHeight() const { return mHeight; }
	void SetBitmapFrame(int width, int height) { mWidth = width; mHeight = height; }

	int GetCoolTime()  const { return mCoolTime; }
	void SetCoolTime(int CoolTime) { mCoolTime = CoolTime; }


	POINT GetPosition() { return mPosition; }
	void SetPosition(int PosX, int PosY) { mPosition.x = PosX; mPosition.y = PosY; }

	void SetBitmap(int ResCode[6]);
	HBITMAP* GetBitmap() { return mAppearanceBitmap; }
};

class Cake : public GameObject
{
private:

public:
	Cake();
	Cake(int ResCode[6]);
	virtual ~Cake();
	virtual void Initialize();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState);

};


class Megazine : public GameObject
{
private:

public:
	Megazine();
	Megazine(int ResCode[6]);
	virtual ~Megazine();
	virtual void Initialize();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState);
};

class Scope : public GameObject
{
private:
public:
	Scope();
	Scope(int ResCode[6]);
	virtual ~Scope();
	virtual void Initialize();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState);
};


class Zombie : public GameObject
{
private:
public:
	Zombie();
	Zombie(int ResCode[6]);
	virtual ~Zombie();
	virtual void Initialize();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState);
};

class Bee : public GameObject
{
private:
public:
	Bee();
	Bee(int ResCode[6]);
	virtual ~Bee();
	virtual void Initialize();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState);
};

class Boss : public GameObject
{
private:
public:
	Boss();
	Boss(int ResCode[6]);
	virtual ~Boss();
	virtual void Initialize();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim, char mState);
};