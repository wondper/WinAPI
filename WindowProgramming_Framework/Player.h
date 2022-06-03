#pragma once
#include "stdafx.h"
class Player
{
private:
	POINT mPosition;

	int mHP;
	int mWin_SizeX = 200;
	int mWin_SizeY = 200;
	int mWinFrameSpeed = 20;

	int mBullet = 8;
	int mScore = 1000;

	int mWeapon = 1;

	HDC mPlayer_memDC;
	HBITMAP mPlayer_Aiming;

	TCHAR mstr_Bullet[10];
	TCHAR mstr_Score[10];
public:
	Player() {}
	virtual ~Player();

	POINT GetPosition() const { return mPosition; }
	void SetPosition(const LONG x, const LONG y) { mPosition.x = x; mPosition.y = y; }

	int GetHP() const { return mHP; }
	void SetHP(int hp) { mHP = hp; }

	int GetBullet() const { return mBullet; }
	void SetBullet(int bullet) { mBullet = bullet; }

	int GetScore() const { return mScore; }
	void SetScore(int score) { mScore = score; }

	int GetWeapon() const { return mWeapon; }
	void SetWeapon(int weapon) { mWeapon = weapon; }

	void SetBulletstr();
	void SetScorestr();
};

