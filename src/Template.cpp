#include "stdafx.h"
#include "Template.h"


Template::Template()
{
}

Template::Template(int posX, int posY, int dir)
{
	posX_ = posX;
	posY_ = posY;
	dir_ = dir;
}


Template::~Template() = default;

void Template::setPosX(const int & posX)
{
	posX_ = posX;
}

const int & Template::getPosX() const
{
	return posX_;
}

void Template::setPosY(const int & posY)
{
	posY_ = posY;
}

const int & Template::getPosY() const
{
	return posY_;
}

void Template::setDir(const int & dir)
{
	dir_ = dir;
}

const int & Template::getDir() const
{
	return dir_;
}
