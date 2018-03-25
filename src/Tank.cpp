#include "stdafx.h"
#include "Tank.h"


Tank::Tank()
{
}

Tank::Tank(int posX, int posY, int dir, int life, int score):Template(posX, posY, dir) {
	life_ = life;
	score_ = score;
}


Tank::~Tank() = default;

void Tank::setLife(const int & life)
{
	life_ = life;
}

const int & Tank::getLife() const
{
	return life_;
}

void Tank::setScore(const int & score)
{
	score_ = score;
}

const int & Tank::getScore() const
{
	return score_;
}
