#pragma once
#include <vector>
#include "Block.h"
class Wall
{
public:
	Wall(std::vector<Block> wall);
	~Wall();
	const int &getLength() const;
	void destroyBlock(const int i);
	Block operator[](const int i);
private:
	std::vector<Block> wall_;
};

