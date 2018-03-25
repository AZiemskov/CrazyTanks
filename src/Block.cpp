#include "stdafx.h"
#include "Block.h"


Block::Block(int posX, int posY)
{
	posX_ = posX;
	posY_=posY;
}


Block::~Block() = default;

void Block::setPosX(const int & posX)
{
	posX_ = posX;
}

const int & Block::getPosX() const
{
	return posX_;
}

void Block::setPosY(const int & posY)
{
	posY_ = posY;
}

const int & Block::getPosY() const
{
	return posY_;
}
