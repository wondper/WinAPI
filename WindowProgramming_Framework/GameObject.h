#pragma once
#include "stdafx.h"

class GameObject
{
private:
	int mHP;
	POINT mPosition;
	HBITMAP mAppearanceBitmap;
public:
	GameObject();
	virtual ~GameObject() = 0;

	virtual void PlaySound();
	virtual void Anim(char Type) = 0; // Type에 따라 다른 애니메이션 설정.
};

