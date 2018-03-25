#pragma once
#include "Template.h"
class Enemy :
	public Template
{
public:
	Enemy();
	Enemy(int posX, int posY, int dir);
	~Enemy();
};

