#include "GameObject.h"

GameObject::GameObject()
	: mHP{ 1 }, mPosition{0, 0}
{

}

void GameObject::PlaySound()
{
	Beep(1, 10);
}