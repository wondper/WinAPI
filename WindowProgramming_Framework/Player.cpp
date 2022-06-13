#include "Player.h"

Player::Player()
	: mHP{ 500 },  mWinFrameSpeed{20}, mBullet{ 10 }, mScore{ 0 },
	mWeapon{ 1 }, mBulletStr{ 0 }, mScoreStr{ 0 }, mPosition{ POINT{0,0} }
{
}

Player::~Player()
{

}

void Player::SetBulletstr()
{
	mBulletStr.assign(L"HandGun Bullet: " + std::to_wstring(mBullet));
}

void Player::SetScorestr()
{
	mScoreStr.assign(L"Score: " + std::to_wstring(mScore));
}