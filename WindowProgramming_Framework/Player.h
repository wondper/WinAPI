#pragma once
#include "stdafx.h"

constexpr int FRAME_SPEED = 20;
constexpr int WINSIZE_WIDEX = 400;
constexpr int WINSIZE_WIDHY = 400;
constexpr int AIMSIZEX = 40;
constexpr int AIMSIZEY = 40;

class Player
{
private:
	POINT mPosition;

	int mHP;
	int mWinFrameSpeed ;

	int mWinSizeX = 200;
	int mWinSizeY = 200;

	int mBullet;
	int mScore;

	int mWeapon;

	//HDC mPlayerMemDC;
	//HBITMAP mAimBitmap; // 윈도우창 조준구 이미지 비트맵

	RECT mAimRect{0, 0, 0, 0};


	//bool Triger = false;
	//int TrigerFrame = 0; // 발사 애니매이션 프레임 갯수입니다.

	bool mIsGameOver = false;

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


	int GetWinSizeX() const { return mWinSizeX; }
	void SetWinSizeX(int WinSizeX) { mWinSizeX = WinSizeX; }

	int GetWinSizeY() const { return mWinSizeY; }
	void SetWinSizeY(int WinSizeY) { mWinSizeY = WinSizeY; }


	int GetBullet() const { return mBullet; }
	void SetBullet(int bullet) { mBullet = bullet; }

	int GetScore() const { return mScore; }
	void SetScore(int score) { mScore = score; }

	int GetWeapon() const { return mWeapon; }
	void SetWeapon(int weapon) { mWeapon = weapon; }

	//const RECT& GetRect() const { return mAimRect; }
	void SetRect(int left, int top, int right, int bottom) { mAimRect.left = left; mAimRect.top = top; mAimRect.right = right; mAimRect.bottom = bottom; }

	void SetGameOver() { mIsGameOver = true; }


	const std::wstring GetBullerStr() const { return mBulletStr; }
	void SetBulletstr();

	const std::wstring GetScoreStr() const { return mScoreStr; }
	void SetScorestr();
};

