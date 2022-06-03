#pragma once
#include "stdafx.h"

constexpr int FRAME_SPEED = 20;
constexpr int WINSIZEX = 200;
constexpr int WINSIZEY = 200;
constexpr int WINSIZE_WIDEX = 400;
constexpr int WINSIZE_WIDHY = 400;

class Player
{
private:
	POINT mPosition;

	int mHP;
	int mWinFrameSpeed ;

	int mBullet;
	int mScore;

	int mWeapon;

	HDC mPlayerMemDC;
	HBITMAP mPlayerAimBitmap;

	std::wstring mBulletStr;
	std::wstring mScoreStr;
public:
	Player();
	virtual ~Player();

	POINT GetPosition() const { return mPosition; }
	void SetPosition(const LONG x, const LONG y) { mPosition.x = x; mPosition.y = y; }
	void SetPositionX(const LONG x) { mPosition.x = x; }
	void SetPositionY(const LONG y) { mPosition.y = y; }

	int GetHP() const { return mHP; }
	void SetHP(int hp) { mHP = hp; }

	void DecreaseBulletCount() { --mBullet; }

	int GetBullet() const { return mBullet; }
	void SetBullet(int bullet) { mBullet = bullet; }

	int GetScore() const { return mScore; }
	void SetScore(int score) { mScore = score; }

	int GetWeapon() const { return mWeapon; }
	void SetWeapon(int weapon) { mWeapon = weapon; }

	const std::wstring GetBullerStr() const { return mBulletStr; }
	void SetBulletstr();

	const std::wstring GetScoreStr() const { return mScoreStr; }
	void SetScorestr();
};

