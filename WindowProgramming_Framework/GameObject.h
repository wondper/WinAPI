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
	int mBitMapAnim; // �ִϸ��̼��� ���� ��Ʈ�� ���� ���ڰ�
public:
	GameObject(int ResCode);
	virtual ~GameObject(){};

	virtual void PlaySound();
	virtual void Anim(char Action) = 0; // Type�� ���� �ٸ� �ִϸ��̼� ����.
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
	Cake();
	virtual ~Cake();
	virtual void PlaySound();
	virtual void Anim(char Action);
	virtual void DrawBitmap(HDC hdc, HDC memdc);

};
//
//class Megazine : public GameObject
//{
//private:
//public:
//	Megazine();
//	virtual ~Megazine();
//};
//
//class Zombie : public GameObject
//{
//private:
//public:
//	Zombie();
//	virtual	~Zombie();
//};
//
//class Bat : public GameObject
//{
//private:
//public:
//	Bat();
//	virtual ~Bat();
//};
//
//class Boss : public GameObject
//{
//private:
//public:
//	Boss();
//	virtual ~Boss();
//};