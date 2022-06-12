#pragma once
#include "stdafx.h"
#include "resource.h"

enum class OBJECT_TYPE {CAKE, MAGAZINE, SCOPE, ZOMBIE, BAT, BOSS , END};

extern HINSTANCE g_hInst;

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
	GameObject(int ResCode[6]);
	virtual ~GameObject(){};

	virtual void PlaySound();
	virtual void Anim(char Action) {}; // Type에 따라 다른 애니메이션 설정.
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim);
	virtual void DrawPlayerWindow(HDC hdc, HDC memdc, int mBitMapAnim, int PLeft, int PRight, int PTop, int PBottom);
	
	int GetHP() const { return mHP; }
	void SetHP(int hp) { mHP = hp; }

	int GetType() const { return mType; }
	void SetType(char type) { mType = type; }

	int GetState() const { return mState; }
	 void SetState(char State) { mState = State; }


	int GetBitMapAnim() const { return mBitMapAnim; }
	void SetmBitMapAnim(int BitMapAnim) { mBitMapAnim = BitMapAnim; }

	int GetWidth() const { return mWidth; }
	int GetHeight() const { return mHeight; }
	void SetBitmapFrame(int width, int height) { mWidth = width; mHeight = height; }

	int GetCoolTime()  const{ return mCoolTime; }
	void SetCoolTime(int CoolTime) { mCoolTime = CoolTime; }


	POINT GetPosition() const { return mPosition; }
	void SetPosition(const POINT& Pos) { mPosition = Pos; }

	void SetBitmap(int* ResCode);

	HBITMAP* GetBitmap() { return mAppearanceBitmap; }
};

class Cake : public GameObject
{
private:

public:
	Cake(int* ResCode);
	virtual ~Cake();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim);

};

//
class Megazine : public GameObject
{
private:
public:
	Megazine(int* ResCode);
	virtual ~Megazine();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim);
};

class Scope : public GameObject
{
private:
public:
	Scope(int* ResCode);
	virtual ~Scope();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim);
};


class Zombie : public GameObject
{
private:
public:
	Zombie(int* ResCode);
	virtual ~Zombie();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim);
};

class Bee : public GameObject
{
private:
public:
	Bee(int* ResCode);
	virtual ~Bee();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim);
};

class Boss : public GameObject
{
private:
public:
	Boss(int* ResCode);
	virtual ~Boss();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim);
};