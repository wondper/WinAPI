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
	virtual void Anim(char Type) = 0; // Type�� ���� �ٸ� �ִϸ��̼� ����.
};

