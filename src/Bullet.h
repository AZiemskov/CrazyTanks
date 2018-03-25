#pragma once
#include "Template.h"
class Bullet :
	public Template
{
public:
	Bullet();
	Bullet(int posX, int posY, int dir);
	~Bullet();
};

