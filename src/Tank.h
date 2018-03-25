#pragma once
#include "Template.h"
class Tank :
	public Template
{
public:
	Tank();
	Tank(int posX, int posY, int dir, int life, int score);
	~Tank();
	void setLife(const int &life);
	const int &getLife() const;
	void setScore(const int &score);
	const int &getScore() const;
private:
	int life_;
	int score_;
};

