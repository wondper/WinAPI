#pragma once
#include "stdafx.h"
#include "resource.h"



enum class OBJECT_TYPE {CAKE, MAGAZINE, ZOMBIE, BAT, BOSS};

extern HINSTANCE g_hInst;

class GameObject
{
private:
	char mType = -1;
	int mHP;

	int mWidth;
	int mHeight;

	POINT mPosition;
	HBITMAP mAppearanceBitmap[6];
	int mBitMapAnim; // 애니메이션을 위한 비트맵 선택 인자값
public:
	GameObject(int ResCode[6]);
	virtual ~GameObject(){};

	virtual void PlaySound();
	virtual void Anim(char Action) = 0; // Type에 따라 다른 애니메이션 설정.
	virtual void DrawBitmap(HDC hdc, HDC memdc);


	int GetHP() const { return mHP; }
	void SetHP(int hp) { mHP = hp; }


	int GetBitMapAnim() const { return mBitMapAnim; }
	void SetmBitMapAnim(int BitMapAnim) { mBitMapAnim = BitMapAnim; }

	void SetType(char type) { mType = type; }
	
	void SetBitmapFrame(int width, int height) { mWidth = width; mHeight = height; }

	void SetPosition(const POINT& Pos) { mPosition = Pos; }


};

class Cake : public GameObject
{
private:

public:
	Cake(int* ResCode);
	virtual ~Cake();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc);

};

//
class Megazine : public GameObject
{
private:
public:
	Megazine();
	virtual ~Megazine();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc);
};

class Zombie : public GameObject
{
private:
public:
	Zombie();
	virtual	~Zombie();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc);
};

class Bat : public GameObject
{
private:
public:
	Bat();
	virtual ~Bat();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc);
};

class Boss : public GameObject
{
private:
public:
	Boss();
	virtual ~Boss();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc);
};