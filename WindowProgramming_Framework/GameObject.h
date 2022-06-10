#pragma once
#include "stdafx.h"
#include "resource.h"

enum class OBJECT_TYPE {CAKE, MAGAZINE, SCOPE, ZOMBIE, BAT, BOSS , END};
enum class OBJECT_ACTION {CREATE, ATTACK, BOSS_SKIL ,DEAD };

extern HINSTANCE g_hInst;

class GameObject
{
private:
	int mType = -1;
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
	virtual void Anim(int Action) {}; // Type에 따라 다른 애니메이션 설정.
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim);
	virtual void DrawPlayerWindow(HDC hdc, HDC memdc, int mBitMapAnim, int PLeft, int PRight, int PTop, int PBottom);
	
	
	int GetHP() const { return mHP; }
	void SetHP(int hp) { mHP = hp; }


	int GetBitMapAnim() const { return mBitMapAnim; }
	void SetmBitMapAnim(int BitMapAnim) { mBitMapAnim = BitMapAnim; }

	void SetType(int type) { mType = type; }
	
	int GetWidth() const { return mWidth; }
	int GetHeight() const { return mHeight; }
	void SetBitmapFrame(int width, int height) { mWidth = width; mHeight = height; }

	int GetCoolTime()  const{ return mCoolTime; }
	void SetCoolTime(int CoolTime) { mCoolTime = CoolTime; }


	POINT GetPosition() const { return mPosition; }
	void SetPosition(const POINT& Pos) { mPosition = Pos; }


};

class Cake : public GameObject
{
private:

public:
	Cake(int* ResCode);
	virtual ~Cake();
	virtual void PlaySound();
	virtual void Anim(int Action);
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
	virtual void Anim(int Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim);
};

class Scope : public GameObject
{
private:
public:
	Scope(int* ResCode);
	virtual ~Scope();
	virtual void PlaySound();
	virtual void Anim(int Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim);
};


class Zombie : public GameObject
{
private:
public:
	Zombie(int* ResCode);
	virtual ~Zombie();
	virtual void PlaySound();
	virtual void Anim(int Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim);
};

class Bat : public GameObject
{
private:
public:
	Bat(int* ResCode);
	virtual ~Bat();
	virtual void PlaySound();
	virtual void Anim(int Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim);
};

class Boss : public GameObject
{
private:
public:
	Boss(int* ResCode);
	virtual ~Boss();
	virtual void PlaySound();
	virtual void Anim(int Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc, int mBitMapAnim);
};