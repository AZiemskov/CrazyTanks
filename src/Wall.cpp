#include "stdafx.h"
#include "Wall.h"


Wall::Wall(std::vector<Block> wall)
{
	wall_ = wall;
}


Wall::~Wall() = default;

const int & Wall::getLength() const
{
	return wall_.size();
}

void Wall::destroyBlock(const int i)
{
	wall_.erase(wall_.begin()+i);
}


Block Wall::operator[](const int i)
{
	for (int j = 0; j < getLength(); j++) {
		if (j == i) {
			return wall_[j];
		}
	}
}
