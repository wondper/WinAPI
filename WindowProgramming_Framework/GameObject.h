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
	virtual ~GameObject();

	virtual void PlaySound();
	virtual void Anim(char Type);
};

